#include<stdio.h>
#include<iostream>
  
int n, t[200005], b[200005] = {0}, par[200005], timet[200005], tmin = 999999999;
  
void dfs(int now, int step, int cnt) {
    b[now] = 1;
    par[now] = cnt;
    timet[now] = step;
    if (!b[t[now]]) {
        dfs(t[now], step+1, cnt);
    } else {
        if (par[t[now]] == cnt) {
            tmin = std::min(tmin, timet[now]-timet[t[now]]+1);
        }
    }
}
  
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 1; i <= n; i++) {
        dfs(i, 0, i);
    }
    printf("%d", tmin);
    return 0;
}
