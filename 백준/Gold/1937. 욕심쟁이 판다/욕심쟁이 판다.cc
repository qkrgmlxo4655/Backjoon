#include <stdio.h>
#include <algorithm>
#define M 888
using namespace std;

int a[M][M];
int table[M][M];
int zx[4]={-1,0,1,0}, zy[4]={0,-1,0,1};
int MAX,RMAX;

struct sg
{
	int x,y,num;
}chk[M*M];

bool com(sg i,sg j)
{
	return i.num<j.num;
}

void findtree(int p,int n)
{
	int i;
	
	int x,y,num;
	
	MAX=0;
	x=chk[p].x;
	y=chk[p].y;
	num=chk[p].num;

	for(i=0 ; i<4 ; i++)
	{
		if(x+zx[i]==0 || x+zx[i]>n || y+zy[i]==0 || y+zy[i]>n) continue;

		if(MAX<table[x+zx[i]][y+zy[i]]+1 && num!=a[x+zx[i]][y+zy[i]])
			MAX=table[x+zx[i]][y+zy[i]]+1;
	}

	table[x][y]=MAX;

	if(RMAX<MAX)
		RMAX=MAX;
}

int main()
{
	int n;
	int i,j;

	scanf("%d", &n);

	for(i=1 ; i<=n ; i++)
	{
		for(j=1 ; j<=n ; j++)
		{
			scanf("%d",&a[i][j]);
			chk[((i-1)*n)+j].x=i;
			chk[((i-1)*n)+j].y=j;
			chk[((i-1)*n)+j].num=a[i][j];
		}
	}

	sort(chk+1,chk+1+(n*n),com);
	RMAX=0;
	for(i=1 ; i<=n ; i++)
	{
		for(j=1 ; j<=n ; j++)
			findtree( ((i-1)*n)+j,n);
	}

	if(RMAX==0)
		RMAX=1;
	printf("%d", RMAX);
	return 0;

}