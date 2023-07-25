#include <stdio.h>
#define M 1111

int arr[M][M];
int zx[4]={1,0,-1,0}, zy[4]={0,1,0,-1};

int main() {
    int i,j;
    int n,target;
    int dx,dy,x,y,xx,yy;
    int k;
    
    scanf("%d%d", &n, &target);
    x=y=k=0;
    
    for(i=n*n ; i>=1 ; i--) {
        arr[x][y] = i;
        xx = x+zx[k%4];
        yy = y+zy[k%4];
        
        if(xx == n || xx<0 || yy<0 || yy==n || arr[xx][yy] != 0) {
            k++;
            xx = x+zx[k%4];
            yy = y+zy[k%4];
        }
        
        if(i == target) {
            dx = x;
            dy = y;
        }
        
        x=xx;
        y=yy;
    }
    
    for(i=0 ; i<n ; i++) {
        for(j=0 ; j<n ; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("%d %d", dx+1,dy+1);
    return 0;
}