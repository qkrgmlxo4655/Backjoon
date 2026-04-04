#include <iostream>
#define MM 55

using namespace std;

int N, M;
int MAP[MM][MM], chk[MM][MM];
int ans;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
// d 0 북 1 동 2 남 3 서

void dfs(int r, int c, int d) {
    int i;
    int nx, ny;

    if(chk[r][c] != 1) {
        chk[r][c]=1; ans++;
    }

    for(i=0 ; i<4 ; i++) {
        nx=r+dx[i]; ny=c+dy[i];
        if(nx<0 || ny<0 || nx>=N || ny>=M || MAP[nx][ny]==1 || chk[nx][ny]) continue;
        else break;
    }

    if(i==4) {
        nx=r-dx[d]; ny=c-dy[d];
        if(MAP[nx][ny] == 1) {
            cout << ans;
            exit(0);
        } else {
            dfs(nx, ny, d);
        }
    } else {
        int new_d = (d + 3) % 4;
        nx=r+dx[new_d]; ny=c+dy[new_d];
        if(nx>=0 && ny>=0 && nx<N && ny<M && MAP[nx][ny]==0 && chk[nx][ny]==0) {
            dfs(nx, ny, new_d);
        } else {
            dfs(r, c, new_d);
        }
        
    }
}

int main() {
    int i, j;
    int r, c, d;
    cin >> N >> M;
    cin >> r >> c >> d;
    for(i=0 ; i<N ; i++) {
        for(j=0 ; j<M ; j++) {
            cin >> MAP[i][j];
        }
    }

    dfs(r, c, d);
    
    return 0;
}