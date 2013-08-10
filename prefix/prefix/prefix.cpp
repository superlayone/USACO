/*
ID:		superla1
PROG:	prefix
LANG:	C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
	ifstream fin("prefix.in",ios::in);
	ofstream fout("prefix.out");
	char Collection[201][11];
	int CollectionLen[201];
	string S;
	string STemp;
int main()
{

	long SSize,Re=0;
	int CollectionSize;
	bool Flag;
	for(CollectionSize=0;;CollectionSize++)
	{
		fin>>Collection[CollectionSize];
		CollectionLen[CollectionSize]=strlen(Collection[CollectionSize]);
		if(strcmp(Collection[CollectionSize],".")==0)
		{
			break;
		}
	}
	//fout<<i;
	while(fin>>STemp)
	{
		S+=STemp;
	}
	SSize=S.size();
	for(int i=0;i<SSize;i++)
	{
		for(int j=0;j<=CollectionSize;j++)
			if(i+CollectionLen[j]>SSize) 
			{
					continue;
			}
			else
			{
				Flag=false; 
				for(int k=0;k<CollectionLen[j];k++)
				{
					if(S[i+k]!=Collection[j][k])  
					{
						Flag=true;
						break;
					}
				}
				if (!Flag) 
				{
					Re=(CollectionLen[j]+i>Re?CollectionLen[j]+i:Re);
				}
			}
		if(i+1>Re) 
		{
			break; //ÍË³öÌõ¼þ
		}
	}
	fout<<Re<<endl;
	return 0;
}