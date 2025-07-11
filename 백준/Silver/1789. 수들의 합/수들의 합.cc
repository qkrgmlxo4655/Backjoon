#include <iostream>

using namespace std;
int main() {
    long long int n, sum=0, i;
    
    cin >> n;
    
    for(i=1 ; i<=n ; i++) {
        sum += i;

        if(sum > n) break;
    }

    cout << i-1;
    return 0;
}