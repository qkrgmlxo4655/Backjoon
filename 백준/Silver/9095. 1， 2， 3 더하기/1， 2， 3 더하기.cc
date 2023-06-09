#include <stdio.h>
int arr[111111];

int sol(int x) {
    if(x <= 0) return 0;
    if(arr[x] != 0) return arr[x];
    
    return sol(x-1) + sol(x-2) + sol(x-3);
}

int main() {
    int n, x;
    int i;
    scanf("%d", &n);
    
    arr[1]=1; arr[2]=2; arr[3]=4;
    for(i=0 ; i<n ; i++) {
        scanf("%d", &x);
        if(arr[x] == 0) {
            arr[x] = sol(x);
        }
        
        printf("%d\n", arr[x]);
    }
}