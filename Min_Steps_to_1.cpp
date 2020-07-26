#include<bits/stdc++.h>
using namespace std;
int stepstopdown(int numb[],int n)
{
	if (n==1)
	{
		numb[n]=0;
		return numb[n];
	}
	if (numb[n]!=0)
	{
		return numb[n];
	}
		int op1=INT_MAX;
		int op2=INT_MAX;
		int op3=INT_MAX;
		if (n%2==0)
		{
			op1=1+stepstopdown(numb,n/2);
		}
		if (n%3==0)
		{
			op2=1+stepstopdown(numb,n/3);
		}
		op3=1+stepstopdown(numb,n-1);
		numb[n]=min(op1,min(op2,op3));
		return numb[n];
}
void stepsbottomup(int numb[],int n)
{
	numb[1]=0;
	for (int i = 2; i <= n; ++i)
	{
		int op1=INT_MAX;
		int op2=INT_MAX;
		int op3=INT_MAX;
		if (n%2==0)
		{
			op1=1+stepstopdown(numb,n/2);
		}
		if (n%3==0)
		{
			op2=1+stepstopdown(numb,n/3);
		}
		op3=1+stepstopdown(numb,n-1);
		numb[n]=min(op1,min(op2,op3));
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int numb[1000]={0};
	// stepstopdown(numb,n);
	stepsbottomup(numb,n);
	cout<<numb[n];
	return 0;
}
