/*
ID:superla1
PROG:	subset
LANG:	C++
*/

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("subset.in");
ofstream fout("subset.out");
long long dp[40][400];
int main()
{
	int n;
	fin>>n;
    int sum = n * (n + 1);
    if ( sum / 2 & 1)
    {
        fout<<0<<endl;
    }
    else
    {
        sum /= 4;
        dp[0][0] = 1;
        for (int i = 1; i <= sum; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j < i)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-i];
                }
            }
        }
        fout<<dp[n][sum]/2<<endl;
    }
	return 0;
}