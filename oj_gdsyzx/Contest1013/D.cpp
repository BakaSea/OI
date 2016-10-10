#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;

const int maxn = 35, inf = 0x3f3f3f3f;

struct node {
	int x, y, k;
};

int n, m, q, ex, ey, tx, ty, sx, sy,
	map[maxn][maxn], movee[maxn][maxn][5][5], step[maxn][maxn],
	vis[maxn][maxn], step2[maxn][maxn][5], vis2[maxn][maxn][5];

node change(node a, int b) {
	node t = a;
	if (b == 1) t.x--;
	if (b == 2) t.x++;
	if (b == 3) t.y--;
	if (b == 4) t.y++;
	return t;
}

int cover(int k) {
	if (k == 1) return 2;
	if (k == 2) return 1;
	if (k == 3) return 4;
	if (k == 4) return 3;
}

int bfs(node s, node t) {
	if (!map[s.x][s.y] || !map[t.x][t.y]) return inf;
	memset(step, 0x3f, sizeof(map));
	memset(vis, 0, sizeof(vis));
	queue<node> q;
	q.push(s);
	step[s.x][s.y] = 0;
	vis[s.x][s.y] = 1;
	node u, v;
	while (!q.empty()) {
		u = q.front();
		for (int i = 1; i <= 4; i++) {
			v = change(u, i);
			if (!vis[v.x][v.y] && map[v.x][v.y]) {
				vis[v.x][v.y] = 1;
				q.push(v);
				step[v.x][v.y] = step[u.x][u.y]+1;
			}
		}
		q.pop();
	}
	return step[t.x][t.y];
}

int spfa(node s, node t) {
	if (s.x == t.x && s.y == t.y) return 0;
	memset(step2, 0x3f, sizeof(step2));
	memset(vis2, 0, sizeof(vis2));
	if (!map[s.x][s.y] && !map[t.x][t.y]) return inf;
	map[s.x][s.y] = 0;
	queue<node> q;
	for (int i = 1; i <= 4; i++) {
		node t = (node) {
			s.x, s.y, i
		};
		q.push(t);
		vis2[s.x][s.y][i] = 1;
		step2[s.x][s.y][i] = bfs((node) {
			ex, ey
		}, change(s, i));
	}
	map[s.x][s.y] = 1;
	while (!q.empty()) {
		node u = q.front();
		vis2[u.x][u.y][u.k] = 0;
		for (int i = 1; i <= 4; i++) {
			node v = change(u, i);
			v.k = cover(i);
			if (step2[u.x][u.y][u.k]+movee[u.x][u.y][u.k][i] < step2[v.x][v.y][v.k]) {
				step2[v.x][v.y][v.k] = step2[u.x][u.y][u.k]+movee[u.x][u.y][u.k][i];
				if (!vis2[v.x][v.y][v.k]) {
					q.push(v);
					vis2[v.x][v.y][v.k] = 1;
				}
			}
		}
		q.pop();
	}
	int ans = inf;
	for (int i = 1; i <= 4; i++) ans = min(ans, step2[t.x][t.y][i]);
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	memset(movee, 0x3f, sizeof(movee));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!map[i][j]) continue;
			map[i][j] = 0;
			for (int k = 1; k <= 4; k++) {
				for (int h = 1; h <= 4; h++) {
					if (h < k) {
						movee[i][j][k][h] = movee[i][j][h][k];
						continue;
					}
					node t1 = change((node) {
						i, j
					}, k), t2 = change((node) {
						i, j
					}, h);
					if (!map[t1.x][t1.y] || !map[t2.x][t2.y]) continue;
					movee[i][j][k][h] = bfs(t1, t2)+1;
				}
			}
			map[i][j] = 1;
		}
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d%d%d%d%d%d", &ex, &ey, &sx, &sy, &tx, &ty);
		int ans = spfa((node) {
			sx, sy
		}, (node) {
			tx, ty
		});
		if (ans < inf) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}
