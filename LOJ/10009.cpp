#include<stdio.h>
#include<queue>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

struct Fish {
	int a, d;
	bool operator < (const Fish &A) const {
		return a < A.a;
	}
};

int n, H, t[110], d[110], s[110], a[110], sum;

int main() {
	scanf("%d%d", &n, &H);
	H *= 60;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
	for (int i = 1; i < n; ++i) {
		scanf("%d", &t[i]);
		s[i] = s[i-1]+t[i];
	}
	for (int i = 1, time, xs; i <= n; ++i) {
		time = (H-s[i-1]*5)/5;
		if (time < 0) break;
		priority_queue<Fish> q;
		while (!q.empty()) q.pop();
		for (int j = 1; j <= i; ++j) {
			Fish x;
			x.a = a[j];
			x.d = d[j];
			q.push(x);
		}
		xs = 0;
		while (!q.empty() && time) {
			time--;
			Fish x = q.top();
			q.pop();
			if (!x.a) break;
			xs += x.a;
			x.a = max(x.a-x.d, 0);
			q.push(x);
		}
		sum = max(sum, xs);
	}
	printf("%d", sum);
	return 0;
}
