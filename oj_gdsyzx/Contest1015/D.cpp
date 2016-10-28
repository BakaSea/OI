#include<stdio.h>
#include<iostream>
#include<string.h>
#define MOD 1000000007
using namespace std;
 
long long da[2][201][1001], db[2][201][1001];
int n, m, K;
char a[1001], b[1001];
 
int main() {
    scanf("%d%d%d%s%s", &n, &m, &K, a+1, b+1);
    int now = 1, pre = 0;
    da[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        da[now][0][0] = 1;
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= K; k++) {
                if (a[i] == b[j]) {
                    db[now][j][k] = (da[pre][j-1][k-1]+db[pre][j-1][k])%MOD;
                } else {
                    db[now][j][k] = 0;
                }
                da[now][j][k] = (da[pre][j][k]+db[now][j][k])%MOD;
            }
        }
        swap(now, pre);
    }
    printf("%lld", da[pre][m][K]);
    return 0;
}
