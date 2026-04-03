#include <iostream>
#include <vector>

using namespace std;

int dice[7] = {0, 0, 0, 0, 0, 0, 0};
int N, M, x, y, K;
int MAP[21][21];

int zx[] = {0, 0, 0, -1, 1};
int zy[] = {0, 1, -1, 0, 0};

void roll(int dir) {
    int d1 = dice[1], d2 = dice[2], d3 = dice[3], d4 = dice[4], d5 = dice[5], d6 = dice[6];
    if (dir == 1) { // 동
        dice[1] = d4; dice[3] = d1; dice[4] = d6; dice[6] = d3;
    } else if (dir == 2) { // 서
        dice[1] = d3; dice[3] = d6; dice[4] = d1; dice[6] = d4;
    } else if (dir == 3) { // 북
        dice[1] = d5; dice[2] = d1; dice[5] = d6; dice[6] = d2;
    } else if (dir == 4) { // 남
        dice[1] = d2; dice[2] = d6; dice[5] = d1; dice[6] = d5;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int command;
        cin >> command;

        int zzx = x + zx[command];
        int zzy = y + zy[command];

        if (zzx < 0 || zzx >= N || zzy < 0 || zzy >= M) continue;

        // 주사위 굴리기
        roll(command);

        // 지도 바닥면과 주사위 바닥면(dice[6]) 상호작용
        if (MAP[zzx][zzy] == 0) {
            MAP[zzx][zzy] = dice[6];
        } else {
            dice[6] = MAP[zzx][zzy];
            MAP[zzx][zzy] = 0;
        }

        x = zzx; y = zzy;
        cout << dice[1] << "\n";
    }

    return 0;
}