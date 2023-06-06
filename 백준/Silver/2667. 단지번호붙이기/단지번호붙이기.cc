#include <stdio.h>
char arr[30][30];
int zx[4] = {0,0,1,-1}, zy[4] = {1,-1,0,0};
int dab[500];

int bfs(int sx, int sy){
    int q[1000][2];
    int st,ed;
    int i;
    int cnt=0;
    
    st=ed=-1;
    
    q[++st][0]=sx; q[st][1]=sy;

    while(st != ed) {
        int x=q[++ed][0];
        int y=q[ed][1];
        arr[x][y] = '0';
        cnt++;
        
        for(i=0 ; i<4 ; i++) {
            int xx=x+zx[i];
            int yy=y+zy[i];
            
            if(arr[xx][yy] == '1') {
                q[++st][0]=xx;
                q[st][1]=yy;
                arr[xx][yy]='0';
            }
        }
    }
    return cnt;
}

int main()
{
    int n, m;
    int i,j;
    int count=0;
    
    scanf("%d", &n);
    
    for(i=0 ; i<n ; i++) {
        for(j=0 ; j<n ; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    
    for(i=0 ; i<n ; i++) {
        for(j=0 ; j<n ; j++) {
            if(arr[i][j] == '1') {
                m = bfs(i,j);
                dab[count++]=m;
            }
        }
    }
    printf("%d\n", count);
    
    for(i=0 ; i<count ; i++) {
        for(j=i+1 ; j<count ; j++) {
            if(dab[i] > dab[j]) {
                int t= dab[i];
                dab[i]=dab[j];
                dab[j]=t;
            }
        }
    }
    
    for(i=0 ; i<count ; i++) {
        printf("%d\n", dab[i]);
    }
    
    return 0;
}
