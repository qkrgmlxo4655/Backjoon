#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>


#define INF 110000000

using namespace std;

typedef pair<int, int> P;
/*
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    int start;
    int V, E;
    int u, v, w;

    cin >> V >> E;
    vector<int> D(V, INF), chk(V, 0);
    vector<pair<int, int>> MAP[V];

    cin >> start;

    for(i=0 ; i<E ; i++) {
        cin >> u >> v >> w;
        MAP[u-1].push_back(make_pair( (v-1), w ));
    }

    priority_queue<P, vector<P>, greater<P>> pq;

    D[start-1]=0;
    pq.push({0, start-1});

    while(!pq.empty()) {
        int value = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(D[node] < value) continue;

        for(i=0 ; i<MAP[node].size() ; i++) {
            int next_node = MAP[node][i].first;
            int next_value = MAP[node][i].second;
            int new_value = value + next_value;

            if(new_value < D[next_node]) {
                D[next_node] = new_value;
                pq.push({new_value, next_node});
            }
        }
    }

    for(j=0 ; j<V ; j++) {
        if(D[j] == INF) {
            cout << "INF" << "\n";
        } else {
            cout << D[j] << "\n";
        }
    }

    return 0;
}