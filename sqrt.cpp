#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
int main()
{
	int n;
	float first=0.0,last,mid,mid_1;
	clock_t  start,end;
	cout<<"Enter the number:";
	cin>>n;
	last = n;
	start = clock();
	while(last>=first)
	{
		mid = (first+last)/2;
		if((mid*mid) == n)
		{
			cout<<"Square root:"<<mid<<endl;
			break;
		}
		else if((mid*mid) > n)
		{
			last = mid+1;
		}
		else if((mid*mid)<n)
		{
			mid_1 = mid;
			while((mid_1*mid_1)<n)
			{
				mid_1++;
				}
				first = floor(mid_1);
			cout<<"Floored sqrt:"<<first<<endl;	
			break;
		}
		
	}
	end = clock();
 	double t = double(end-start)/CLOCKS_PER_SEC;
	cout<<"Exection time:"<<t;
}
