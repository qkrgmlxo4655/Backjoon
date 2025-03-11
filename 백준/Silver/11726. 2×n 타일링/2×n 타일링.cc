#include <stdio.h>

int main() {
	int arr[1111];
	int n;
	int i,j;
	
	scanf("%d", &n);
	
	arr[0] = 1;
	arr[1] = 2;
	for(i=2 ; i<n ; i++) {
		arr[i] = (arr[i-1] + arr[i-2]) % 10007;
	}
	
	printf("%d", arr[n-1]);
	return 0;
}