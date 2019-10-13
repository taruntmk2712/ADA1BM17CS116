#include <bits/stdc++.h>
using namespace std;

void displaySubset(int subSet[], int size) {
        cout<<"{";
        for(int i = 0; i < size; i++) {
            cout << subSet[i] << ",";
        }
        cout<<"}";
        cout << endl;
}

void subsetSum(int set[], int subSet[], int n, int subSize, int total, int nodeCount ,int sum) 
{
   if( total == sum) 
   {
      displaySubset(subSet, subSize);     
      subsetSum(set,subSet,n,subSize-1,total-set[nodeCount],nodeCount+1,sum);     
      return;     
   }
   else 
   {
      for( int i = nodeCount; i < n; i++ ) 
      {     
         subSet[subSize] = set[i];
         subsetSum(set,subSet,n,subSize+1,total+set[i],i+1,sum);     
      }
   }
}

void findSubset(int set[], int size, int sum) 
{
   int *subSet = new int[size];     
   subsetSum(set, subSet, size, 0, 0, 0, sum);
   delete[] subSet;
}

int main() 
{ 
	int weights[30],target,size;
    cout<<"Enter no. of weights :";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter weight "<<i+1<<": ";
        cin>>weights[i];
    }
    cout<<"Enter the target sum :";
    cin>>target;
    cout<<"\nSubSets { }"<<endl;
    findSubset(weights, size, target);
    return 0; 
} 
/*
OUTPUT:
Enter no. of weights :5
Enter weight 1: 10
Enter weight 2: 5
Enter weight 3: 15
Enter weight 4: 7
Enter weight 5: 20
Enter the target sum :2 

SubSets { }


Enter no. of weights :5
Enter weight 1: 10
Enter weight 2: 7
Enter weight 3: 5
Enter weight 4: 15
Enter weight 5: 20
Enter the target sum :20

SubSets { }
{5,15,}
{20,}
*/
