/*
    C++: Hello, World!
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;

    string cloth, cloth_type;

    cin >> T;

    for(int i=0 ; i<T ; i++) {
        cin >> n;

        int count=0, index;
        vector<string> V[111];
        unordered_map<string, int> cloth_set;

        for(int j=0 ; j<n ; j++) {
            cin >> cloth >> cloth_type;

            if(cloth_set.find(cloth_type) != 0) {
                index = cloth_set[cloth_type];
            } else {
                cloth_set.insert(make_pair(cloth_type, count));
                index = count;
                count++;
            }

            V[index].push_back(cloth);
        }

        int result=1;
        for(int j=0 ; j<count ; j++) {
            result = result * (V[j].size()+1);
        }

        cout << result-1 << "\n";
    }

    return 0;
}
