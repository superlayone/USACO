/*
ID:superla1
PROB:milk3
LANG:C++
*/
//#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory.h>
#include <algorithm>

using namespace std;
ifstream fin ("milk3.in");
ofstream fout ("milk3.out");

long ans[50],p=-1;
long a,b,c;      //各桶上限 
bool found[50][50][50];     //搜索记录 

bool isIn(long C)
{
	bool in=false;
	for (long i=0;i<=p;i++)
	{
		if (ans[i]==C)
		{
			in=true;
			break;
		}
	}
	return in;
}

void DFS(long A,long B,long C)
{
	if (found[A][B][C]) return;
	found[A][B][C]=true;
	if (A==0)
	{
		if (!isIn(C))
		{
			ans[++p]=C;
		}
	}
	if (A<=b-B) DFS(0,B+A,C);             //A->B     
	else DFS(A-(b-B),b,C);
	if (A<=c-C) DFS(0,B,C+A);             //A->C
	else DFS(A-(c-C),B,c);
	if (B<=a-A) DFS(A+B,0,C);             //B->A     
	else DFS(a,B-(a-A),C);
	if (B<=c-C) DFS(A,0,C+B);             //B->C
	else DFS(A,B-(c-C),c);
	if (C<=a-A) DFS(A+C,B,0);             //C->A     
	else DFS(a,B,C-(a-A));
	if (C<=b-B) DFS(A,B+C,0);             //C->B
	else DFS(A,b,C-(b-B));
	return;
}

int main()
{
	memset (ans,0,sizeof(ans));
	memset (found,0,sizeof(found));
	fin >>a >>b >>c;
	DFS(0,0,c);
	sort(ans,ans+p+1);
	for (long i=0;i<=p;i++)     //输出
	{
		if (i!=0) fout <<' ';
		fout <<ans[i];
	}
	fout <<endl;
	system("pause");
	return 0;
}