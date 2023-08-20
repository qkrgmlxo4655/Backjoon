#include <stdio.h>
#define M 100

int zx[4] = { 0,-1,0,1 }, zy[4] = { -1,0,1,0 };
int arr[M][M], pass[M*5][5];
int sx, sy;

int bfs(int n, int x, int y, int tx, int ty) {
    int st, ed;
    int count, zzx, zzy;
    int chk[M][M] = { 0, };
    int q[M*M*M][3];
    int i;

    st = ed = -1;
    q[++st][0] = x; q[st][1] = y; q[st][2] = 0;

    while (st != ed) {
        x = q[++ed][0]; y = q[ed][1]; count = q[ed][2];
        chk[x][y] = 1;

        if (tx == x && ty == y) return count;

        for (i = 0; i < 4; i++) {
            zzx = x + zx[i]; zzy = y + zy[i];

            if (zzx<1 || zzy <1 || zzx > n || zzy > n ||
                arr[zzx][zzy] || chk[zzx][zzy]) continue;

            q[++st][0] = zzx; q[st][1] = zzy; q[st][2] = count + 1;
            chk[zzx][zzy] = 1;
        }
    }

    return -1;
}

int main()
{
    int n, m, k;
    int i, j;
    int charge;
    int min, point;
    int chk[M*5] = { 0, };

    scanf("%d%d%d", &n, &m, &k);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    scanf("%d%d", &sx, &sy);

    for (i = 0; i < m; i++) {
        scanf("%d%d%d%d", &pass[i][0], &pass[i][1], &pass[i][2], &pass[i][3]);
        pass[i][4] = bfs(n, pass[i][0], pass[i][1], pass[i][2], pass[i][3]);
    }

    for (i = 0; i < m; i++) {
        min = 99999999;
        point = 0;
        for (j = 0; j < m; j++) {
            if (chk[j]) continue;
            charge = bfs(n, sx, sy, pass[j][0], pass[j][1]);

            if (charge == -1) {
                k = -99999999;
                point = 0;
                break;
            }

            if (min >= charge) {
                if (min == charge) {
                    if (point != -1) {
                        if (pass[j][0] < pass[point][0]) {
                            point = j;
                        }
                        if (pass[j][0] == pass[point][0] && pass[j][1] < pass[point][1]) {
                            point = j;
                        }
                    }
                    else {
                        point = j;
                    }
                }
                else {
                    min = charge;
                    point = j;
                }
            }
        }

        chk[point] = 1;
        k = k - min - pass[point][4];

        if (k < 0) {
            k = -1; break;
        }
        else {
            k = k + pass[point][4] * 2;
        }

        sx = pass[point][2]; sy = pass[point][3];
    }

    printf("%d", k);
    return 0;
}
