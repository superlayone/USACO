/*
ID:superla1
PROB:numtri
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory.h>
#include <algorithm>

using namespace std;
ifstream fin ("numtri.in");
ofstream fout ("numtri.out");

long max(long a,long b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int num[1000][1000];
int main()
{
	int R=0;
	fin>>R;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<=i;j++)
		{
			fin>>num[i][j];
		}
	}
	for(int i=R-2;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
		{
			num[i][j]+=max(num[i+1][j],num[i+1][j+1]);
		}
	}
	fout<<num[0][0]<<endl;

	return 0;
}