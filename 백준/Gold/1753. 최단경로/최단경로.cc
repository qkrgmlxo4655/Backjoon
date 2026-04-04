#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
#define M 22222
#define INF 1000000000

using namespace std;

int V, E, K;
typedef tuple<int,int> P;
vector<P> MAP[M];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,j;
    int u, v, w;

    cin >> V >> E >> K;

    for(i=0 ; i<E ; i++) {
        cin >> u >> v >> w;
        MAP[u].push_back({w,v});
    }

    vector<int> via(V+1, INF);
    priority_queue<P, vector<P>, greater<P>> Q;
    via[K]=0;
    Q.push({0, K});

    while(!Q.empty()) {
        auto [value, node] = Q.top(); Q.pop();
        if(via[node] < value) continue;

        for(i=0 ; i<MAP[node].size() ; i++) {
            int next_value=get<0>(MAP[node][i]), next_node=get<1>(MAP[node][i]);

            if(via[next_node] > value + next_value) {
                next_value = value + next_value;
                via[next_node] = next_value;
                Q.push({next_value, next_node});
            }
        }

    }

    for(i=1 ; i<=V ; i++) {
        if(via[i] == INF) {
            cout << "INF";
        } else {
            cout << via[i];
        }
        cout << "\n";
    }

    return 0;
}