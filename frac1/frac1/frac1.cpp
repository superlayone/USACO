/*
ID:superla1
PROB:frac1
LANG:C++
*/
//#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
ifstream fin ("frac1.in");
ofstream fout ("frac1.out");

int  index;

typedef struct node
{
	int x,y;
}node;
node valid[13000];

int gcd(int x,int y)
{
	return y==0 ? x : gcd(y,x%y);
}

int cmp(node a,node b)
{
	return (double)a.x /a.y < (double)b.x / b.y;
}

void process(int n)
{
	index=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			int a=j,b=i;
			if(gcd(a,b) == 1)
			{
				valid[index].x=a;
				valid[index].y=b;
				//fout<<valid[index].x<<" "<<valid[index].y<<endl;
				index++;
			}
		}
	}
}
int main()
{
	int n;
	fin>>n;
	process(n);

	sort(valid,valid+index,cmp);
	
	for(int i=0;i<index;i++)
	{
		fout<<valid[i].x<<"/"<<valid[i].y<<endl;
	}
	return 0;
}