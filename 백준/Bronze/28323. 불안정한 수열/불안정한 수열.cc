#include <stdio.h>
#define M 555555
int arr[M];

int main() {
    int n;
    int i,j;
    int s, count=1;
    
    scanf("%d", &n);
    for(i=0 ; i<n ; i++) {
        scanf("%d", &arr[i]);
    }
    
    s=arr[0];
    
    for(i=1 ; i<n ; i++) {
        if(s%2 == 1) {
            if(arr[i]%2==0) {
                count++;
                s=arr[i];
            }
        } else {
            if(arr[i]%2==1) {
                count++;
                s=arr[i];
            }
        }
    }
    
    printf("%d", count);
    
    return 0;
}