/*
    C++: Hello, World!
*/
#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> arr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    int i;
    int x;

    cin >> n;

    for(i=0 ; i<n ; i++) {
        cin >> x;
        arr.insert(x);
    }

    cin >> m;

    for(i=0 ; i<m ; i++) {
        cin >> x;

        if(arr.find(x) != 0) 
            cout << 1 << "\n";
        else {
            cout << 0 << "\n";
        }
    }

    return 0;
}
