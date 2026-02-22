#include <iostream>
#include <vector>

using namespace std;

void change(string S[], int x, int y) {
    int i, j;
    for(i=x ; i<=x+2 ; i++) {
        for(j=y ; j<=y+2 ; j++) {
            S[i][j] = (1-(S[i][j]-'0')) + '0';
        }
    }
}

int main() {
    int N, M;
    int i, j;
    int cnt=0;

    cin >> N >> M;
    string S[N], T[N];

    for(i=0 ; i<N ; i++) {
        cin >> S[i];
    }

    for(i=0 ; i<N ; i++) {
        cin >> T[i];
    }

    for(i=0 ; i<N-2 ; i++) {
        for(j=0 ; j<M-2 ; j++) {
            if(S[i][j] != T[i][j]) {
                change(S, i, j);
                cnt++;
            }
        }
    }

    for(i=0 ; i<N ; i++) {
        if(S[i] != T[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
    
    
    return 0;
}