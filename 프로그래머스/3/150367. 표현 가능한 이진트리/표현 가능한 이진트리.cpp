#include <string>
#include <vector>
#include <iostream>

using namespace std;
int flag;

void ans(int left, int right, vector<int> arr) {
	int mid = (left+right)/2;
    
    if(flag == -1 || left >= right) return;
    
    if(arr[mid] == 1) {
        ans(left, mid-1, arr);
        ans(mid+1, right, arr);
    } else {
        if( arr[(left + mid-1)/2] == 0) {
         	ans(left, mid-1, arr);   
        } else {
            flag=-1;
            return;
        }
        if( arr[(mid+1 + right)/2] == 0) {
       	 	ans(mid+1, right, arr);
        } else {
            flag=-1;
            return;
        }
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    int i, j;
    long long t;
    
   	for(i=0 ; i<numbers.size() ; i++) {
        long long num = numbers[i];
        flag=0;
    	vector<int> arr;
        
        while(num!=0) {
            arr.push_back(num%2);
            num/=2;
        }

        for(t=1 ; t<=arr.size() ; t*=2);
        
        if(numbers[i] == t) {
            answer.push_back(1);
            continue;
        }
        for(j=arr.size() ; j<t-1 ; j++) {
            arr.push_back(0);
        }
        
        ans(0, arr.size()-1, arr);
        if(flag == -1) {
            answer.push_back(0);
        } else {
	        answer.push_back(1);
        }
    }
    return answer;
}



    