
// 10
// 10 -4 3 1 5 6 -35 12 21 -1

#include <iostream>
#include <algorithm>
#define M 111111

using namespace std;

int main()
{
    int n;
    int arr[M], dp[M];
    int res;

    cin >> n;
    
    for(int i=1 ; i<=n ; i++) {
        cin >> arr[i];
    }
    
    res = dp[1] = arr[1];
    
    for(int i=2 ; i<=n ; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        res = max(res, dp[i]);
    }
    
    cout << res;

    return 0;
}