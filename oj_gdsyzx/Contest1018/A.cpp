#include<stdio.h>
#include<string.h>
using namespace std;
 
char s[10000+10];
double n, m;
 
int main() {
    //freopen("jiantao.in", "r", stdin);
    //freopen("jiantao.out", "w", stdout);
    scanf("%lf%lf%*c", &n, &m);
    m /= 100;
    gets(s);
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    double minn, maxn;
    for (int i = 0, num; i < strlen(s); ++i) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] == ',')) {
            cnt1++;
            cnt2++;
            if (s[i] != ',') cnt3++;
        }
        if (s[i] == ' ') cnt2++;
        if (s[i] == '.') {
            cnt1++;
            cnt2++;
            num = 0;
            while (++num) {
                if (((num*n*(1-m) <= cnt1) && (n*num*(1+m) >= cnt1)) || ((num*n*(1-m) <= cnt3) && (n*num*(1+m) >= cnt3))) {
                    printf("%d", cnt2);
                    return 0;
                }
                if (num*n*(1-m) > cnt1) break;
            }
        }
    }
    printf("0");
    return 0;
}
