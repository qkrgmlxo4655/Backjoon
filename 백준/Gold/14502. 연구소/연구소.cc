#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int zx[4]={0,0,1,-1}, zy[4]={1,-1,0,0};
queue<pair<int, int>> Q;

int BFS(vector<vector<int>> V) {
    int i, j;
    queue<pair<int, int>> TQ = Q;

    while(!TQ.empty()) {
        int x=TQ.front().first, y=TQ.front().second;
        TQ.pop();

        for(i=0 ; i<4 ; i++) {
            int zzx, zzy;
            zzx = x + zx[i]; zzy = y + zy[i];

            if(zzx < 0 || zzy < 0 || zzx >= N || zzy >= M) continue;

            if(V[zzx][zzy] == 0) {
                V[zzx][zzy]=2;
                TQ.push(make_pair(zzx, zzy));
            }
        }
    }

    int cnt=0;
    for(i=0 ; i<N ; i++) {
        for(j=0 ; j<M ; j++) {
            if(V[i][j] == 0) cnt++;
        }
    }

    return cnt;
}

int build(int i, int j, int k, vector<vector<int>>& V) {
    int wall[3][2];

    wall[0][0] = i/M; wall[0][1] = i%M;
    wall[1][0] = j/M; wall[1][1] = j%M;
    wall[2][0] = k/M; wall[2][1] = k%M;

    for(int p=0 ; p<3 ; p++) {
        if(V[wall[p][0]][wall[p][1]] != 0) return 0;
    }

    for(int p=0 ; p<3 ; p++) {
        V[wall[p][0]][wall[p][1]]=1;
    }

    return 1;
}

void destory(int i, int j, int k, vector<vector<int>>& V) {
    int wall[3][2];

    wall[0][0] = i/M; wall[0][1] = i%M;
    wall[1][0] = j/M; wall[1][1] = j%M;
    wall[2][0] = k/M; wall[2][1] = k%M;

    for(int p=0 ; p<3 ; p++) {
        V[wall[p][0]][wall[p][1]]=0;
    }
}

int main() {
    int i, j, k;
    int MAX=0;

    cin >> N >> M;

    vector<vector<int>> V(N, vector<int> (M, 0));

    for(i=0 ; i<N ; i++) {
        for(j=0 ; j<M ; j++) {
            cin >> V[i][j];

            if(V[i][j] == 2) {
                Q.push(make_pair(i, j));
            }
        }
    }

    for(i=0 ; i<N*M ; i++) {
        for(j=0 ; j<N*M ; j++) {
            for(k=0 ; k<N*M ; k++) {
                if(i==j || i==k || j==k) continue;

                if(!build(i, j, k, V)) {
                    continue;
                }

                MAX = max(MAX, BFS(V));
                destory(i, j, k, V);
            }
        }
    }

    cout << MAX;
    return 0;
}