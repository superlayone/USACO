/*
ID:superla1
PROB:runround
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <stack>

using namespace std;
stack<int> stk;
ifstream fin ("runround.in");
ofstream fout ("runround.out");
bool check(unsigned long n)
{
	int a[10]={0};
	int b[10]={0};
	int k=0;
	while(n!=0)
	{
		stk.push(n%10);
		k++;
		n=n/10;
	}
	for(int i=0;i<k;i++)
	{
		a[i]=stk.top();
		stk.pop();
	}
	int i=0,t=k;
	while(t--)
	{
		i+=a[i];
		i=i%k;
		b[a[i]]++;
	}
	 for (int i=0;i<10;i++)
	 {
        if (b[i]!=0 && b[i]!=1)
		{
			return false;
		}
	 }
	 return true;
}
int main()
{
	unsigned long n,i;
	fin>>n;
	i=n+1;
	while (true)
	{
		if(check(i)==true)
		{
			fout<<i<<endl;
			break;
		}
		i++;
	}
	return 0;
}