#include <iostream>
#include <tuple>
#include <queue>
#define L 1111

using namespace std;


int MAP[L][L], chk[2][L][L];
int zx[4] = {0,0,1,-1}, zy[4] = {1,-1,0,0};
int N, M;

void BFS(int x, int y) {
    int move, breaking, i, temp_break;

    queue<tuple<int, int, int, int>> Q;
    Q.push(make_tuple(x, y, 0, 0));

    while(!Q.empty()) {
        x=get<0>(Q.front()); y=get<1>(Q.front()); move=get<2>(Q.front()); breaking=get<3>(Q.front());
        Q.pop();
        // cout << x << " " << y << " " << move << " " << breaking << endl;
        if(x==N-1 && y==M-1) {
            cout << move+1;
            return;
        }

        for(i=0 ; i<4 ; i++) {
            int zzx, zzy;
            zzx=x+zx[i]; zzy=y+zy[i];

            if(zzx<0 || zzy<0 || zzx>=N || zzy>=M || chk[breaking][zzx][zzy] || (MAP[zzx][zzy] == 1 && breaking != 0) ) continue;

            if(MAP[zzx][zzy] == 1) temp_break=1;
            else temp_break = breaking;

            chk[breaking][zzx][zzy]=1;
            Q.push(make_tuple(zzx, zzy, move+1, temp_break));
        }
    }
    cout << -1;
}

int main() {
    int i, j;
    string S;

    cin >> N >> M;

    for(i=0 ; i<N ; i++) {
        cin >> S;
        for(j=0 ; j<M ; j++) {
            MAP[i][j] = S[j]-'0';
        }
    }

    BFS(0, 0);
}