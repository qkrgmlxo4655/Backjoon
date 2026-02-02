/*
    C++: Hello, World!
*/
#include <iostream>
#include <queue>
#include <vector>
#define M 111
using namespace std;

vector<int> arr[M];
int chk[M];

int warm_spread(int num) {
    int i;
    int count=0;
    
    queue<int> Q;
    Q.push(num); chk[num]=1;

    while(!Q.empty()) {
        int dis = Q.front();
        Q.pop();
        count++;

        for(i=0 ; i<arr[dis].size() ; i++) {
            int t = arr[dis][i];
            if(chk[t] == 0) {
                chk[t]=1;
                Q.push(t);
            }
        }
    }

    return count-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    int n, m;
    int x, y;

    cin >> n >> m;

    for(i=0 ; i<m ; i++) {
        cin >> x >> y;

        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    cout << warm_spread(1);
    return 0;
}
