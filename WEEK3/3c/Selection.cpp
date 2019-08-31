#include <iostream>
#include<ctime>
using namespace std;
int main()
{
	int a[10],n,k,mid1,count=0,count1=0;
	clock_t start,end;
	cout<<"Enter no. of elements:";
	cin>>n;
	cout<<"Enter elements:";
	for(int i =0;i<n;i++)
	cin>>a[i];
	start = clock();
	for(int i=0;i<n;i++)
	{
		mid1=i;
		for(int j = i+1;j<n;j++)
			{
				if(a[mid1]>a[j])
				{
					mid1 = j;
					count1++;
				}
			}
			int temp= a[mid1];
			a[mid1]=a[i];
			a[i]=temp;
			count++;
			
	}
	end=clock();
	cout<<"Count:"<<count*count1<<endl;
	float exe= float(end-start)/CLOCKS_PER_SEC;
	cout<<exe;
	
	return 0;
}
