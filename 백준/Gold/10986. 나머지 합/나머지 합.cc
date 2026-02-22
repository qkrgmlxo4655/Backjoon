/*
    C++: Hello, World!
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i;
    int N, M;

    cin >> N >> M;
    int num;
    vector<long long> count(M);

    long long SUM, ans;

    SUM=ans=0;

    for(i=0 ; i<N ; i++) {
        cin >> num;

        SUM += num;

        if(SUM % M == 0) {
            ans++;
        }

        count[SUM%M]++;
    }

    for(i=0 ; i<M ; i++) {
        if(count[i] >=2) {
            long long p = count[i];
            ans = ans + ((p * (p-1))/2);
        }
    }

    cout << ans;
    return 0;
}
