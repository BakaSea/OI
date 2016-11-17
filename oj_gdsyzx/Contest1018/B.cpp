#include<stdio.h>
#include<algorithm>
#include<string.h>
#define MAXN 10010
#define MAXM 100000*2+10
#define INF 0x7fffffff
using namespace std;
 
struct Edge {
    int u, v, w, next;
} e[MAXM];
 
int h[MAXN], n, m, k, cal[MAXN], book[MAXN];
 
int main() {
    //freopen("xiayibu.in", "r", stdin);
    //freopen("xiayibu.out", "w", stdout);
    memset(h, 0, sizeof(h));
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1, u, v, w, j = m+1; i <= m; ++i, ++j) {
        scanf("%d%d%d", &u, &v, &w);
        e[i].u = u;
        e[i].v = v;
        e[i].w = w;
        e[i].next = h[u];
        h[u] = i;
        e[j].u = v;
        e[j].v = u;
        e[j].w = w;
        e[j].next = h[v];
        h[v] = j;
    }
    for (int i = 1, temp, cnt, minn, u; i <= k; ++i) {
        memset(book, 0, sizeof(book));
        scanf("%d", &temp);
        cnt = 0, minn = INF, u = INF;
        for (int j = h[temp]; j; j = e[j].next) {
            if (minn > e[j].w) {
                minn = e[j].w;
                u = e[j].v;
            }
            if (minn == e[j].w && u > e[j].v) {
                u = e[j].v;
            }
            if (book[e[j].v]) continue;
            cnt++;
            book[e[j].v] = 1;
            cal[cnt] = e[j].v;
        }
        if (minn == INF) printf("0\n");
        else {
            printf("%d", u);
            for (int j = 1; j <= cnt; ++j) {
                printf(" %d", cal[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
