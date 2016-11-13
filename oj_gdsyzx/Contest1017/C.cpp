#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
 
struct Edge {
    int u, v, next;
} e[500000+10], fe[500000+10];
 
int h[100000+10], fh[100000+10], n, m, w[100000+10], low[100000+10];
bool book[100000+10] = {0}, vis[500000+10] = {0};
 
void spfa() {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    while (!q.empty()) q.pop();
    vis[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        for (int i = h[u], flag; i; i = e[i].next) {
        	if (book[e[i].v] && !vis[i]) {
        		vis[i] = 1;
            	if (low[u] < low[e[i].v]) low[e[i].v] = low[u];
        		q.push(e[i].v);
			}
        }
        q.pop();
    }
    return;
}
 
void bfs() {
    book[n] = 1;
    queue<int> q;
    while (!q.empty()) q.pop();
    q.push(n);
    vis[n] = 1;
    while (!q.empty()) {
        int u = q.front();
        for (int i = fh[u]; i; i = fe[i].next) {
            if (!vis[i]) {
                vis[i] = 1;
                book[fe[i].v] = 1;
                q.push(fe[i].v);
            }
        }
        q.pop();
    }
    return;
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
    	scanf("%d", &w[i]);
    	low[i] = w[i];
	}
    for (int i = 1, z, cnt = 0; i <= m; ++i) {
    	cnt++;
        scanf("%d%d%d", &e[cnt].u, &e[cnt].v, &z);
        fe[cnt].u = e[cnt].v;
        fe[cnt].v = e[cnt].u;
        fe[cnt].next = fh[fe[cnt].u];
        fh[fe[cnt].u] = cnt;
        e[cnt].next = h[e[cnt].u];
        h[e[cnt].u] = cnt;
        if (z == 2) {
        	cnt++;
        	fe[cnt].u = fe[cnt-1].v;
        	fe[cnt].v = fe[cnt-1].u;
        	fe[cnt].next = fh[fe[cnt].u];
        	fh[fe[cnt].u] = cnt;
        	e[cnt].u = e[cnt-1].v;
        	e[cnt].v = e[cnt-1].u;
        	e[cnt].next = h[e[cnt].u];
        	h[e[cnt].u] = cnt;
		}
    }
    bfs();
    spfa();
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
    	if (ans < w[i]-low[i]) ans = w[i]-low[i];
	}
	printf("%d", ans);
    return 0;
}
