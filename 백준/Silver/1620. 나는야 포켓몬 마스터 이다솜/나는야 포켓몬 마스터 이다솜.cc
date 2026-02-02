/*
    C++: Hello, World!
*/
#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    int i;
    string S;

    unordered_map<string, int> index;
    string name[111111];

    cin >> n >> m;

    for(i=0 ; i<n ; i++) {
        cin >> S;

        index.insert(make_pair(S, i));
        name[i]=S;
    }

    for(i=0 ; i<m ; i++) {
        cin >> S;

        if(isdigit(S[0]) != 0) {
            cout << name[stoi(S)-1] << "\n";
        } else {
            cout << index[S]+1 << "\n";
        }
    }
    return 0;
}