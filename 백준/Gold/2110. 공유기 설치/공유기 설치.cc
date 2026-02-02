/*
    C++: Hello, World!
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    int N, C;
    int x, result;

    vector<int> V;

    cin >> N >> C;
    
    for(i=0 ; i<N ; i++) {
        cin >> x;
        V.push_back(x);
    }

    sort(V.begin(), V.end());

    int l,r,mid;

    l=1; r=V[N-1] - V[0];

    while(l<=r) {
        mid = (l+r)/2;
        int cnt=1;
        int last = V[0];

        for(i=1 ; i<N ; i++) {
            if(V[i] - last >= mid) {
                last = V[i];
                cnt++;
            }
        }

        if(cnt >= C) {
            result = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout << result;
    return 0;
}
