#include<stdio.h>
#include<algorithm>
using namespace std;

struct Line {
	int a, b;
	bool operator < (const Line &A) const {
		return b < A.b;
	}
} l[1000010];

int n, p, k;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &l[i].a, &l[i].b);
	sort(l+1, l+n+1);
	for (int i = 1; i <= n; ++i) {
		if (l[i].a >= p) {
			p = l[i].b;
			k++;
		}
	}
	printf("%d", k);
	return 0;
}
