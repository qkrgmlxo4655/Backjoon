#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
queue<tuple<int, int, int>> Q;
/*
6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1
*/

int zx[4]={-1,0,0,1}, zy[4]={0,-1,1,0};
int BFS(int N, int M, vector<vector<int>> A) {
    int i, j;
    int x, y, c;

    while(!Q.empty() ) {
        x=get<0>(Q.front()); y=get<1>(Q.front()); c=get<2>(Q.front());
        Q.pop();

        for(i=0 ; i<4 ; i++) {
            int zzx, zzy;
            zzx = x+zx[i]; zzy=y+zy[i];

            if(zzx<0 || zzx>=M || zzy<0 || zzy>=N) continue;

            if(A[zzx][zzy] == 0) {
                Q.push({zzx, zzy, c+1});
                A[zzx][zzy]=1;
            }
        }
    }

    for(i=0 ; i<M ; i++) {
        for(j=0 ; j<N ; j++) {
            if(A[i][j] == 0) {
                return -1;
            }
        }
    }

    return c;
}

int main() {
    int N, M;
    int i, j;
    cin >> N >> M;
    vector<vector<int>> A(M, vector<int> (N, 0));
    for(i=0 ; i<M ; i++) {
        for(j=0 ; j<N ; j++) {
            cin >> A[i][j];

            if(A[i][j] == 1) {
                Q.push(make_tuple(i,j,0));
            }
        }
    }

    cout << BFS(N, M, A);
    return 0;
}