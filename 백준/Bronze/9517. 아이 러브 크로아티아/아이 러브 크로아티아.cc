#include <iostream>

using namespace std;

int main() {
    int k, n, t;
    int TI = 210;
    char z;
    cin >> k >> n;
    k--;
    for(int i=0 ; i<n ; i++) {
        cin >> t >> z;
        
        TI-=t;
        if(TI <= 0) break;

        if(z == 'T') {
            k++;
        }
        
        k%=8;
    }
    
    cout << k+1;
    return 0;
}