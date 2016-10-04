#include<stdio.h>
 
struct station {
    int x, y, s;
} a[200010];
 
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].s);
    double l = 0, r = 1e7;
    while (r-l >= 1e-6) {
        double mid = (l+r)/2, t = 0;
        bool flag = 0;
        a[0].y = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i].s/mid+t <= a[i].x) t = a[i].x;
            else if (a[i].s/mid+t > a[i].y) {
                flag = 1;
                break;
            } else if (a[i].s/mid+t > a[i].x && a[i].s/mid+t <= a[i].y) t += a[i].s/mid;
        }
        if (flag) l = mid;
        else r = mid;
    }
    printf("%.2lf", l);
    return 0;
}
