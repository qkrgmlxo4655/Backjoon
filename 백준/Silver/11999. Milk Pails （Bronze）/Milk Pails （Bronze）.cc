#include <iostream>

using namespace std;
int arr[2222], x[2], chk[1111];

int main() {
    int m;
    int st,ed,t=0;
    st=ed=-1;
    cin >> x[0] >> x[1] >> m;

    arr[++st]=0;
    while(st!=ed) {
        int s = arr[++ed];

        if(t<s) t=s;

        for(int i=0 ; i<2 ; i++) {
            if(s+x[i] <= m && chk[s+x[i]] == 0) {
                arr[++st]=s+x[i];
                chk[s+x[i]]=1;
            }
        }
    }
    cout << t;
    return 0;
}