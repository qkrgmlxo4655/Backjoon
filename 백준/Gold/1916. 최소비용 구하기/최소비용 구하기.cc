#include <iostream>
#include <vector>
#include <algorithm>
#define INF 110000000
using namespace std;

/*
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5
*/

int get_current(vector<int>& via, vector<int>& chk) {
    int MIN=INF;
    int i, index=-1;

    for(i=0 ; i<via.size() ; i++) {
        if(chk[i]) continue;
        if(MIN > via[i]) {
            MIN=via[i];
            index = i;
        }
    }

    return index;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, j;
    int N, M;
    int x, y, value;
    cin >> N >> M;
    
    vector<vector<int>> V(N, vector<int> (N, INF));
    vector<int> via, chk(N, 0);

    for(i=0 ; i<M ; i++) {
        cin >> x >> y >> value;
        V[x-1][y-1]=min(V[x-1][y-1], value);
    }

    cin >> x >> y;
    x--; y--;

    for(i=0 ; i<N ; i++) {
        V[i][i] = 0;
    }
    
    via = V[x];
    chk[x]=1;
    
    for(i=0 ; i<N ; i++) {
        int current_idx = get_current(via, chk);

        if(current_idx == -1) break;
        chk[current_idx]=1;

        for(j=0 ; j<N ; j++) {
            via[j] = min(via[j], via[current_idx] + V[current_idx][j]);
        }
    }

    cout << via[y];
    return 0;
}