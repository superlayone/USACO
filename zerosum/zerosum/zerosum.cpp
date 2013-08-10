/*
ID:		superla1
PROG:	zerosum
LANG:	C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
char Line[18];
int N;
void DFS(int step,int sum,int last)
{
	if(step==N)
	{
		if(sum+last==0)
		{
			fout<<Line<<endl;
		}
		return;
	}
	Line[2*step-1]=' ';
	DFS(step+1,sum,last>0 ? last*10+step+1 : last*10-step-1);
	Line[2*step-1]='+';
	DFS(step+1,sum+last,step+1);
	Line[2*step-1]='-';
	DFS(step+1,sum+last,-step-1);
}
int main()
{
	fin>>N;
	for(int i=0;i<N;i++)
	{
		Line[i*2]=i+'1';
	}
	DFS(1,0,1);
	return 0;
}