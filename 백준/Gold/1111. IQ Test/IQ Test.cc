#include <stdio.h>

int main() {
    int n;
    int i;
    long long int arr[55];
    long long int a,b,c,temp_a;
    
    scanf("%d", &n);
    
    for(i=0 ; i<n ; i++) {
        scanf("%lld", &arr[i]);
    }
    
    if(n<=2) {
        if(arr[0] == arr[1]) {
            printf("%lld", arr[0]);
        } else {
            printf("A");
        }
        return 0;
    }
    
    c = arr[2] - arr[1];
    temp_a = arr[1] - arr[0];
    
    if(temp_a == 0) {
        a = 1;
    } else {
        a = c/temp_a;
        if(a*temp_a != c) {
            printf("B");
            return 0;
        }
    }
    
    b = arr[1] - a * arr[0];
    
    for(i=1 ; i<n ; i++) {
        if(a*arr[i-1]+b != arr[i]) {
            printf("B");
            return 0;
        }
    }
    
    printf("%lld", a*arr[n-1]+b);
    return 0;
}