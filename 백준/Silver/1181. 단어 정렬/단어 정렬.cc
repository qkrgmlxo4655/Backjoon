/*
    C++: Hello, World!
*/
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int i;
    vector<string> V[60];
    unordered_set<string> P;

    string S;
    cin >> n;

    for(i=0 ; i<n ; i++) {
        cin >> S;
        if(P.find(S) == 0) {
            P.insert(S);
            V[S.size()].push_back(S);
        }
    }

    for(i=1 ; i<=50 ; i++) {
        sort(V[i].begin(), V[i].end());

        if(V[i].size() > 0) {
            for(int j=0 ; j<V[i].size() ; j++) {
                cout << V[i][j] << "\n";
            }
        }
    }

    return 0;
}
