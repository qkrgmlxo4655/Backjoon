
// 6
// 6
// 10
// 13
// 9
// 8
// 1

#include <iostream>
#include <algorithm>
#define M 11111

using namespace std;

int main()
{
    int n;
    int arr[M], dp[M];

    cin >> n;
    
    for(int i=1 ; i<=n ; i++) {
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    
    if(n>=2) {
        dp[2] = arr[1] + arr[2];
    }
        
    for(int i=3 ; i<=n ; i++) {
        dp[i] = max({
            dp[i-1],
            dp[i-2]+arr[i],
            dp[i-3]+arr[i-1]+arr[i]
        });
    }
    
    cout << dp[n] << endl;

    return 0;
}