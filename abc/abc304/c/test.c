#include <stdio.h>

int main()
{
	int i, N, D, X[2001], Y[2001];
	scanf("%d %d", &N, &D);
	for (i = 1; i <= N; i++) scanf("%d %d", &(X[i]), &(Y[i]));
	
	int j, flag[2001] = {}, q[2001], head, tail;
	flag[1] = 1;
	q[0] = 1;
	for (head = 0, tail = 1; head < tail; head++) {
		i = q[head];
		for (j = 1; j <= N; j++) {
			if (flag[j] != 0) continue;
			if ((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) <= D * D) {
				flag[j] = 1;
				q[tail++] = j;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		if (flag[i] == 0) printf("No\n");
		else printf("Yes\n");
	}
	fflush(stdout);
	return 0;
}