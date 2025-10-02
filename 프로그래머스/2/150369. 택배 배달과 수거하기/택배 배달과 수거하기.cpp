#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int flag_d, flag_p, t_d, t_p;
    int cap_d, cap_p;
    int i, j;
    
    flag_d=flag_p=n-1;
    while(flag_d >= 0 || flag_p >= 0) {
        cap_d=cap_p=cap;
        t_d=t_p=-1;
        
        for(i=flag_d ; i>=0 ; i--) {
            if(deliveries[i] == 0) {
               continue;
            } else {
                if(t_d == -1)
                    t_d = i;

                cap_d -= deliveries[i];
            }

            if(cap_d <= 0) {
                deliveries[i] = -cap_d;
                break;
            } else {
                deliveries[i] = 0;
            }
        }

        for(j=flag_p ; j>=0 ; j--) {
            if(pickups[j] == 0) {
                continue;
            } else {
                if(t_p==-1)
                    t_p = j;

                cap_p -= pickups[j];
            }

            if(cap_p <= 0) {
                pickups[j] = -cap_p;
                break;
            } else {
                pickups[j] = 0;
            }
        }
        
        if(t_p > t_d) {
            answer += ((t_p+1)*2);
        } else {
            answer += ((t_d+1)*2);
        }
        
        flag_d = i;
        flag_p = j;
    }
    return answer;
}