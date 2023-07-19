#include <stdio.h>
#define M 555555
int arr[M];

int main() {
    int n;
    int i,j;
    long long int count=1, dab=1;
    
    scanf("%d", &n);
    
    for(i=0 ; i<n ; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(i=n-2 ; i>=0 ; i--) {
        if(count+1 <= arr[i]) {
            count++;
        } else if(arr[i] < count) {
            count = arr[i];
        }
        dab+=count;
    }
    
    printf("%lld", dab);
    return 0;
}