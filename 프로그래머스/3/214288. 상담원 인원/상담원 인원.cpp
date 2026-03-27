#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
// k = 상담유형, n = 멘토 수, reqs = 요청
int MIN=0x7fffffff;

void simul(vector<int> C, vector<vector<int>> reqs) {
    int i;
    int total=0;
    priority_queue<int, vector<int>, greater<int>> q[5];
    
    for(i=0 ; i<reqs.size() ; i++) {
        int x = reqs[i][2]-1;
        int s = reqs[i][0] + reqs[i][1];
        
        if(q[x].size() < C[x]+1) {
	        q[x].push(s);        
        } else {
            while(!q[x].empty()) {
                if(q[x].top() <= reqs[i][0]) {
                    q[x].pop();
                } else {
                    break;
                }
            }
            
            if(q[x].size() < C[x]+1) {
	        	q[x].push(s);        
        	} else {
                int temp = q[x].top() + reqs[i][1];
                total = total + (temp-s);
                q[x].push(temp);
                q[x].pop();
            }
        }
    }
    
    if(total < MIN) {
        MIN = total;
    }
}

void make_com(int k, int p, vector<int> C, int idx, vector<vector<int>> reqs, int depth) {
	int i;
    
    if(depth == p) {
    	simul(C, reqs);
        return;
    }
    
    for(i=idx ; i<k ; i++) {
        C[i]++;
    	make_com(k, p, C, i, reqs, depth+1);
        C[i]--;
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int i;
    int p=n-k;
    
    vector<int> C(k, 0);    
    make_com(k, p, C, 0, reqs, 0);
    
    return MIN;
}
// 70 115 100 80/115/100
/*
10 60 1				1 70
15 100 3			3 115
20 30 1				1 50
30 50 3				3 80
50 40 1				1 90
60 30 2				2 90
65 30 1				1 100 // 5
70 100 2			2 190 // 20
    
25
    
    
5 55 2				2 60
10 90 2				2 100
20 40 2				2 100 // 40
50 45 2				2 145 // 50
100 50 2			2 150
*/

