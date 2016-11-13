#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;
 
struct BIGNUM {
     
    int len, a[3000];
     
    BIGNUM() {
        len = 1;
        a[len] = 0;
    }
     
    void operator = (int b) {
        len = 0;
        while (b) {
            a[++len] = b%10;
            b /= 10;
        }
    }
     
    void operator = (BIGNUM b) {
        memset(a, 0, sizeof(a));
        len = b.len;
        for (int i = 1; i <= len; ++i) {
            a[i] = b.a[i];
        }
    }
     
    BIGNUM operator * (BIGNUM b) {
        BIGNUM c;
        memset(c.a, 0, sizeof(c.a));
        for (int i = 1; i <= len; ++i) {
            for (int j = 1, x, k; j <= b.len; ++j) {
                c.a[i+j-1] += a[i]*b.a[j];
                x = c.a[i+j-1]/10;
                c.a[i+j-1] %= 10;
                k = i+j-1;
                while (x) {
                    c.a[++k] += x%10;
                    x /= 10;
                }
            }       }
        c.len = len+b.len;
        while (c.a[c.len] == 0) c.len--;
        return c;
    }
     
};
 
int f(int x, int y) {
    if (x%y) return f(y, x%y);
    return y;
}
 
int main() {
    freopen("fannao.in", "r", stdin);
    freopen("fannao.out", "w", stdout);
    BIGNUM sum, b;
    int n, ans, y = 0;
    scanf("%d", &n);
    if (n == 0 || n == 1) {
        printf("1F");
        return 0;
    }
    sum = n;
    while (--n) {
        b = n;
        sum = sum*b;
    }
    for (int i = sum.len; i > 0; --i) {
        y += sum.a[i];
    }
    printf("%d", y);
    for (int i = 2; i <= sqrt(y); ++i) {
        if (f(y, i) == i) {
            printf("F");
            return 0;
        }
    }
    printf("T");
    return 0;
}
