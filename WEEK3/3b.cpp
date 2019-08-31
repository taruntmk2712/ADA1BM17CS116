#include<bits/stdc++.h>
using namespace std; 
  
void merge(int arr[], int low, int mid, int high) 
{ 
    int i, j, k; 
    int n1 = mid - low + 1; 
    int n2 =  high - mid; 
  

    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[low + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1+ j]; 
  
    i = 0; 
    j = 0;  
    k = low; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int mid = low+(high - low)/2; 
        mergeSort(arr, low, mid); 
        mergeSort(arr, mid+1, high); 
  
        merge(arr, low, mid, high); 
    } 
} 


int main()
{
	int arr[10],i,j,high,low,n;
	clock_t start,end;
	cout<<"Enter no of elements:";
	cin>>n;
	low=0;
	high=n-1;
	cout<<"Enter elements:";
	for(i =0;i<n;i++)
		cin>>arr[i];
	start = clock();
	mergeSort(arr, low, high);
	end = clock();
	for(i =0;i<n;i++)
		cout<<endl<<arr[i];
	float exe = float(end-start)/CLOCKS_PER_SEC;
	cout<<"\nExecution time:"<<exe;    
    return 0; 
}
