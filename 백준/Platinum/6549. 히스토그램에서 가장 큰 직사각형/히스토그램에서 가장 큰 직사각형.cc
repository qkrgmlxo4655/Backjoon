#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

ll getMaxArea(const vector<ll>& h) {
    stack<int> s;
    ll maxArea = 0;
    int n = h.size();

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && h[s.top()] > h[i]) {
            ll height = h[s.top()];
            s.pop();
            ll width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }

    // 남은 막대 처리
    while (!s.empty()) {
        ll height = h[s.top()];
        s.pop();
        ll width = s.empty() ? n : n - s.top() - 1;
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<ll> h(n);
        for (int i = 0; i < n; ++i) cin >> h[i];

        cout << getMaxArea(h) << '\n';
    }

    return 0;
}
