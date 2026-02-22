/*
    C++: Hello, World!
*/
#include <iostream>

using namespace std;
int arr[3] = {-1, 0, 1};

char CLICK(char p) {
    if(p=='0') {
        return '1';
    } else {
        return '0';
    }
}

int main()
{
    int N;
    int i, j;
    int ON_CNT, OFF_CNT;
    string S_ON, S_OFF, T;

    cin >> N;
    cin >> S_OFF >> T;

    S_ON = S_OFF;
    ON_CNT=OFF_CNT=0;
    
    S_ON[0] = CLICK(S_ON[0]);
    S_ON[1] = CLICK(S_ON[1]);
    ON_CNT++;

    for(i=1 ; i<N ; i++) {
        if(S_ON[i-1] != T[i-1]) {
            for(j=0 ; j<3 ; j++) {
                int t=i+arr[j];

                if(t>=N) continue;
                S_ON[t] = CLICK(S_ON[t]);
            }
            ON_CNT++;
        }

        if(S_OFF[i-1] != T[i-1]) {
            for(j=0 ; j<3 ; j++) {
                int t=i+arr[j];

                if(t>=N) continue;
                S_OFF[t] = CLICK(S_OFF[t]);
            }
            OFF_CNT++;
        }
    }

    if(S_ON == T && S_OFF == T) {
        cout << (ON_CNT > OFF_CNT ? OFF_CNT : ON_CNT);
    }
    else if(S_ON == T) {
        cout << ON_CNT;
    } else if(S_OFF == T) {
        cout << OFF_CNT;
    } else {
        cout << -1;
    }

    return 0;
}
