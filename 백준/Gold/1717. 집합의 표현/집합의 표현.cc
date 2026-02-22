/*
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1
*/

#include <iostream>

using namespace std;

int U[1111111];

int search_parent(int x) {
    if(U[x] == x) return x;

    return U[x] = search_parent(U[x]);
}

void union_group(int a, int b) {
    int p_a, p_b;

    p_a=search_parent(a); p_b=search_parent(b);

    if(p_a != p_b) {
        U[p_b] = U[p_a];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    int n, m;
    int qus, a, b;

    cin >> n >> m;

    for(i=0 ; i<=n ; i++) {
        U[i] = i;
    }

    for(i=0 ; i<m ; i++) {
        cin >> qus >> a >> b;
        
        if(qus == 0) {          //  합집합  
            union_group(a, b);
        } else if(qus == 1) {   //  확인
            if(search_parent(a) == search_parent(b)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
}