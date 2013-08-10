/*
ID:superla1
PROB:lamps
LANG:C++
*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

ifstream fin("lamps.in");
ofstream fout("lamps.out");
int n,c,light[10][10]={
                       {},
                       {0,0,0,0,0,0,0},
                       {0,0,0,1,1,1,0},
                       {0,0,1,0,1,0,1},
                       {0,0,1,1,0,1,1},
                       {0,1,0,0,1,0,0},
                       {0,1,0,1,0,1,0},
                       {0,1,1,0,0,0,1},
                       {0,1,1,1,1,1,1},
                       };
int minnum[50]={0,1,2,1,1,2,1,2,0};
int in[101];
int main()
{
      int i,j,k,t,p,q;
      fin>>n>>c;
      for(i=1;i<=n;i++)
	  {
			in[i]=-1;
	  }
      while(1)
      {
        fin>>t;
        if(t!=-1)
		{
			in[t]=1;
		}
        else 
		{
			break;
		}
      }
      while(1)
      {
        fin>>t;
        if(t!=-1)
		{
			in[t]=0;
		}
        else 
		{
			break;
		}
      }
      q=0;
      for(k=1;k<=8;k++) 
      {
        p=1;
        for(i=1;i<=n;i++)
        {
         if(in[i]==-1)continue;
         t=i%6;
         if(t==0)t=6;
         if(in[i]!=light[k][t]){p=0;break;}
        } 
        if(p==1&&c>=minnum[k]){
                 q=1;
                 for(j=1;j<=n;j++)
                  {
                  t=j%6;
                  if(t==0)t=6;
                  fout<<light[k][t];
                  }
                 fout<<endl;
               }
      }
      if(q==0)
	  {
		  fout<<"IMPOSSIBLE"<<endl;
	  }
      return 0;      
}