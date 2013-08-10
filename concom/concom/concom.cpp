/*
ID:		superla1
PROG:	concom
LANG:	C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("concom.in");
ofstream fout("concom.out");
int Con[202][202];
bool Tag[202][202];
void DFS(int i,int j)
{
	Tag[i][j]=true;
	for (int k=1;k<=100;k++)
	 {
         Con[i][k]+=Con[j][k];
	 }

     for (int k=1;k<=100;k++)
	 {
         if(!Tag[i][k] && Con[i][k]>50)
		 {
				DFS(i,k);
		 }
	 }
     for (int k=1;k<=100;k++)
	 {
         if (Tag[j][k] && !Tag[i][k]) 
		 {
				DFS(j,k);
		 }
	 }
     for (int k=1;k<=100;k++)
	 {
		 if (Tag[k][i]&& !Tag[k][j])
		 {
				DFS(k,j);
		 }
	 }
}
int main()
{
	int N,a,b;
	fin>>N;
	for(int i=1;i<=N;i++)
	{
		fin>>a>>b;
		fin>>Con[a][b];
	}
	memset(Tag,false,sizeof(Tag));
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			if(!Tag[i][j] && Con[i][j]>50)
			{
				DFS(i,j);
			}
		}
	}
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			if(i!=j && Tag[i][j])
			{
				fout<<i<<" "<<j<<endl;
			}
		}
	}
	return 0;
}