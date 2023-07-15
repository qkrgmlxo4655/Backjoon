#include <stdio.h>
#define M 111111

int main() {
	int n;
	int i;
	int dis[M], val[M];
	int t;
	long long int sum = 0, dis_temp = 0;

	scanf("%d", &n);

	for (i = 0; i < n - 1; i++) {
		scanf("%d", &dis[i]);
	}

	for (i = 0; i < n; i++) {
		scanf("%d", &val[i]);
	}

	t = val[0];
	dis_temp = dis[0];

	for (i = 1; i < n-1 ; i++) {
		if (t > val[i]) {
			sum += dis_temp * t;
			t = val[i];
			dis_temp = dis[i];
		} else {
			dis_temp += dis[i];
		}
	}

	printf("%lld", sum + dis_temp*t);
	return 0;
}