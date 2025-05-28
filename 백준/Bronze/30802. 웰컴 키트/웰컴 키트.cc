#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[6], sum=0;
    
    cin >> n;
    
    for(int i=0 ; i<6 ; i++) {
        cin >> arr[i];
    }
    
    int x,y;
    
    cin >> x >> y;
    
    for(int i=0 ; i<6 ; i++) {
        if(arr[i] == 0) continue;
        sum += arr[i]/x;
        
        if(arr[i]%x !=0 ) sum++;
    }
    cout << sum << endl << n/y << " " << n%y;
    return 0;
}