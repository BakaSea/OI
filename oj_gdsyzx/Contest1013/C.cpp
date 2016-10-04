#include<stdio.h>
 
int a[110], n, m, flag;
 
void dfs(int step, int cnt) {
    if (step == n+1) {
        if (cnt == m) flag = 1;
        return;
    }
    if (cnt > m) return;
    dfs(step+1, cnt);
    dfs(step+1, cnt+a[step]);
    return;
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    flag = 0;
    dfs(1, 0);
    if (flag) printf("yes");
    else printf("no");
    return 0;
}
