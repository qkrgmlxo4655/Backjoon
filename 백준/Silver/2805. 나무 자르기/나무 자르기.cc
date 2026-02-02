/*
    C++: Hello, World!
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long int m;
    int x;
    int i;
    vector<int> V;
    cin >> n >> m;

    for(i=0 ; i<n ; i++) {
        cin >> x;
        V.push_back(x);
    }

    sort(V.begin(), V.end());

    long long int l, r, mid, l_idx, r_idx, mid_idx;
    long long int sum=0;
    int result;

    l=0; r=V[n-1];

    while(l <= r) {
        mid = (l+r)/2;
        l_idx=0; r_idx=n-1;

        while(l_idx <= r_idx) {
            mid_idx = (l_idx + r_idx)/2;

            if(V[mid_idx] >= mid) {
                r_idx = mid_idx-1;
            } else {
                l_idx = mid_idx+1;
            }
        }
        
        sum=0;
        for(i=0 ; i<n ; i++) {
            if(V[i] - mid > 0) {
                sum += (V[i] - mid);
            }
        }
        // cout << l << " " << mid << " " << r << " " << sum << endl;
        if(sum >= m) {
            result = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout << result << endl;

    return 0;
}
