#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 100000000

using namespace std;

int N, E;
vector<pair<int, int>> adj[805];

vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < d) continue;

        for (auto edge : adj[now]) {
            int next = edge.first;
            int next_dist = d + edge.second;

            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist_from_1 = dijkstra(1);
    vector<int> dist_from_v1 = dijkstra(v1);
    vector<int> dist_from_v2 = dijkstra(v2);

    long long path1 = (long long)dist_from_1[v1] + dist_from_v1[v2] + dist_from_v2[N];
    long long path2 = (long long)dist_from_1[v2] + dist_from_v2[v1] + dist_from_v1[N];

    long long ans = min(path1, path2);

    if (ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}