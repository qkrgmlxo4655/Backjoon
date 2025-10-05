#include <string>
#include <vector>
#include <iostream>
using namespace std;

string find_sol(int n, int m, int x, int y, int r, int c, int k) {
    int i;
    int xx, yy;
    string ans="";
    xx=x; yy=y;
    
    if(k==0) {
        return "";
    }
    
    cout << xx << " " << yy;
    for(i=0 ; i<k-1 ; i++) {
        if(r-xx>0 && xx+1<=n) {
            xx++;
            ans+='d';
        } else if(c-yy<0 && yy-1>0) {
            yy--;
            ans+='l';
        } else if(c-yy>0 && yy+1<=m) {
            yy++;
            ans+='r';
        } else if(r-xx<0 && xx-1>0) {
            xx--;
            ans+='u';
        }
    }
    
    xx-=r; yy-=c;
    if(xx==1) {
        ans+='u';
    } else if(xx<0) {
        ans+='d';
    } else if(yy==1) {
        ans+='l';
    } else {
        ans+='r';
    }
    
    return ans;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
	int xx, yy;
    int i;
    
    xx=x; yy=y;
    
    int x1=r-x, y1=c-y, sum;
    if(x1<0) x1=-x1;
    if(y1<0) y1=-y1;
    sum=x1+y1;
    
    if(k < sum || ((x1+y1) % 2 != k%2))
        answer = "impossible";
    else {
        if(sum-k == 0) {
            answer += find_sol(n, m, x, y, r, c, k);
        } else {
            int xx, yy;
            int temp = k;
            xx=x; yy=y;

            for(i=0 ; i<k ; i++) {
                int x1=r-xx, y1=c-yy;
                if(x1<0) x1=-x1;
                if(y1<0) y1=-y1;
                
                if(temp == x1+y1) {
                    break;
                }
                
                if(xx+1<=n) {
                    xx++;
                    answer+='d';
                } else if(yy-1>0) {
                    yy--;
                    answer+='l';
                } else if(yy+1<=m) {
                    yy++;
                    answer+='r';
                } else if(xx-1>0) {
                    xx--;
                    answer+='u';
                }
                temp--;
            }
            answer += find_sol(n, m, xx, yy, r, c, k-i);
        }
    }
    return answer;
}
/*
ㅁㅁㅁㅁ
ㅁㅁsㅁ
dㅁㅁㅁ
*/