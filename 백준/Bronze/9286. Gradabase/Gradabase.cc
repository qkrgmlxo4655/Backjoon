#include <iostream>

using namespace std;

int main() {
    int n, m, x;
    cin >> n;
    
    for(int i=0 ; i<n ; i++) {
        cin >> m;
        cout << "Case " << i+1 << ":"  << endl;

        for(int j=0 ; j<m ; j++) {
            cin >> x;
            
            if(x==6) continue;
            
            cout << x+1 << endl;
        }
    }
    
    return 0;
}