#include<stdio.h>
 
int main() {
    int n, m, k, x;
    scanf("%d%d%d%d", &n, &m, &k, &x);
    int r = 1, c = 10;
    while (k) {
        if (k&1) r = (r*(c%n))%n;
        k = k >> 1;
        c = (c*c)%n;
    }
    r = (r*(m%n))%n;
    r = (r+x)%n;
    printf("%d", r);
    return 0;
}
