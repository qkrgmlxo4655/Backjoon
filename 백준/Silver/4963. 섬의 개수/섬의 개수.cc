#include <stdio.h>
int arr[60][60];
int zx[8]={-1,0,1,-1,1,-1,0,1},zy[8]={-1,-1,-1,0,0,1,1,1};

void dfs(int x,int y) {
    int i;
    
    if(!arr[x][y] || x<0 || y<0) return;
    
    arr[x][y] = 0;
    
    for(i=0 ; i<8 ; i++) {
        dfs(x+zx[i], y+zy[i]);
    }
}

int main() {
    int n,m;
    int cnt;
    int i,j;
    
    while(1) {
        cnt=0;
        scanf("%d%d", &n,&m);
        
        if(n==0 && m==0) break;
        
        for(i=0 ; i<m ; i++) {
            for(j=0 ; j<n ; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        
        for(i=0 ; i<m ; i++) {
            for(j=0 ; j<n ; j++) {
                if(arr[i][j]) {
                    dfs(i,j);
                    cnt++;
                }                
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}