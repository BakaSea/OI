#include<stdio.h>
#include<algorithm>
#include<string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int n, a[100], sum, minn, v[100], next[100];

bool cmp(const int &x, const int &y) {
	return x > y;
}

int dfs(int step, int pre, int rest, int len) {
	if (!step) return 1;
	if (!rest) {
		for (int i = 1; i <= n; ++i) {
			if (!v[i]) {
				v[i] = 1;
				if (dfs(step-1, i, len-a[i], len)) return 1;
				v[i] = 0;
				break;
			}
		}
		if (step > 1) return 0;
		return 1;
	}
	int l = pre+1, r = n;
	while (l < r) {
		int mid = (l+r) >> 1;
		if (a[mid] <= rest) r = mid;
		else l = mid+1;
	}
	for (int i = l; i <= n; ++i) {
		if (!v[i] && rest >= a[i]) {
			v[i] = 1;
			if (dfs(step, i, rest-a[i], len)) return 1;
			v[i] = 0;
			if (rest == a[i]) return 0;
			i = next[i];
			if (i == n) return 0;
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
		minn = max(minn, a[i]);
	}
	sort(a+1, a+n+1, cmp);
	for (int i = 1, p; i <= n; ++i) {
		p = i;
		while (i < n && a[i+1] == a[p]) ++i;
		next[p] = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (!next[i]) next[i] = next[i-1];
	}
	for (int i = minn; i <= sum; ++i) {
		if (!(sum%i)) {
			memset(v, 0, sizeof(v));
			v[1] = 1;
			if (dfs(sum/i, 1, i-a[1], i)) {
				printf("%d", i);
				break;
			}
		}
	}
	return 0;
}
