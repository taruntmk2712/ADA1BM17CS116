#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int a[10],n,k,i,j;
	clock_t start,end;
	cout<<"Enter no. of elements:";
	cin>>n;
	cout<<"Enter elements:";
	for(int i =0;i<n;i++)
	cin>>a[i];
	cout<<"Enter the 'k'th position"<<endl;
	cin>>k;
	start = clock();
	for(i =0 ; i<k;i++)
	{
		for(j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					int temp = a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
	}
	end=clock();
	cout<<a[k-1]<<endl;
	float exe= float(end-start)/CLOCKS_PER_SEC;
	cout<<exe;
	
	return 0;
}
