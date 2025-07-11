#include <iostream>

using namespace std;

int main() {
    string a;

    while( getline(cin, a)) {
        int alen = a.length();
        for(int i=0 ; i+2 < alen ; i++) {
            if(a.substr(i, 3) == "BUG") {
                a = a.substr(0, i) + a.substr(i+3, alen - i - 3);
                alen -= 3;
                i = max(i-3, -1);
            }
        }

        cout << a << endl;
    }
    return 0;
}