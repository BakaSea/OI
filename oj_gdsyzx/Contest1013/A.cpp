#include<stdio.h>
 
struct carpet {
    int a, b, g, k;
} c[10010];
 
int main() {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &c[i].a, &c[i].b, &c[i].g, &c[i].k);
    }
    scanf("%d%d", &x, &y);
    for (int i = n; i >= 1; i--) {
        if (x >= c[i].a && x <= c[i].a+c[i].g && y >= c[i].b && y <= c[i].b+c[i].k) {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
