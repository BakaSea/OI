#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
 
int T, n, x, y, ans;
int a[20];
 
void clear() {
    memset(a, 0, sizeof(a));
    ans = 0;
}
 
bool check() {
    for (int i = 1; i <= 15; ++i) {
        if (a[i]) return false;
    }   
    return true;
}
 
void dfs(int step) {
    if (step > ans) return;
    if (check()) {
        ans = min(ans, step);
        return;
    }
    int sum = 0;
    for (int i = 1; i <= 13; i++) {
        if (a[i]) sum++;
    }
    if (a[14]+a[15]) sum++;
    ans=min(ans,step+sum);
    for (int kind = 1; kind <= 5; kind++) {
        if (kind == 1) {
            for (int i = 1; i <= 8; i++) {
                if (a[i]) {
                    bool flag = true;
                    for (int j = i+1; j <= i+3; j++) {
                        if (!a[j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) continue;
                    for (int j = i+4; j < 13 && a[j]; j++) {
                        for (int k = i; k <= j; k++) a[k]--;
                        dfs(step+1);
                        for (int k = i; k <= j; k++) a[k]++;
                    }
                }
            }
        }
        if (kind == 2) {
            for (int i = 1; i <= 10; i++) {
                if (a[i] >= 2 && a[i+1] >= 2) {
                    for (int j = i+2; j < 13 && a[j] >= 2; j++) {
                        for (int k = i; k <= j; k++) a[k] -= 2;
                        dfs(step+1);
                        for (int k = i; k <= j; k++) a[k] += 2;
                    }
                }   
            }
        }
        if (kind == 3) {
            for (int i = 1; i <= 11; i++) {
                if (a[i] >= 3) {
                    if (a[i+1] < 3) continue;
                    for (int j = i; j < 13 && a[j] >= 3; j++) {
                        for (int k = i; k <= j; k++) a[k] -= 3;
                        dfs(step+1);
                        for (int k = i; k <= j; k++) a[k] += 3;
                    }
                }
            }
        }
        if (kind==4) {
            for (int i = 1; i <= 13; i++) {
                if (a[i] >= 3) {
                    a[i] -= 3;
                    for (int j = 1; j <= 15; j++) {
                        if (a[j]) {
                            a[j]--;
                            dfs(step+1);
                            a[j]++;
                        }
                    }
                    for (int j = 1; j <= 15; j++) {
                        if (a[j] >= 2) {
                            a[j] -= 2;
                            dfs(step+1);
                            a[j] += 2;
                        }
                    }
                    a[i] += 3;
                }
            }
        }
        if (kind == 5) {
            for (int i = 1; i <= 15; i++) {
                if (a[i] >= 4) {
                    a[i] -= 4;
                    for (int j = 1; j <= 15; j++) {
                        if (a[j]) {
                            a[j]--;
                            for (int k = j; k <= 15; k++) {
                                if (a[k]) {
                                    a[k]--;
                                    dfs(step+1);
                                    a[k]++;
                                }
                            }
                            a[j]++;
                        }
                    }
                    a[i] += 4;
                }
            }
            for (int i = 1; i <= 15; i++) {
                if (a[i] >= 4) {
                    a[i] -= 4;
                    for (int j = 1; j <= 15; j++) {
                        if (a[j] >= 2) {
                            a[j] -= 2;
                            for (int k = j; k <= 15; k++) {
                                if (a[k] >= 2) {
                                    a[k] -= 2;
                                    dfs(step+1);
                                    a[k] += 2;
                                }
                            }
                            a[j] += 2;
                        }
                    }
                    a[i] += 4;
                }
            }  
        }
    }
}
 
int main() {
    scanf("%d%d", &T, &n);
    while (T--) {
        clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &x, &y);
            if (!x) a[y+13]++;
            if (x == 1 || x == 2) a[x+11]++;
            if (x>=3) a[x-2]++;
        }
        for (int i = 1; i <= 13; i++) if (a[i]) ans++;
        if (a[14]+a[15]) ans++;
        dfs(0);
        printf("%d\n",ans);
    }
}
