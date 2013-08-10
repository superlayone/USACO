/*
ID:superla1
PROG:checker
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<memory.h>
using namespace std;

ifstream fin("checker.in");
ofstream fout("checker.out");

int N;
int tot=0;
int C[255];
int vis[3][255];

void search(int cur)
{
	int i,j;
	if(cur==N) 
	{
		tot++;
		if(tot<4)
		{	
			for(int n=0;n<N-1;n++)
			    fout<<C[n]<<" ";
			fout<<C[N-1]<<endl;
		}
 
	}
	else 
		for(i=0;i<N;i++)
		{
			if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+N])//���ö�ά����ֱ���ж��Ƿ��ǰ��Ļʺ��ͻ
			{
				C[cur]=i+1;
				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+N]=1;//�޸�ȫ�ֱ���
				search(cur+1);
				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+N]=0;//���ڴ��Ļ�����
			}
		}
}
 
 
int main()
{
	fin>>N;
	memset(C,0,14);
	search(0);
	fout<<tot<<endl;
	return 0;
}