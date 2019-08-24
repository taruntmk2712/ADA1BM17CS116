#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int a[10],n,k,mid1;
	clock_t start,end;
	cout<<"Enter no. of elements:";
	cin>>n;
	cout<<"Enter elements:";
	for(int i =0;i<n;i++)
	cin>>a[i];
	cout<<"Enter the 'k'th position"<<endl;
	cin>>k;
	start = clock();
	for(int i=0;i<n;i++)
	{
		mid1=i;
		for(int j = i+1;j<n;j++)
			{
				if(a[mid1]>a[j])
				{
					mid1 = j;
				}
			}
			int temp= a[mid1];
			a[mid1]=a[i];
			a[i]=temp;
	}
	end=clock();
	cout<<"'k' Largest elements:"<<endl;
	for(int i=n-1;i>n-1-k;i--)
	cout<<a[i]<<endl;
	float exe= float(end-start)/CLOCKS_PER_SEC;
	cout<<exe;
	
	return 0;
}
