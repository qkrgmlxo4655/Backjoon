#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int N, K;
int knap[101][100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    int w, v;

    cin >> N >> K;
    vector<tuple<int,int>> V;

    for(i=0 ; i<N ; i++) {
        cin >> w >> v;
        V.push_back({v, w});
    }

    for(i=1 ; i<=N ; i++) {
        auto [v, w] = V[i-1];

        for(j=1 ; j<=K ; j++) {
            if(j < w) {
                knap[i][j]=knap[i-1][j];
            } else {
                knap[i][j]=max(knap[i-1][j], knap[i-1][j-w] + v);
            }
        }
    }

    cout << knap[N][K];
    return 0;
}