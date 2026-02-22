#include <iostream>
#include <unordered_map>
using namespace std;

/*
5 2
map
set
dijkstra
floyd
os
map,dijkstra
map,floyd
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    int i, j;
    int ans;
    string S;
    unordered_map<string, int> map;
    
    cin >> N >> M;
    ans = N;

    for(i=0 ; i<N ; i++) {
        cin >> S;
        map.insert(make_pair(S, 0));
    }

    for(i=0 ; i<M ; i++) {
        string T="";
        cin >> S;
        for(j=0 ; j<S.size() ; j++) {
            if(S[j] == ',') {
                if(map.find(T) != map.end()) {
                    if(map[T] == 0) {
                        ans--;
                        map[T]=1;
                    }
                }
                T="";
                continue;
            }
            T+=S[j];
        }

        if(map.find(T) != map.end()) {
            if(map[T] == 0) {
                ans--;
                map[T]=1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}