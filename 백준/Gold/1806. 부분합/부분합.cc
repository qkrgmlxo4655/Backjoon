#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int i;
    int N, S;
    int start, end;
    int sum, MIN=0x7fffffff;
    cin >> N >> S;

    vector<int> A(N);

    for(i=0 ; i<N ; i++) {
        cin >> A[i];
    }

    sum = start = end = 0;

    while(start<=N && end<=N) {
        if(sum >= S) {
            MIN = min(MIN, (end-start));
            sum -= A[start];
            start++;
        } else {
            sum+=A[end];
            end++;
        }
    }

    if(MIN == 0x7fffffff) {
        cout << 0;
    } else {
        cout << MIN;
    }
    return 0;
}