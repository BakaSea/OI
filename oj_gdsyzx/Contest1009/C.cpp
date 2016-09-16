#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
 
int n, a[11], b[12][11] = {0}, tmin;
 
int f(int x, int y) {
    if (!y) return x;
    return f(y, x%y);
}
 
void dfs(int step, int count) {
    if (count > tmin) return;
    if (step == n+1) {
        if (count < tmin) {
            tmin = count;
        }
        return;
    }
    for (int i = 1; i <= count; i++) {
        bool flag = true;
        for (int j = 1; j <= b[i][0]; j++) {
            if (f(max(a[step], b[i][j]), min(a[step], b[i][j])) != 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            b[i][++b[i][0]] = a[step];
            dfs(step+1, count);
            b[i][b[i][0]--] = 0;
        }
    }
    count++;
    b[count][++b[count][0]] = a[step];
    dfs(step+1, count);
    b[count][b[count][0]--] = 0;
    return;
}
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    tmin = 20;
    dfs(1, 0);
    printf("%d", tmin);
    return 0;
}
