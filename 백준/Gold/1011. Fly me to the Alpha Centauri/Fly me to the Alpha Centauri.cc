#include <stdio.h>

int sol(int term) {
    long long int i,k;
    long long int sum=0;
    
    for(i=1 ; i<term ; i++) {
        if(i*i + i >= term) {
            break;
        }
    }
    
    for(k=1 ; k<=i ; k++) {
        sum+=k;
    }
    
    sum*=2;

    if(term <= sum-i) return i*2-1;
    else return i*2;
}

int main()
{
    int n;
    int x,y;
    int i;
    int term;
    
    scanf("%d", &n);
    
    for(i=0 ; i<n ; i++) {
        scanf("%d%d", &x,&y);
        term = y-x;
        
        printf("%d\n", sol(term));
    }
    return 0;
}
