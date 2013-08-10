/*
ID:superla1
PROG:	money
LANG:	C++
*/

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");
long long Ways[10001];
int Units[26];
int V,N;
void Solve()
{
	Ways[0]=1;
	for(int i=0;i<V;i++)
	{
		for(int j=0;j+Units[i]<=N;j++)
		{
			Ways[j+Units[i]]+=Ways[j];	
		}
	}
	fout<<Ways[N]<<endl;
}
int main()
{
	fin>>V>>N;
	for(int i=0;i<V;i++)
	{
		fin>>Units[i];
	}
	Solve();
	return 0;
}