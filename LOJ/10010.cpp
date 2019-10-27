#include<stdio.h>
#include<algorithm>
#include<math.h>
#define MAXN 1000010
using namespace std;

int n;
long long sum, c[MAXN], a[MAXN], avg, tot;

int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	avg = sum/n;
	for (int i = 2; i <= n; ++i) c[i] = c[i-1]+a[i]-avg;
	int mid = n >> 1 | 1;
	nth_element(c+1, c+mid, c+n+1);
	for (int i = 1; i <= n; ++i) tot += abs(c[i]-c[mid]);
	printf("%lld", tot);
	return 0;
}
