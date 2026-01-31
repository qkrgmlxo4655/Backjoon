/*
    C++: Hello, World!
*/
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

bool com(string a, string b) {
    return a>b;
}

int main()
{
    int n;
    string name, method;
    unordered_set<string> s;

    cin >> n;

    for(int i=0 ; i<n ; i++) {
        cin >> name >> method;
        
        if(method == "enter") {
            s.insert(name);
        } else {
            s.erase(name);
        }
    }
    
    vector<string> result(s.begin(), s.end());
    sort(result.begin(), result.end(), com);

    for(int i=0 ; i<result.size() ; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
