#include <stdio.h>

int is_change(int A, int B) {
	if(A == -1 || A>B+1) {
		return 1;
	}
	return 0;
}

int main() {
	int arr[1111111];
	int n;
	int i,j;
	
	scanf("%d", &n);
	
	for(i=0 ; i<=n ; i++) arr[i]=-1;
	arr[1] = 0;
	
	for(j=0 ; j<=n ; j++) {
		if(arr[n] != -1) break;
		for(i=n ; i>=1 ; i--)  {
		
			if(arr[i] != -1) {
				if(i+1 <=n && is_change(arr[i+1], arr[i])) {
					arr[i+1] = arr[i]+1;
				}
				if(i*2 <= n && is_change(arr[i*2], arr[i])) {
					arr[i*2] = arr[i]+1;
				}
				if(i*3 <= n && is_change(arr[i*3], arr[i])) {
					arr[i*3] = arr[i]+1;
				}
			}
		}
	}
	
	printf("%d", arr[n]);
	return 0;
}