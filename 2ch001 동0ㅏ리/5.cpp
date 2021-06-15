#include <stdio.h>
#include <time.h>
#include <queue>
#include <stdlib.h>
using namespace std;
int arr[45][45]={0}; // ¹Ì·Î¸Ê  
int vi[145][145]={0};
int dx[]={1,0,0,0};
int dy[]={0,1,-1,1};


void f(int x,int y)
{
	if(x==78 && y==78) return ;
	printf("%d %d\n",x,y);
	int i=rand()%2;
	while(1)
	{
		if(x+dx[i]>0 && x+dx[i]<79
		 && y+dy[i]>0 && y+dy[i]<79
		)
		{
			vi[x+dx[i]][y+dy[i]]=0 ;
			f(x+dx[i],y+dy[i]);
			return ;
		}
		else 
		{
			i=rand()%4;
	
		}
		
	}
	
}
int main()
{
	srand(time(NULL));
	for(int i=0;i<80;i++)
	{
		for(int j=0;j<80;j++)
		{
			vi[i][j]=1;
		}
	}
	vi[1][0]=1;
	f(1,0);
	
	for(int i=0;i<70;i++)
	{
		for(int j=0;j<50;j++)
		{
			vi[rand()%79][rand()%79]=0;
		}
	}
	for(int i=0;i<80;i++)
	{
		for(int j=0;j<80;j++)
		{
			if (i==0 || i==79 || j==0 || j==79) vi[i][j]=1;
		
		}
	}
	vi[1][0]=2;
	vi[78][79]=3;
	for(int i=0;i<80;i++)
	{
		for(int j=0;j<80;j++)
		{
			printf("%d ",vi[i][j]);
		}
		puts("");
	}
	
}
