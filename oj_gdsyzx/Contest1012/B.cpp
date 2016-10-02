#include<stdio.h>
 
int n, m, a[100001];
 
int check(int x) {
    int k = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > x) return 0;
        if (k+a[i] > x) {
            k = a[i];
            cnt++;
        } else k += a[i];
    }
    cnt++;
    if (cnt <= m) return 1;
    return 0;
}
 
int main() {
    scanf("%d%d", &n, &m);
    int l = 0, r = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        r += a[i];
    }
    while (l <= r) {
        int mid = (l+r)/2;
        if (check(mid)) {
            ans = mid;
            r = mid-1;
        } else l = mid+1;
    }
    printf("%d", ans);
    return 0;
}
