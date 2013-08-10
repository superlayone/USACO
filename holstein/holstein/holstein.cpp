/*
ID:superla1
PROB:holstein
LANG:C++
*/
//#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
ifstream fin ("holstein.in");
ofstream fout ("holstein.out");

const long MAXLONGINT=999999999;
 
long need[26];
long food[16][26];
long n,c;
long minc=MAXLONGINT,minstate=0;
 
void init()
{
     fin >>n;
     for (long i=0;i<n;i++)
         fin >>need[i];
     fin >>c;
     for (long i=0;i<c;i++)
         for (long j=0;j<n;j++)
             fin >>food[i][j];
     return;
}
 
bool record(long state)
{
     long t=0,tState=state,i=0;
	 long fed[26]={0};
     while (tState>0)
     {
           if (tState&1)
           {
              t++;
              for (long j=0;j<n;j++)
                  fed[j]+=food[i][j];
           }
           tState>>=1;
           i++;
     }
     for (long j=0;j<n;j++)
         if (fed[j]<need[j]) return false;       //如果fed小于need,直接返回 
     if (t<minc)
     {
        minc=t;
        minstate=state;
     }
     return true;
}
 
void run(long state,long level)
{
     if (record(state)) return;
     if (level==c) return;
     run(state+(1<<level),level+1);
     run(state,level+1);
     return;
}
 
int main()
{
    init();
    run(0,0);
    fout <<minc;
    for (long i=0;i<c;i++)
        if ((minstate>>i)&1) fout <<' ' <<i+1;
    fout <<endl;
    return 0;
}