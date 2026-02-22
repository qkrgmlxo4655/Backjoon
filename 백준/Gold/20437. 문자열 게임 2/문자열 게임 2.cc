#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff;

using namespace std;

int main() {
    int T, K;
    string W;
    int i, j;
    int MAX, MIN;
    cin >> T;

    for(i=0 ; i<T ; i++) {
        int flag=0;
        cin >> W;
        cin >> K;
        MAX=-INF; MIN=INF;

        queue<int> Q[26];
        vector<int> V(26, 0);

        for(j=0 ; j<W.size() ; j++) {
            int c=W[j]-'a';

            Q[c].push(j);
            V[c]++;

            if(V[c] == K) {
                int length = Q[c].front();
                Q[c].pop();
                length = j - length;
                MAX = max(MAX, length);
                MIN = min(MIN, length);
                flag=1;
                V[c]--;
            }

            // for(int k=0 ; k< 26 ; k++) {
            //     cout << V[k] << " ";
            // }
            // cout << endl;
        }
        
        if(!flag) {
            cout << -1 << "\n";
        } else {
            cout << (MIN+1) << " " << (MAX+1) << "\n";
        }
    }
    return 0;
}