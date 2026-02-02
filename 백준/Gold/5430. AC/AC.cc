/*
    C++: Hello, World!
*/
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    int n;
    string P, S;
    cin >> T;

    for(int i=0 ; i<T ; i++) {
        deque<int> deque_arr;
        bool is_reverse = false, is_break = false;

        cin >> P;
        cin >> n;
        cin >> S;

        if(n != 0) { 
            string temp;
            for(int j=1 ; j<S.size() ; j++) {
                if(S[j] == ',') {
                    deque_arr.push_back(stoi(temp));
                    temp = "";
                    continue;
                }

                temp += S[j];
            }
            deque_arr.push_back(stoi(temp));
        }

        for(int j=0 ; j<P.size() ; j++) {
            if(P[j] == 'R') {
                is_reverse = !is_reverse;
            } else if(P[j] == 'D') {
                if(deque_arr.size() != 0) {
                    if(is_reverse) {
                        deque_arr.pop_back();
                    } else {
                        deque_arr.pop_front();
                    }
                } else {
                    cout << "error" << "\n";
                    is_break = true;
                    break;
                }
            }
        }

        if(!is_break) {
            cout << "[";
            while(!deque_arr.empty()) {
                if(is_reverse) {
                    cout << deque_arr.back();
                    deque_arr.pop_back();
                } else {
                    cout << deque_arr.front();
                    deque_arr.pop_front();
                }

                if(!deque_arr.empty()) {
                    cout << ",";
                }
            }
            cout << "]" << "\n";
        }
    }

    return 0;
}
