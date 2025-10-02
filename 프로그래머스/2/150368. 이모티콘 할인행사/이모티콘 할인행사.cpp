#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> e;
vector<vector<int>> u;
vector<int> answer;
int con_rate[10], rate[4]={10,20,30,40};

void a(int n) {
   	int i,j;
    
    if(n == e.size()) {
        int user, value;
        user=value=0;
        
		for(i=0 ; i<u.size() ; i++) {
            int sum=0;
            for(j=0 ; j<e.size() ; j++) {
                if(rate[con_rate[j]] >= u[i][0]) { // buy
					sum = sum + (e[j]/100 * (100-rate[con_rate[j]]) ); 
                }
                if(sum >= u[i][1]) {
                    user++;
                    sum=0;
                    break;
                }
            }
           	value+=sum;
        }

        if(answer[0] < user || (answer[0] == user && answer[1] < value)) {
            answer[0] = user;
            answer[1] = value;
        }
    } else {
        for(i=0 ; i<4 ; i++) {
            con_rate[n]=i;
            a(n+1);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
   	
    u = users;
    e = emoticons;
    answer.push_back(0); answer.push_back(0);
    
    a(0);
    return answer;
}