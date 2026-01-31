/*
    C++: Hello, World!
*/
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int value;
    node *prev, *next;
};

int main()
{
    int n, m;
    int i, j;
    vector<int> dab;

    node *link = new node, *head = new node;
    link->value = 1;
    link->prev = link->next = NULL;
    head->next = link;

    cin >> n >> m;

    for(i=2 ; i<=n ; i++) {
        node* temp = new node;
        temp->value = i;
        temp->prev = link;
        temp->next = NULL;

        link->next = temp;
        link = temp;
    }

    head->next->prev = link;
    link->next = head->next;

    for(i=0 ; i<n ; i++) {
        for(j=0 ; j<m ; j++) {
            head = head->next;
        }

        dab.push_back(head->value);

        // 현재 값 link 끊기
        head->prev->next = head->next;
        head->next->prev = head->prev;
    }
    
    cout << "<";
    for(i=0 ; i<dab.size() ; i++) {
        cout << dab[i];
        if(i == dab.size()-1) continue;
        cout << ", ";
    }
    cout << ">";

    return 0;
}
