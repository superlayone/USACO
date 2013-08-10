/*
ID:superla1
PROB:nocows
LANG:C++
*/
#include <fstream>
#include <iostream>
#include <memory>
using namespace std;
ifstream fin("nocows.in");
ofstream fout("nocows.out");
int N,K;
int Tables[102][203];
int SmallTrees[102][203];
int main()
{
	fin>>N>>K;
	int Symmetric;
	Tables[1][1]=1;
	for(int i=2;i<=K;i++)
	{
		for(int j=1;j<=N;j+=2)
		{
			for(int k=1;k<=j-1-k;k+=2)
			{
				if(k!=j-1-k)
				{
					Symmetric=2;
				}
				else
				{
					Symmetric=1;
				}
				Tables[i][j]+=Symmetric*(
					SmallTrees[i-2][k]*Tables[i-1][j-1-k]+
					Tables[i-1][k]*SmallTrees[i-2][j-1-k]+
					Tables[i-1][k]*Tables[i-1][j-1-k]
					);
				Tables[i][j]%=9901;
			}
		}
		for(int k=0;k<=N;k++)
		{
			SmallTrees[i-1][k]+=Tables[i-1][k]+SmallTrees[i-2][k]; 
            SmallTrees[i-1][k]%=9901; 
		}
	}
	fout<<Tables[K][N]<<endl;
	return 0;
}