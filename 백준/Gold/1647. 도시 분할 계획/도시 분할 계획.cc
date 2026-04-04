#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> P;
int via[111111];
int N, M;

int find(int x) {
    if(via[x] == x) {
        return via[x];
    }
    return via[x] = find(via[x]);
    
}

void mer(int A, int B) {
    int a=find(A);
    int b=find(B);

    if(a != b) {
        via[a]=b;
    }
}

int main() {
    // 입출력 속도 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    int ans=0;
    cin >> N >> M;
    
    priority_queue<P, vector<P>, greater<P>> Q;

    for(i=1 ; i<=N ; i++) {
        via[i]=i;
    }

    for(i=0 ; i<M ; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        Q.push({C, A, B});
    }

    while(!Q.empty()) {
        auto [C, A, B] = Q.top(); Q.pop();

        if(N==2) {
            break;
        }

        if(find(A) == find(B)) {
            continue;
        } else {
            mer(A, B);
            N--;
            ans+=C;
        }
    }

    cout << ans;
    return 0;
}