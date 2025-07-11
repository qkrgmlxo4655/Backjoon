#include <iostream>

using namespace std;
int zy[4]={1, 0, -1, 0}, zx[4]={0,1,0,-1};
int main() {
    int n, x, y, p=1, cnt=0;
    cin >> n;
    x=0; y=0;
    
    if(n==0) {
        cout << "0 0";
    } else {

        for(int i=0 ; ; i++) {
            for(int j=0 ; j<p ; j++) {
                x=x+zx[i%4]; y=y+zy[i%4];
                cnt++;
                if(cnt==n) break;
            }
            if(cnt==n) break;

            if((i+1)%2==0) p++;

        }
        cout << x << " " << y << endl;
    }
    return 0;
}