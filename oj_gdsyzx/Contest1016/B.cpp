#include<stdio.h>
#include<string.h>
#define MAXN 2501
using namespace std;
 
int g[MAXN][MAXN], minn[MAXN];
bool book[MAXN];
 
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(g, 1, sizeof(g));
    for (int i = 1, x, y, c; i <= m; ++i) {
        scanf("%d%d%d", &x, &y, &c);
        g[x][y] = g[y][x] = c;
    }
    memset(minn, 1, sizeof(minn));
    minn[1] = 0;
    memset(book, 1, sizeof(book));
    for (int i = 1; i <= n; i++) {
        int k = 0;
        for (int j = 1; j <= n; ++j) {
            if (book[j] && (minn[j] < minn[k])) k = j;
        }
        book[k] = 0;
        for (int j = 1; j <= n; ++j) {
            if (book[j] && (g[k][j] < minn[j])) minn[j] = g[k][j];
        }
    }
    int maxn = 0;
    for (int i = 1; i <= n; ++i) {
        if (maxn < minn[i]) maxn = minn[i];
    }
    printf("%d %d", n-1, maxn);
    return 0;
}
