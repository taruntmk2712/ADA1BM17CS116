#include<bits/stdc++.h>
using namespace std; 
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 
void knapSack(int W, int wt[], int val[], int n) 
{ 
int i, j; 
int K[n+1][W+1]; 
for (i = 0; i <= n; i++) 
{ 
	for (j = 0; j <= W; j++) 
	{ 
		if (i==0 || j==0) 
			K[i][j] = 0; 
		else if (wt[i-1] <= j) 
				K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]], K[i-1][j]); 
		else
				K[i][j] = K[i-1][j]; 
	} 
} 
  for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cout<<K[i][j]<<"\t";
        }
        cout<<"\n";
    }
int res = K[n][W];     
    cout<<"Maximum Profit: "<<res<<endl;
    j = W; 
	cout<<"Weights of items included: ";
    for (i = n; i > 0 && res > 0; i--)  
	{    
        if (res == K[i - 1][j])  
            continue;         
        else 
		{
            cout<<i<<"->"<<wt[i - 1]<<endl;
            res = res - val[i - 1]; 
            j= j- wt[i - 1]; 
        } 
    } 
} 
int main() 
{ 
	int val[10],wt[10],W,n;
	cout<<"Enter the no of items:";
	cin>>n;
	cout<<"\n";
	for(int i=0;i<n;i++){
		cout<<"Enter the weight"<<i+1<<":"<<endl;	
		cin>>wt[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the values"<<i+1<<":"<<endl;
		cin>>val[i];
	}
	cout<<"Max capacity: "<<endl;
	cin>>W;
	knapSack(W, wt, val, n); 
	return 0; 
} 
/*
OUTPUT:
Enter the no of items:4

Enter the weight1:
2
Enter the weight2:
1
Enter the weight3:
3
Enter the weight4:
2
Enter the values1:
12
Enter the values2:
10
Enter the values3:
20
Enter the values4:
15
Max capacity: 
5
0	0	  0	  0	  0	  0	
0	0	  12	12	12	12	
0	10	12	22	22	22	
0	10	12	22	30	32	
0	10	15	25	30	37	
Maximum Profit: 37
Weights of items included: 
4->2
2->1
1->2
*/
