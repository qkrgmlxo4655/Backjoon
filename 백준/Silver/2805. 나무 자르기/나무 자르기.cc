#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
long long arr[1111111];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;

    cin >> N >> M;

    for(i=0 ; i<N ; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    long long L, R, MID, l_idx, r_idx, m_idx, ans;
    L=0; R=arr[N-1];

    while(L <= R) {
        MID = (L+R)/2;
        l_idx=0; r_idx=N-1;
        
        while(l_idx <= r_idx) {
            m_idx = (l_idx + r_idx)/2;

            if(arr[m_idx] >= MID) {
                r_idx=m_idx-1;
            } else {
                l_idx=m_idx+1;
            }
        }

        if(l_idx > r_idx) {
            m_idx = r_idx-1;
        } else {
            m_idx = l_idx-1;
        }

        long long sum=0;
        for(i=m_idx ; i<N ; i++) {
            if(arr[i] - MID > 0) {
                sum += (arr[i]-MID);
            }
        }

        if(sum >= M) {
            ans = MID;
            L = MID+1;
        } else {
            R = MID-1;
        }
    }

    cout << ans;
    return 0;
}