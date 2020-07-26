#include<bits/stdc++.h>
using namespace std;
int setbitstopdown(int memo[],int n)
{
	if (n==1 || n==0)
	{
		memo[n]=n;
		return memo[n];
	}
	if (memo[n]!=0)
	{
		return memo[n];
	}
	int op1;
	if (n%2==0)
	{
		memo[n]=setbitstopdown(memo,n/2);
		return memo[n];
	}
	memo[n]=1+setbitstopdown(memo,n/2);
	return memo[n];
}
void setbitsbottomup(int memo[],int n)
{
	memo[0]=0;
	memo[1]=1;
	for (int i = 2; i <= n; ++i)
	{
		if (n%2==0)
	   {
		  memo[n]=setbitstopdown(memo,n/2);
	   }
	   else
	   {
	   	memo[n]=1+setbitstopdown(memo,n/2);
	   }
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int memo[1000]={0};
	// setbitstopdown(memo,n);
	setbitstopdown(memo,n);
	cout<<memo[n]<<endl;
	return 0;
}
