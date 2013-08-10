/*
ID:superla1
PROB:sprime
LANG:C++
*/
//#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
ifstream fin ("sprime.in");
ofstream fout ("sprime.out");
 
bool isPrime(long num)
{
     if (num==1 || num==0)
        return false;
     long max=long(sqrt(double(num)));
     for (long i=2;i<=max;i++)
     {
         if (num%i==0)
            return false;
     }
     return true;
}
 
void DFS(long num,long times)            //DFSÃ¶¾ÙÊý×Ö 
{
     if (times==0)
     {
        fout <<num <<endl;
        return;
     }
     times--;
     for (long i=0;i<=9;i++)
     {
         if (isPrime(num*10+i))
            DFS(num*10+i,times);
     }
     return;
}
 
int main()
{
    long len;
    fin >>len;
    DFS(0,len);
    return 0;
}