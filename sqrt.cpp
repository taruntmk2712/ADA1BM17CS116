#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
int main()
{
	here:
	int n;
	int first=0,last,mid,sqrt1;
	char c;
	clock_t  start,end;
	cout<<"Enter the number:";
	cin>>n;
	last = n;
	start = clock();
	while(true)
	{
		while(last>=first)
		{
			mid = (first+last)/2;
			if((mid*mid) == n)
			{
				sqrt1 = mid;
				break;
			}
			else if((mid*mid) > n)
			{
				last = mid-1;
			}
			else if((mid*mid)<n)
			{
				first = mid+1;
				sqrt1=mid;
				
			}

		}
		cout<<"Square root:"<<sqrt1<<endl;
		cout<<"Do you want to continue?(y/n):";
			cin>>c;
		if(c=='y')
			goto here;
		else if(c=='n')
			break;
	}
	end = clock();
 	double t = double(end-start)/CLOCKS_PER_SEC;
	cout<<"Exection time:"<<t;
}
