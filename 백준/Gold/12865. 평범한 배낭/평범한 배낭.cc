#include <stdio.h>
int arr[111111];

int main() {
    int n, k;
    int w,v;
    int i,j;
    int max = -1;
    scanf("%d%d", &n, &k);
    arr[0] = -1;
    for(i=0 ; i<n ; i++) {
        scanf("%d%d", &w, &v);
        
        for(j=100000 ; j>=0 ; j--) {
            if(arr[j] != 0) {
                int t = j+w;
                if(t > k) continue;
                int value = arr[j] + v;
                
                if(arr[t] < value) {
                    arr[t] = value;
                }
                
                if(max < value) {
                    max = value;
                }
            }
        }
    }
    printf("%d\n", max+1);
}