#include<bits/stdc++.h>
using namespace std;
int grid[4][4];
int N,SQN;
bool usedInRow(int row,int num){
    for(int col=0;col<N;col++){
        if(grid[row][col] == num)
            return true;
    }
    return false;
}
bool usedInColumn(int col,int num){
    for(int row=0;row<N;row++){
        if(grid[row][col] == num)
            return true;
    }
    return false;
}
bool usedInBox(int boxStartRow,int boxStartCol, int num){
    for(int row=0;row< SQN;row++){
        for(int col =0;col<SQN;col++){
            if(grid[row+boxStartRow][col+boxStartCol] == num){
                return true;
            }
        }
    }
    return false;
}
bool isSafe(int row,int col,int num){
    return(!usedInRow(row,num) && !usedInColumn(col,num) && !usedInBox(row-row%SQN,col-col%SQN,num));
}
bool findUnassignedLocation(int *row, int *col){
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            if(grid[i][j] == 0){
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false;
}
bool solveSuduko(){
    int row,col;
    if(!findUnassignedLocation(&row,&col)){
        return true;
    }
    for(int num=1;num<=N;num++){
        if(isSafe(row,col,num)){
            grid[row][col] = num;
            if(solveSuduko()){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}
int main(){
    cout<<"Enter Sudoku elements:";
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>grid[i][j];
        }
    }
    SQN = sqrt(N);
        cout<<"\nSudoku"<<endl;
         for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }   
    
    bool t = solveSuduko();
    cout<<endl;
    Solution:
    if(t){
     for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }   
    }
    else
    {
        cout<<"No Solution";
    }
    
}



/*
OUTPUT 1:
Enter Sudoku elements:4
1 0 3 0
4 0 2 0
3 0 1 0
2 0 4 0

Sudoku
1 0 3 0
4 0 2 0
3 0 1 0
2 0 4 0

Solution:
1 2 3 4
4 3 2 1
3 4 1 2
2 1 4 3

OUTPUT 2:
Enter Sudoku elements:4
1 0 3 0
2 0 4 0
3 0 1 0
1 0 3 0

Sudoku
1 0 3 0
2 0 4 0
3 0 1 0
1 0 3 0

Solution:
No Solution
*/
