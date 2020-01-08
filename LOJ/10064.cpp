#include<stdio.h>
#include<queue>
#include<string.h>
#define MAXN 1010
#define MAXM 500010
#define LL long long
#define MOD 2147483647
using namespace std;

struct Edge {
	int u, v, w, next;
} e[2*MAXM];

int n, m, h[MAXN], d[MAXN], v[MAXN];
LL cnt = 1, tot[MAXN];
priority_queue< pair<int, int> > q;

void addEdge(int u, int v, int w, int num) {
	e[num].u = u;
	e[num].v = v;
	e[num].w = w;
	e[num].next = h[u];
	h[u] = num;
}

void dijkstra() {
	memset(d, 127, sizeof(d));
	d[1] = 0;
	q.push(make_pair(0, 1));
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (!v[u]) {
			v[u] = 1;
			for (int i = h[u]; i; i = e[i].next) {
				if (d[e[i].v] > d[u]+e[i].w) {
					d[e[i].v] = d[u]+e[i].w;
					q.push(make_pair(-d[e[i].v], e[i].v));
				}
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v, w; i <= m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w, i);
		addEdge(v, u, w, i+m);
	}
	dijkstra();
	for (int u = 1; u <= n; ++u) {
		for (int i = h[u]; i; i = e[i].next) {
			if (d[e[i].v] == d[u]+e[i].w) tot[e[i].v]++;
		}
	}
	for (int i = 2; i <= n; ++i) cnt = (cnt*tot[i])%MOD;
	printf("%lld", cnt);
	return 0;
}
