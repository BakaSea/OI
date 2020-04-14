#include <stdio.h>
#include <algorithm>
#include <iostream>
#define MAXN 100010
#define INF 1e9
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

inline int read() {
	int ch = getchar(), x = 0, f = 1;
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*f;
}

struct Node {
	int lc, rc, val, size, w, rnd;
	Node() : lc(0), rc(0), val(0), size(0), w(0), rnd(0) { }
	Node(int val) : lc(0), rc(0), val(val), size(1), w(1), rnd(rand()) { }
} t[MAXN];

int n, cnt, rt;

void pushup(int x) {
	t[x].size = t[t[x].lc].size+t[t[x].rc].size+t[x].w;
}

void lrotate(int &k) {
	int d = t[k].rc;
	t[k].rc = t[d].lc;
	t[d].lc = k;
	pushup(k);
	pushup(d);
	k = d;
}

void rrotate(int &k) {
	int d = t[k].lc;
	t[k].lc = t[d].rc;
	t[d].rc = k;
	pushup(k);
	pushup(d);
	k = d;
}

void insert(int &k, int val) {
	if (!k) {
		k = ++cnt;
		t[k] = Node(val);
		return;
	}
	t[k].size++;
	if (val == t[k].val) t[k].w++;
	else if (val < t[k].val) {
		insert(t[k].lc, val);
		if (t[t[k].lc].rnd < t[k].rnd) rrotate(k);
	} else {
		insert(t[k].rc, val);
		if (t[t[k].rc].rnd < t[k].rnd) lrotate(k);
	}
}

int erase(int &k, int val) {
	if (!k) return 0;
	if (t[k].val == val) {
		if (t[k].w > 1) {
			t[k].w--;
			t[k].size--;
		} else {
			if (!t[k].lc || !t[k].rc) k = t[k].lc+t[k].rc;
			else {
				if (t[t[k].lc].rnd < t[t[k].rc].rnd) {
					rrotate(k);
					erase(k, val);
				} else {
					lrotate(k);
					erase(k, val);
				}
			}
		}
		return 1;
	} else if (val < t[k].val) {
		if (erase(t[k].lc, val)) {
			t[k].size--;
			return 1;
		} else return 0;
	} else {
		if (erase(t[k].rc, val)) {
			t[k].size--;
			return 1;
		} else return 0;
	}
}

int rank(int k, int x) {
	if (!k) return 0;
	if (t[k].val == x) return t[t[k].lc].size+1;
	if (t[k].val < x) return t[t[k].lc].size+t[k].w+rank(t[k].rc, x);
	return rank(t[k].lc, x);
}

int number(int k, int x) {
	if (!k) return 0;
	if (x <= t[t[k].lc].size) return number(t[k].lc, x);
	if (x > t[t[k].lc].size+t[k].w) return number(t[k].rc, x-t[t[k].lc].size-t[k].w);
	return t[k].val;
}

int pre(int k, int x) {
	if (!k) return -INF;
	if (x <= t[k].val) return pre(t[k].lc, x);
	int d = pre(t[k].rc, x);
	return max(t[k].val, d);
}

int sub(int k, int x) {
	if (!k) return INF;
	if (x >= t[k].val) return sub(t[k].rc, x);
	int d = sub(t[k].lc, x);
	return min(t[k].val, d);
}

int main() {
	srand(233);
	n = read();
	for (int i = 1, opt, x; i <= n; ++i) {
		opt = read(), x = read();
		if (opt == 1) insert(rt, x);
		else if (opt == 2) erase(rt, x);
		else if (opt == 3) printf("%d\n", rank(rt, x));
		else if (opt == 4) printf("%d\n", number(rt, x));
		else if (opt == 5) printf("%d\n", pre(rt, x));
		else if (opt == 6) printf("%d\n", sub(rt, x));
	}
	return 0;
}
