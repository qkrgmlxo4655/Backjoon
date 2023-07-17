#include <stdio.h>
#define M 100

int main() {
    int n,m;
    int min, max=1;
    char arr[M][M];
    int i,j,k;
    
    scanf("%d%d", &n, &m);
    
    for(i=0 ; i<n ; i++) {
        scanf("%s", &arr[i]);
    }
    
    if(n > m) {
        min = m;
    } else {
        min = n;
    }
    
    if(min == 1) {
        printf("1");
    } else {
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<m ; j++) {
                for(k=1 ; k<min ; k++) {
                    int rt, ld;
                    rt=j+k; ld=i+k;
                    
                    if(rt >=m || ld>=n) continue;

                    if(arr[i][j] == arr[i][rt] && arr[i][j] == arr[ld][j] && arr[i][j] == arr[ld][rt]) {
                        if(max < (k+1)*(k+1)) {
                            max = (k+1)*(k+1);
                        }
                    }
                }
            }
        }
        printf("%d", max);
    }

    return 0;
}