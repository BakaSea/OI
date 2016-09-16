#include<stdio.h>
#include<algorithm>
using namespace std;
  
void filecache() {
    freopen("battery.in", "r", stdin);
    freopen("battery.out", "w", stdout);
}
  
int n;
double tmx, tmp, sum;
  
int main() {
    //filecache();
    while (scanf("%d", &n) != EOF) {
        //scanf("%d", &n);
        tmx = 0;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lf", &tmp);
            sum += tmp;
            if (tmx < tmp) tmx = tmp;
        }
        if (sum < 2*tmx) {
            printf("%.1lf\n", sum-tmx);
        }
        else printf("%.1lf\n", sum/2);
    } 
    return 0;
}
