/*
    C++: Hello, World!
*/
#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    char x;
    unordered_map<char, Node*> P;
    string data;

    ~Node() {
        for (auto it : P) delete it.second;
    }
};

bool add_word(string S, Node *head) {
    int i;
    Node *Temphead = head;
    bool flag = false;

    for(i=0 ; i<S.size() ; i++) {
        if(Temphead->P.find(S[i]) == Temphead->P.end()) {
            Node *temp = new Node();
            temp->x = S[i];
            Temphead->P.insert(make_pair(S[i], temp));
            Temphead = Temphead->P[S[i]];
        } else {
            Temphead = Temphead->P[S[i]];
        }

        if(Temphead->data != "") {
            flag=true;
        }

        if(i == S.size()-1) {
            Temphead->data = S;
        }
    }

    if(!Temphead->P.empty()) flag = true;

    return flag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N;
    int i, j;
    string S;

    cin >> T;

    for(i=0 ; i<T ; i++) {
        bool flag = false;
        Node *head = new Node();
        cin >> N;

        for(j=0 ; j<N ; j++) {
            cin >> S;
            if(add_word(S, head)) {
                flag = true;
            }
        }

        if(flag) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }

        delete head;
    }

    return 0;
}
