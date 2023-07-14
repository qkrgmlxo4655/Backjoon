#include <stdio.h>
#define M 255000

int main() {
	int n, x;
	int i;
	int arr[M];
	int sum=0, max, count = 1;

	scanf("%d%d", &n, &x);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);

		if (i < x) {
			sum += arr[i];
		}
	}

	max = sum;

	for (i = x; i < n; i++) {
		sum -= arr[i-x];					// 맨 앞 값을 빼준다.
		sum += arr[i];						// 맨 뒤 값을 더해준다.

		if (max == sum) {
			count++;
		}

		else if (max < sum) {
			max = sum;
			count = 1;
		}
	}

	if (max == 0) {
		printf("SAD");
	} else {
		printf("%d\n%d", max, count);
	}
	return 0;
}