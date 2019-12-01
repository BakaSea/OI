#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

struct node {
	int x, y, d;
};

int n, m, d[510][510];
char g[510][510];

int ok(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > m) return 0;
	return 1;
}

void bfs() {
	deque<node> q;
	while (!q.empty()) q.pop_back();
	q.push_back((node) {1, 1, 0});
	while (!q.empty()) {
		node cur = q.front();
		q.pop_front();
		int x = cur.x, y = cur.y, dis = cur.d;
		if (ok(x-1, y-1)) {
			if (g[x-1][y-1] == '\\')  {
				if (d[x-1][y-1] > dis) {
					d[x-1][y-1] = dis;
					q.push_front((node) {x-1, y-1, dis});
				}				
			} else if (d[x-1][y-1] > dis+1) {
				d[x-1][y-1] = dis+1;
				q.push_back((node) {x-1, y-1, dis+1});
			}
		}
		if (ok(x-1, y+1)) {
			if (g[x-1][y] == '/')  {
				if (d[x-1][y+1] > dis) {
					d[x-1][y+1] = dis;
					q.push_front((node) {x-1, y+1, dis});
				}
			} else if (d[x-1][y+1] > dis+1) {
				d[x-1][y+1] = dis+1;
				q.push_back((node) {x-1, y+1, dis+1});
			}
		}
		if (ok(x+1, y+1)) {
			if (g[x][y] == '\\')  {
				if (d[x+1][y+1] > dis) {
					d[x+1][y+1] = dis;
					q.push_front((node) {x+1, y+1, dis});
				}
			} else if (d[x+1][y+1] > dis+1) {
				d[x+1][y+1] = dis+1;
				q.push_back((node) {x+1, y+1, dis+1});
			}
		}
		if (ok(x+1, y-1)) {
			if (g[x][y-1] == '/')  {
				if (d[x+1][y-1] > dis) {
					d[x+1][y-1] = dis;
					q.push_front((node) {x+1, y-1, dis});
				}
			} else if (d[x+1][y-1] > dis+1) {
				d[x+1][y-1] = dis+1;
				q.push_back((node) {x+1, y-1, dis+1});
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	if ((n+m) & 1) printf("NO SOLUTION");
	else {
		for (int i = 1; i <= n; ++i) scanf("%s", g[i]+1);
		n++; m++;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				d[i][j] = 2147483647;
			}
		}
		bfs();
		printf("%d", d[n][m]);
	}
	return 0;
}
