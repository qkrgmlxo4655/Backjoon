#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int> P;

priority_queue<P, vector<P>, greater<P>> Q, TQ;


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int MIN=2000;
    int i;
    
    for(i=0 ; i<jobs.size() ; i++) {
        Q.push({jobs[i][1], jobs[i][0]});
        if(jobs[i][0] < MIN) {
            MIN=jobs[i][0];
        }
    }
    
    int current_time=MIN;

    while(!Q.empty()) {
        int x, y;
        x=y=-1;
        while(!Q.empty()) {
            auto [a, b] = Q.top(); Q.pop();
            
            if(b <= current_time) {
                x=a; y=b;
                break;
            } else {
                TQ.push({a, b});
            }
        }
        
        while(!TQ.empty()) {
            Q.push(TQ.top());
            TQ.pop();
        }
        
        if(x==-1 && y==-1) {
            current_time++;
        } else {
            current_time += (x);
            answer += (current_time-y);
        }
    }
    
    return answer/jobs.size();
}