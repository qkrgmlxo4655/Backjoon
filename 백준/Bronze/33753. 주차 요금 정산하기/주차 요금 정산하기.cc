#include <iostream>

using namespace std;

int main() {
    int a, b, c, t, s=0;
    cin >> a >> b >> c >> t;
    
    t-=30;
    
    if(t >= 0) {
        s = c * (int)(t/b);
        if(t%b != 0) s += c;
    }
    cout << a + s;    
    return 0;
}