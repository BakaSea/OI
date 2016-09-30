#include<stdio.h>
  
int n, k;
double a[10001];
  
int main() {
    scanf("%d%d", &n, &k);
    k++;
    double l = 0, r = 0;
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        a[i] = 3.141592653589*t*t;
        if (a[i] > r) r = a[i]+1;
    }
    while (l+0.00001 < r) {
        double mid = (l+r)/2;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += a[i]/mid;
        }
        if (ans >= k) l = mid;
        else r = mid;
    }
    printf("%.3lf", l);
    return 0;
}
