#include<stdio.h>
#include<algorithm>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

struct Product {
	int a, b, idx;
} p[1010];

int n, fi, ta, tb;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i].a);
		p[i].idx = i;
	}
	for (int i = 1; i <= n; ++i) scanf("%d", &p[i].b);
	for (int i = 1, x; i <= n; ++i) {
		x = i;
		for (int j = i+1; j <= n; ++j) {
			if (p[x].a+max(p[x].b, p[j].a)+p[j].b > p[j].a+max(p[j].b, p[x].a)+p[x].b) {
				x = j;
			}
		}
		swap(p[x], p[i]);
	}
	for (int i = 1; i <= n; ++i) {
		ta += p[i].a;
		tb = max(ta, tb)+p[i].b;
	}
	printf("%d\n", tb);
	for (int i = 1; i < n; ++i) printf("%d ", p[i].idx);
	printf("%d", p[n].idx);
	return 0;
}
