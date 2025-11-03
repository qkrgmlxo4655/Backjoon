/*
    C++: Hello, World!
*/
#include <iostream>

using namespace std;

int main()
{
    int n; 
    int i, x;
    int flag, dab, max;
    max = dab = flag = 0;
    cin >> n;

    for(i=0 ; i<n; i++) {
        cin >> x;


        if(x==0) {
            if(i >= flag) {
                flag=i+2;
            } else {
                dab=0;
            }
        } else {
            dab++;
        }

        if(max < dab) {
            max = dab;
        }
    }

    cout << max;
    return 0;
}
