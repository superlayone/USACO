/*
ID:superla1
PROB:castle
LANG:C++
*/
#include <fstream>
#include <math.h>

int Graph[105][105]={0};
bool wall[105][105][4]={0};   //0代表无墙，1有墙 //第三个值：0西面有墙，1北面有墙，2东面有墙 3南面有墙 
                                                        //    1
                                                        //0       2
                                                        //    3
int  f[105][105]={0};       //记录各个连通分量 （第cnt个） 
int c[10010]={0};      //第cnt个连通分量房间的数目 
using namespace std;
 
ifstream cin("castle.in");
ofstream cout("castle.out");
 
int n,m,cnt;           //cnt表示房间数 
void input()
{
   cin>>n>>m;int temp;
   for(int i=1; i<=m; i++)
   for(int j=1; j<=n; j++)
     {
           cin>>temp;
           if(temp&1)wall[i][j][0]=1;
           if(temp&2)wall[i][j][1]=1;
           if(temp&4)wall[i][j][2]=1;
           if(temp&8)wall[i][j][3]=1;
     }
 
}
 
void dfs(int i,int j,int &count)
{
     if(i<1||i>m||j<1||j>n||Graph[i][j])return;
     f[i][j]=cnt; Graph[i][j]=++count;
     if(!wall[i][j][0])dfs(i,j-1,count);
     if(!wall[i][j][1])dfs(i-1,j,count);
     if(!wall[i][j][2])dfs(i,j+1,count);
     if(!wall[i][j][3])dfs(i+1,j,count);
}
 
 
 
int main()
{
    input();
    cnt=0;
    int max=0;
    for(int i=1; i <= m; i++ )
    for(int j=1; j <= n ; j++)
    {
      if(!Graph[i][j])
         {
                      int count=0;
                      cnt++;
                      dfs(i,j,count);
 
                      if(count>max) 
                            max=count;
                      c[cnt]=count; 
         }
    } 
 
    cout<<cnt<<endl;
    cout<<max<<endl;
    int ii,jj,mmax=0;char ch;// 最大房间的信息
 
 
    for(int j=1; j<=n; j++) 
    for(int i=m; i>=1; i--)
    {
      //i,j
      if(wall[i][j][1]&&f[i][j]!=f[i-1][j])
            {
 
                int x1=f[i][j],x2=f[i-1][j];
                if(c[x1]+c[x2]>mmax){ mmax=c[x1]+c[x2]; ii=i; jj=j; ch='N'; }
            }
      if(wall[i][j][2]&&f[i][j]!=f[i][j+1])
         {
 
            int x1=f[i][j],x2=f[i][j+1];
            if(c[x1]+c[x2]>mmax){ mmax=c[x1]+c[x2]; ii=i; jj=j; ch='E'; }
         }
 
 
    }
 
    cout<<mmax<<endl;
    cout<<ii<<' '<<jj<<' '<<ch<<endl;
 
    //system("pause");
    return 0;
}