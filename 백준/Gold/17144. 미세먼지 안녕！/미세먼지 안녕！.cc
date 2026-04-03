#include <iostream>
#include <vector>

using namespace std;

int R, C, T;
int MAP[51][51], temp_MAP[51][51];
int X,Y;
int zx[4]={0,0,1,-1}, zy[4]={1,-1,0,0};
int up[2], down[2];

void spread() {
    int i, j, k;

    for(i=0 ; i<R ; i++) {
        for(j=0 ; j<C ; j++) {
            temp_MAP[i][j] = MAP[i][j];
        }
    }

    for(i=0 ; i<R ; i++) {
        for(j=0 ; j<C ; j++) {
            if(MAP[i][j] > 0) {
                int spraed_weight = MAP[i][j]/5;
                for(k=0 ; k<4 ; k++) {
                    int zzx, zzy;
                    zzx = i + zx[k]; zzy = j + zy[k];

                    if(zzx<0 || zzy<0 || zzx>=R || zzy>=C || MAP[zzx][zzy] == -1) continue;

                    temp_MAP[zzx][zzy] = temp_MAP[zzx][zzy] + spraed_weight;
                    temp_MAP[i][j] -= spraed_weight;
                }
            }
        }
    }

    for(i=0 ; i<R ; i++) {
        for(j=0 ; j<C ; j++) {
            MAP[i][j] = temp_MAP[i][j];
        }
    }
}

int get_sum() {
    int i, j;
    int sum=0;

    for(i=0 ; i<R ; i++) {
        for(j=0 ; j<C ; j++) {
            if(MAP[i][j] == -1) continue;
            sum+=MAP[i][j];
        }
    }

    return sum;
}

void active() {
    int i, j;
    int x, y;
    int dir=0;
    x=X-1; y=Y+1;
    
    for(i=0 ; i<R ; i++) {
        for(j=0 ; j<C ; j++) {
            temp_MAP[i][j] = MAP[i][j];
        }
    }  

    int up[4]={0,3,1,2}, down[4]={0,2,1,3};

    while(x != X-1 || y != Y) {
        int zzx, zzy;
        zzx=x+zx[up[dir]]; zzy=y+zy[up[dir]];

        if(zzx == X-1 && zzy == Y) break;
        if(zzx < 0 || zzy < 0 || zzx >= R || zzy >= C) {
            dir++;
            continue;
        }

        temp_MAP[zzx][zzy]=MAP[x][y];
        x=zzx; y=zzy;
    }

    x=X; y=Y+1; dir=0;
    while(x != X || y != Y) {
        int zzx, zzy;
        zzx=x+zx[down[dir]]; zzy=y+zy[down[dir]];

        if(zzx == X && zzy == Y) break;
        if(zzx < 0 || zzy < 0 || zzx >= R || zzy >= C) {
            dir++;
            continue;
        }

        temp_MAP[zzx][zzy]=MAP[x][y];
        x=zzx; y=zzy;
    }

    temp_MAP[X-1][Y+1]=temp_MAP[X][Y+1]=0;
    for(i=0 ; i<R ; i++) {
        for(j=0 ; j<C ; j++) {
            MAP[i][j] = temp_MAP[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> R >> C >> T;

    for(i=0 ; i<R ; i++) {
        for(j=0 ; j<C ; j++) {
            cin >> MAP[i][j];

            if(MAP[i][j] == -1) {
                X=i; Y=j;
            }
        }
    }

    for(i=0 ; i<T ; i++) {
        spread();
        active();
    }

    cout << get_sum();
    return 0;
}