/*
ID:superla1
PROB:sort3
LANG:C++
*/
//#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
ifstream fin ("sort3.in");
ofstream fout ("sort3.out");

int main()
{
	int n,x;
	int k=0;
	int count[4]={0},a[4]={0};
	int t[1001]={0};
	fin>>n;
	while (fin>>x) 
	{
          count[x]++;
          t[++k]=x;
    }
    for (int i=1;i<=count[1]+count[2];i++)
	{
        if (t[i]==3) 
		{
			a[3]++;
		}
        else if (t[i]==2&&i<=count[1]) 
		{
			a[1]++;
		}
        else if (t[i]==1&&i>count[1]) 
		{
			a[2]++;
		}
    }
    fout<<a[3]+(a[1]>a[2]?a[1]:a[2])<<endl;
	return 0;
}