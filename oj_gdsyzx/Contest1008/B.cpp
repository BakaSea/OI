#include<stdio.h>
 
void filecache() {
    freopen("intelligence.in", "r", stdin);
    freopen("intelligence.out", "w", stdout);
}
 
int n;
long long f[25] = {0};
 
int main() {
    filecache();
    scanf("%d", &n);
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = (i-1)*(f[i-1]+f[i-2]);
    }
    printf("%lld", f[n]);
    return 0;
}
