#include <iostream>
#include <vector>

using namespace std;

struct Fireball {
    int r, c, m, s, d;
};

int N, M, K;
vector<Fireball> fireballs;
vector<Fireball> MAP[55][55];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void move_fireballs() {
    for (auto& f : fireballs) {
        int nr = (f.r + dx[f.d] * (f.s % N) + N) % N;
        int nc = (f.c + dy[f.d] * (f.s % N) + N) % N;
        
        MAP[nr][nc].push_back({nr, nc, f.m, f.s, f.d});
    }

    fireballs.clear();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (MAP[i][j].size() == 0) continue;

            if (MAP[i][j].size() == 1) {
                fireballs.push_back(MAP[i][j][0]);
            } else {
                int sum_m = 0, sum_s = 0;
                int count = MAP[i][j].size();
                bool is_all_even = true, is_all_odd = true;

                for (auto& f : MAP[i][j]) {
                    sum_m += f.m;
                    sum_s += f.s;
                    if (f.d % 2 == 0) is_all_odd = false;
                    else is_all_even = false;
                }

                int next_m = sum_m / 5;
                int next_s = sum_s / count;

                if (next_m > 0) {
                    if (is_all_even || is_all_odd) {
                        for (int nd = 0; nd < 8; nd += 2) {
                            fireballs.push_back({i, j, next_m, next_s, nd});
                        }
                    } 
                    else {
                        for (int nd = 1; nd < 8; nd += 2) {
                            fireballs.push_back({i, j, next_m, next_s, nd});
                        }
                    }
                }
            }
            MAP[i][j].clear();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        fireballs.push_back({r - 1, c - 1, m, s, d});
    }

    while (K--) {
        move_fireballs();
    }

    int ans = 0;
    for (auto& f : fireballs) {
        ans += f.m;
    }

    cout << ans << "\n";

    return 0;
}