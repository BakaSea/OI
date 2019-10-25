#include<stdio.h>
#include<algorithm>
using namespace std;

struct Activity {
	
	int a, b;
	
	bool operator < (const Activity &A) const {
		if (b != A.b) return b < A.b;
		return a > A.a;
	}
	
} a[1010];

int n, tot, time;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].a, &a[i].b);
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; ++i) {
		if (time <= a[i].a) {
			time = a[i].b;
			tot++;
		}
	}
	printf("%d", tot);
	return 0;
}
