/*
    C++: Hello, World!
*/
#include <iostream>
#include <deque>
using namespace std;

int size_chk(deque<int> deque_arr) {
    if(!deque_arr.size()) {
        cout << -1 << "\n";
        return 0;
    } else {
        return 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    int x;
    string S;
    cin >> T;
    deque<int> deque_arr;

    for(int i=0 ; i<T ; i++) {
        cin >> S;

        if(S == "push_back") {
            cin >> x;
            deque_arr.push_back(x);
        } else if(S == "push_front") {
            cin >> x;
            deque_arr.push_front(x);
        } else if(S == "front") {
            if(size_chk(deque_arr)) {
                cout << deque_arr.front() << "\n";
            }
        } else if(S == "back") {
            if(size_chk(deque_arr)) {
                cout << deque_arr.back() << "\n";
            }
        } else if(S == "size") {
            cout << deque_arr.size() << "\n";
        } else if(S == "empty") {
            cout << deque_arr.empty() << "\n";
        } else if(S == "pop_front") {
            if(size_chk(deque_arr)) {
                cout << deque_arr.front() << "\n";
                deque_arr.pop_front();
            }
        } else if(S == "pop_back") {
            if(size_chk(deque_arr)) {
                cout << deque_arr.back() << "\n";
                deque_arr.pop_back();
            }
        }
    }

    return 0;
}
