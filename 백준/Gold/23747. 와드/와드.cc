#include <stdio.h>
#include <string.h>
#define M 1111

char arr[M][M];
char walk[M*M];
int map[M][M];

void check(int x,int y,char t,int n,int m) {
    if(t != arr[x][y] || x<0 || y<0 || x==n || y==m || map[x][y]) return;
    map[x][y]=1;
    check(x+1,y,t,n,m);
    check(x-1,y,t,n,m);
    check(x,y+1,t,n,m);
    check(x,y-1,t,n,m);
}

int main() {
    int n,m,x,y;
    int i,j;
    
    scanf("%d%d", &n, &m);
    
    for(i=0 ; i<n ; i++) {
        scanf("%s", &arr[i]);
    }

    scanf("%d%d", &x, &y);
    scanf("%s", &walk);
    x--; y--;
    for(i=0 ; i<strlen(walk) ; i++) {
        if(walk[i] == 'W') {
            check(x,y,arr[x][y],n,m);
        } else {
            if(walk[i] == 'U') {
                x--;
                if(x<0) x=0;
            } else if(walk[i] == 'L') {
                y--;
                if(y<0) y=0;
            } else if(walk[i] == 'D') {
                x++;
                if(x==n) {
                    x=n-1;
                }
            } else if(walk[i] == 'R') {
                y++;
                if(y==m) {
                    y=m-1;
                }
            }
        }
    }
    
    map[x][y]=1;
    if(x-1>=0) map[x-1][y]=1;
    if(x+1 != n) map[x+1][y]=1;
    if(y-1>=0) map[x][y-1]=1;
    if(y+1 != m) map[x][y+1]=1;

    for(i=0 ; i<n ; i++) {
        for(j=0 ; j<m ; j++) {
            if(map[i][j] == 1) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}