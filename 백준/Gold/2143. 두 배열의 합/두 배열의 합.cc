#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long T;
    cin >> T;

    int n;
    cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    int m;
    cin >> m;
    vector<long long> B(m);
    for (int i = 0; i < m; i++) cin >> B[i];

    vector<long long> sumA, sumB;

    for (int i = 0; i < n; i++) {
        long long current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += A[j];
            sumA.push_back(current_sum);
        }
    }

    for (int i = 0; i < m; i++) {
        long long current_sum = 0;
        for (int j = i; j < m; j++) {
            current_sum += B[j];
            sumB.push_back(current_sum);
        }
    }

    sort(sumB.begin(), sumB.end());

   

    long long answer = 0;
    
    for (int i = 0; i < sumA.size(); i++) {
        long long target = T - sumA[i];
        
        auto upper = upper_bound(sumB.begin(), sumB.end(), target);
        auto lower = lower_bound(sumB.begin(), sumB.end(), target);
        
        answer += (upper - lower);
    }

    cout << answer << "\n";

    return 0;
}