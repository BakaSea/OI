#include<stdio.h>
#include<string.h>
#define ULL unsigned long long
#define B 10000007
using namespace std;

int T;
char s1[1000010], s2[1000010];
ULL p[1000010], sum[1000010];

int main() {
	p[0] = 1;
	for (int i = 1; i <= 1000000; ++i) p[i] = p[i-1]*B;
	scanf("%s%s", s2+1, s1+1);
	int n = strlen(s1+1), m = strlen(s2+1);
	sum[0] = 0;
	for (int i = 1; i <= m; ++i) sum[i] = sum[i-1]*B+(ULL)(s2[i]-'A'+1);
	ULL s = 0;
	for (int i = 1; i <= n; ++i) s = s*B+(ULL)(s1[i]-'A'+1);
	int ans = 0;
	for (int i = 0; i <= m-n; ++i) {
		if (s == sum[i+n]-sum[i]*p[n]) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}
