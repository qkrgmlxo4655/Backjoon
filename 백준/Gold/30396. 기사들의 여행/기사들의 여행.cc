/*
    C++: Hello, World!

1111
1111
1111
0110
0111
1111
1011
1111
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>

#define M 5
using namespace std;

int dist[M][M][M][M];
int zx[8] = {-2, -1, 1, 2, -2, -1, 1, 2}, zy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

struct sg {
    int x,y;
};

vector<sg> a_v, b_v;

int valid(int nr, int nc) {
    return (nr >= 0 && nr < 4 && nc>=0 && nc < 4);
}

void bfs(int s, int e) { 
    queue<tuple<int,int,int>> q;
    q.push({s, e, 0});
    dist[s][e][s][e] = 0;

    bool via[4][4] = {false,};
    via[s][e]=true;

    while(!q.empty()) {
        auto [r, c, d] = q.front();
        q.pop();
        
        for(int i=0 ; i<8 ; i++) {
            int nr = r+zx[i];
            int nc = c+zy[i];

            if(valid(nr, nc) && !via[nr][nc]) {
                via[nr][nc]=true;
                dist[s][e][nr][nc] = d+1;
                q.push({nr, nc, d+1});
            }
        }
    }
}


#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()

const int NIL = -1;
const bool LEFT = false;
const bool RIGHT = true;
const int MAX = 10000;

int N;
vector<int> rmatch, lmatch;
vector<int> l_pred, r_pred;
vector<vector<int>> w;
vector<int> lh, rh;

int find_augmenting_path() {//find augmenting path and return the index of an unmatched r, if any

	queue<pair<int, bool>> q;//{vertex idx, (0: left, 1: right)}
	vector<bool> FL(N), FR(N);
	vector<int> slack(N, INT_MAX), slack_l(N, NIL);

	for (int l = 0; l < N; l++) {
		if (lmatch[l] != NIL) continue;//unmatched l in L
		l_pred[l] = NIL;
		q.emplace(l, LEFT);
		FL[l] = true;
	}

	for (int l = 0; l < N; l++) {
		if (!FL[l]) continue;

		for (int r = 0; r < N; r++) {//none of R is in FR now
			if (lh[l] + rh[r] - w[l][r] < slack[r]) {
				slack[r] = lh[l] + rh[r] - w[l][r]; 
				if (slack[r] < 0) cout << lh[l] << "+" << rh[r] << "-" << w[l][r] << "=" << slack[r] << '\n';
				slack_l[r] = l;
			}
		}
	}


	while (true) {
		if (q.empty()) {
			int delta = INT_MAX;

			for (int r = 0; r < N; r++) {//optimize delta calculation with slack variable
				if (!FR[r]) delta = min(delta, slack[r]);
			}

			if (delta == INT_MAX) return -1;

			for (int i = 0; i < N; i++){
				if (FL[i]) lh[i] -= delta;

				if (FR[i]) rh[i] += delta;
			}

			for (int i = 0; i < N; i++) {
				if (FR[i]) continue;
					slack[i] -= delta;
					
					if (!slack[i]) {
						r_pred[i] = slack_l[i];

						if (rmatch[i] == NIL) return i;//unmatched
						q.emplace(i, RIGHT);
						FR[i] = true;
				}
			}
		}

		auto [u, V] = q.front();
		q.pop();

		if (V == RIGHT) {//matched right
			int l = rmatch[u];
			l_pred[l] = u;
			FL[l] = true;
			q.emplace(l, LEFT);

			for (int r = 0; r < N; r++) {
				if (!FR[r] && (slack[r] > lh[l] + rh[r] - w[l][r])) {
					slack[r] = lh[l] + rh[r] - w[l][r];
					slack_l[r] = l;
				}
			}
		}
		else {//left
			for (int r = 0; r < N; r++) {
				if ((rmatch[u] != r && lh[u] + rh[r] == w[u][r]) && !FR[r]) {
					r_pred[r] = u;

					if (rmatch[r] == NIL) return r;//unmatched
					q.emplace(r, RIGHT);
					FR[r] = true;
				}
			}
		}
	}
}

void update_match(int cur) {//backtrace augmenting path
	bool toggle = RIGHT;

	while (cur != NIL) {
		if (toggle == RIGHT) {
			rmatch[cur] = r_pred[cur];
			lmatch[r_pred[cur]] = cur;
			cur = r_pred[cur];
		}
		else cur = l_pred[cur];

		toggle = !toggle;
	}
}

int hungarian() {

	// default feasible vertex labeling
	for (int l = 0; l < N; l++) lh[l] = *max_element(all(w[l]));

	int max_match_weight = 0;

	while (true) {
		int r = find_augmenting_path();
		if (r < 0) break;
		update_match(r);
	}

	for (int l = 0; l < N; l++) {
		max_match_weight += w[l][lmatch[l]];
	}

	return max_match_weight;
};

void init() {
	w.assign(N, vector<int>(N));
	lh.resize(N);
	rh.resize(N);
	lmatch.resize(N, NIL);
	rmatch.resize(N, NIL);
	l_pred.resize(N, NIL);
	r_pred.resize(N, NIL);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[M][M], b[M][M];
    int i, j, k, l;
    for(i=0 ; i<4 ; i++) for(j=0 ; j<4 ; j++)
        for(k=0 ; k<4 ; k++) for(l=0 ; l<4 ; l++)
            dist[i][j][k][l]=-1;

    for(i=0 ; i<4 ; i++) {
        for(j=0 ; j<4 ; j++) {
            bfs(i, j);
        }
    }

    sg temp;

    for(i=0 ; i<4 ; i++) {
        string s;
        cin >> s;
        for(j=0 ; j<4 ; j++) {
            a[i][j] = s[j]-'0';

            if(a[i][j] == 1) {
                temp.x=i; temp.y=j;
                a_v.push_back(temp);
            }
        }
    }

    for(i=0 ; i<4 ; i++) {
        string s;
        cin >> s;
        for(j=0 ; j<4 ; j++) {
            b[i][j] = s[j]-'0';

            if(b[i][j] == 1) {
                temp.x=i; temp.y=j;
                b_v.push_back(temp);
            }
        }
    }

    N=a_v.size();

    if(N == 0) {
        cout << 0 << endl;
        return 0;
    }
    init();

    for(i=0 ; i<N ; i++) {
        int q,ww,e,r;
        q=a_v[i].x;
        ww=a_v[i].y;
        for(j=0 ; j<N ; j++) {
            e=b_v[j].x;
            r=b_v[j].y;
            w[i][j] = -dist[q][ww][e][r];
        }
    }

    cout << -hungarian();
    return 0;
}
