 #include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    int i, j;
    string S;

    cin >> N;
    cin >> S;

    vector<int> fail(N, 0);
    j=0;

    for(i=1 ; i<N ; i++) {
        while(j>0 && S[i] != S[j]) {
            j=fail[j-1];
        }

        if(S[i] == S[j]) {
            fail[i]=++j;
        }
    }

    cout << N-fail[N-1];
    return 0;
}