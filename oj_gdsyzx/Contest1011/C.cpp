#include<stdio.h>
  
int n, k, a[10001];
double t;
  
int main() {
    scanf("%d%d", &n, &k);
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &t);
        a[i] = t*100;
        if (a[i] > r) r = a[i]+1;
    }
    while (l+1 < r) {
        int mid = (l+r)/2;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += a[i]/mid;
        }
        if (ans >= k) l = mid;
        else r = mid;
    }
    printf("%.2lf", l/100.0);
    return 0;
}
