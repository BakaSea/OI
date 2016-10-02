#include<stdio.h>
#include<iostream>
using namespace std;
 
int main() {
    int n, m;
    for (scanf("%d%d", &n, &m); n || m; scanf("%d%d", &n, &m)) {
        if (n < m) swap(n, m);
        if (n/m >= 2 || !n%m || n == m) printf("win\n");
        else {
            int tot = 0;
            do {
                n -= m;
                swap(n, m);
                tot++;
            } while (n/m < 2 && n%m);
            if (tot%2) printf("lose\n");
            else printf("win\n");
        }
    }
    return 0;
}
