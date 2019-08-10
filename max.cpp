#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int a[10], n, temp;
	cout<<"Enter the number of elements:";
	cin>>n;
	
	cout<<"Enter the elements:";
	for(int i=0;i<n;i++)
		cin>>a[i];
		
			for(int j=0;j<n;j++)
			{
				if(a[j]>a[j+1])
				{
				 temp = a[j];
				}
			}
		cout<<temp;
	return 0;
}
