#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
 
int n, k, pre[101], sum, tmx, par[101] = {0};
 
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        pre[i] = i;
    }
    for (int i = 1; i <= k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        pre[max(a, b)] = min(a, b);
    }
    sum = 0;
    tmx = 1;
    for (int i = 1; i <= n; i++) {
        if (pre[i] == i) {
            par[i] = 1;
            sum++;
        }
        else {
            int j = i;
            while (j != pre[j]) {
                j = pre[j];
            }
            par[j]++;
            tmx = max(par[j], tmx);
        }
    }
    printf("%d %d", sum, tmx);
    return 0;
}
