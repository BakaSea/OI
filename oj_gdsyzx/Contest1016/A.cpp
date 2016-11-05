#include<stdio.h>
 
int par[1001];
 
int find(int x) {
    if (par[x] != x) par[x] = find(par[x]);
    return par[x];
}
 
int main() {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) par[i] = i;
    for (int i = 1, a, b; i <= n; ++i) {
        scanf("%d%d", &a, &b);
        int x = find(a);
        int y = find(b);
        if (x != y) par[x] = y;
        else ans++;
    }
    printf("%d", ans);
    return 0;
}
