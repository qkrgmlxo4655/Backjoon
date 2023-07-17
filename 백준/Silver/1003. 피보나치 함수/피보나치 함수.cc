#include <stdio.h>
int arr[55][2];

int main() {
    int n,x;
    int i;
    
    scanf("%d", &n);
    
    arr[0][0]=1;
    arr[1][1]=1;
    
    for(i=2 ; i<=40 ; i++) {
        arr[i][0] = arr[i-1][0] + arr[i-2][0];
        arr[i][1] = arr[i-1][1] + arr[i-2][1];
    }
    
    for(i=0 ; i<n ; i++) {
        scanf("%d", &x);
        
        printf("%d %d\n", arr[x][0], arr[x][1]);
    }
    return 0;
}