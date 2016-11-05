#include<stdio.h>
#define MAXN 1000001
 
int par[MAXN];
bool book[MAXN] = {0};
 
void dfs(int step) {
    book[step] = 1;
    if (par[step] == step) return;
    dfs(par[step]);
}
 
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 1, a, b; i < n; ++i) {
        scanf("%d%d", &a, &b);
        if (a < b) par[b] = a;
        else par[a] = b;
    }
    int s, e;
    scanf("%d%d", &s, &e);
    dfs(s);
    while (!book[e]) {
        e = par[e];
    }
    printf("%d", e);
    return 0;
}
