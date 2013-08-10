/*
ID:superla1
PROB:hamming
LANG:C++
*/
//#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
ifstream fin ("hamming.in");
ofstream fout ("hamming.out");

int k,n,m,sum;
int ans[65];
bool check(int n)
{
	int i,x;
	for(i=1;i<=sum;i++)
	{
		x=n ^ ans[i];
		//fout<<"x="<<x<<endl;
		x = (x&0x55555555) + ((x>>1)&0x55555555); 
		x = (x&0x33333333) + ((x>>2)&0x33333333); 
		x = (x&0x0f0f0f0f) + ((x>>4)&0x0f0f0f0f); 
		x = (x&0x00ff00ff) + ((x>>8)&0x00ff00ff); 
		x = (x&0x0000ffff) + ((x>>16)&0x0000ffff); 
		if(x<k)
		{
			return false;
		}
	}
	return true;
}

void init()
{
	fin>>n>>m>>k;
	//fout<<n<<m<<k<<endl;
	sum=1;
	ans[1]=0;
}
void work()
{
	int i;
	//fout<<(1<<m)<<endl;
	for(i=1;i<=(1<<m);i++)
	{
		if(check(i))
		{
			//fout<<i<<endl;
			sum++;
			ans[sum]=i;
		}
		if(sum==n)
		{
			break;
		}
	}
}
void print()
{
	int i;
	for(i=1;i<=n;i++)
	{
		fout<<ans[i];
		if(i%10 !=0 && i<n)
		{
			fout<<" ";
		}
		else
		{
			fout<<endl;
		}
	}
	if(n%10!=0 && i<n)
	{
		fout<<endl;
	}
}
int main()
{
	init();
	work();
	print();
	return 0;
}