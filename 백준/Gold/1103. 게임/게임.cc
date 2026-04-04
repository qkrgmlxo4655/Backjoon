#include <iostream>
#include <vector>
#include <algorithm>
#define MM 55

using namespace std;

int N, M;
char arr[MM][MM];
int dp[MM][MM];
bool visited[MM][MM];
int dx[] = {0,1,-1,0}, dy[] = {1,0,0,-1};

int dfs(int x, int y) {
    int i;

    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y]=1; visited[x][y]=true;
    for(i=0 ; i<4 ; i++) {
        int nx, ny;
        nx=x+(dx[i]*(arr[x][y]-'0')); ny=y+(dy[i]*(arr[x][y]-'0'));
        if(nx<0 || ny<0 || nx>=N || ny>=M || arr[nx][ny]=='H') continue;

        if(visited[nx][ny]) {
            cout << -1;
            exit(0);
        }

        dp[x][y] = max(dp[x][y], dfs(nx, ny)+1);
    }

    visited[x][y]=false;
    return dp[x][y];
}

int main() {
    int i, j;
    string S;

    cin >> N >> M;

    for(i=0 ; i<N ; i++) {
        cin >> S;
        for(j=0 ; j<M ; j++) {
            arr[i][j]=S[j];
            dp[i][j]=-1;
            visited[i][j]=false;
        }
    }

    cout << dfs(0, 0) << "\n";
    return 0;
}