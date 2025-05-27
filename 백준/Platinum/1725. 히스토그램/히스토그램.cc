// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
#include <algorithm>
#define M 111111
using namespace std;

int h[M];
stack<int> idx;

int main() {
    int n;
    long long int sum;
    cin >> n;

    for(int i=0 ; i<n ; ++i) {
        cin >> h[i];
    }

    sum=0;
    for(int i=0 ; i<n ; ++i) {
        while(!idx.empty() && h[idx.top()] > h[i]) {
            long long int height = h[idx.top()];
            idx.pop();

            long long int width = idx.empty() ? i : (i - idx.top()-1);

            sum = max(sum, width * height);
        }

        idx.push(i);
    }

    while(!idx.empty()) {

        long long int height = h[idx.top()];
        idx.pop();

        long long int width = idx.empty() ? n : (n - idx.top()-1);

        sum = max(sum, width * height);
    }

    cout << sum << endl;
    
    

    return 0;
}