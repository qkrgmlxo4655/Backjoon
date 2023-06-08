#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int zx[8]={-1,-1,-1,0,0,1,1,1},zy[8]={-1,0,1,-1,1,-1,0,1};

int main()
{
    int n,m,k;
    int x,y,age;
    int arr[22][22], soil[22][22], soil_temp[22][22];
    vector<int> v[22][22], v_temp[22][22];
    int i,j,l,t,p;

    scanf("%d%d%d", &n, &m, &k);
    
    for(i=1 ; i<=n ; i++) {
        for(j=1 ; j<=n ; j++) {
            soil[i][j] = 5;
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(i=0 ; i<m ; i++) {
        scanf("%d%d%d", &x, &y, &age);
        v[x][y].push_back(age);
    }
    
    for(t=0 ; t<k ; t++) {
        for(i=1 ; i<=n ; i++) {
            for(j=1 ; j<=n ; j++) {
                soil_temp[i][j]=0;
                for(l=0 ; l<v[i][j].size() ; l++) {
                    if(l==0) { // sort 진행
                        sort(v[i][j].begin(), v[i][j].end());
                    }

                    if(soil[i][j] < v[i][j][l]) { // 영양분 초과
                        soil_temp[i][j] += (v[i][j][l]/2);
                        v[i][j].erase(v[i][j].begin() + l);
                        l--;
                        continue;
                    } else {
                        soil[i][j] -= v[i][j][l];
                        v[i][j][l]++;
                    }
                    
                    if(v[i][j][l] % 5 == 0) {
                        for(p=0 ; p<8 ; p++) {
                            int zzx, zzy;
                            zzx = i+zx[p];
                            zzy = j+zy[p];
                            
                            if(zzx <= 0 || zzy <= 0 || zzx>n || zzy >n) {
                                continue;
                            }
                        
                            v_temp[zzx][zzy].push_back(1);
                        }
                    }
                }
            }
        }
        
        for(i=1 ; i<=n ; i++) {
            for(j=1 ; j<=n ; j++) {
                while(!v_temp[i][j].empty()) {
                    v[i][j].push_back(1);
                    v_temp[i][j].pop_back();
                }
            
                soil[i][j] += soil_temp[i][j];
                soil[i][j] += arr[i][j];
            }
        }
    }
    int sum =0;
    for(i=1 ; i<=n ; i++) {
        for(j=1 ; j<=n ; j++) {
            if(v[i][j].size() > 0 ) {
                int a = v[i][j].size();
                sum += a;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
