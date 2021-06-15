#include <stdio.h>
#include <time.h>
#include <queue>
#include <stdlib.h>
using namespace std;
int arr[141][141]={0}; // 미로맵  
bool vi[141][141]={0};
int dx[]={1,-1,0,0};
char ara[2500];
int dy[]={0,0,1,-1};
bool f(int x,int y)
{
	if(x==78 && y==78) return 1;
	//printf("%d %d\n",x,y);
	for(int i=0;i<4;i++)
	{
		if(x+dx[i]>0 && x+dx[i]<80 && y+dy[i]>0 && y+dy[i]<80
		&&arr[x+dx[i]][y+dy[i]]==0)
		{
			arr[x+dx[i]][y+dy[i]]=9;
			if(f(x+dx[i],y+dy[i])) return 1;
			arr[x+dx[i]][y+dy[i]]=0;
		}
	}
	return 0;
}
int main()
{
	FILE *fp;
	fp=fopen("./1.txt","r");
	srand(time(NULL));
	int i=0;
	for(int i=0;i<80;i++)
	{
		fgets(ara,2024,fp);
		
		for(int j=0;j<80;j++)
		{
			arr[i][j]=ara[j*2]-'0';
			printf("%c ",ara[j*2]);
		}
		puts("");
	}
	for(int i=0;i<80;i++)
	{
		printf("			");
		for(int j=0;j<80;j++)
		{
			if(arr[i][j]==1)printf("■");
			else if (arr[i][j]==2) printf("★");
			else if(arr[i][j]==3) printf("◈"); 
			else printf("□"); 
		}
		puts("");
	}
	printf("			거리 검색 을 원할시 enter를 입력하세요\n");
	gets(ara);
	f(1,0);
	for(int i=0;i<80;i++)
	{
		printf("			");
		for(int j=0;j<80;j++)
		{
			if(arr[i][j]==1)printf("■");
			else if (arr[i][j]==2) printf("★");
			else if(arr[i][j]==3) printf("◈"); 
			else if(arr[i][j]==9) printf("♧"); 
			else printf("□"); 
		}
		puts("");
	}
	printf("			클로보를 따라갈시 목적지에 도착할수 있습니다\n");
}
