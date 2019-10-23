#include<stdio.h>
#include<string.h>
#define MOD 3167
using namespace std;

int n, a[MOD], c;
char s[MOD][20], ans[20];

void hash(char *t) {
	int x = 0, len = strlen(t);
	for (int i = 0; i < len; ++i) x = (x+(t[i]-'a')*(i+1))%MOD;
	while (a[x] && strcmp(s[x], t) != 0) x = (x+1)%MOD;
	if (!a[x]) strcpy(s[x], t);
	a[x]++;
}

int main() {
	while (scanf("%d", &n) != EOF && n) {
		char tmp[20];
		memset(a, 0, sizeof(a));
		memset(s, 0, sizeof(s));
		c = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%s", tmp);
			hash(tmp);
		}
		for (int i = 0; i < MOD; ++i) {
			if (c < a[i]) {
				c = a[i];
				strcpy(ans, s[i]);
			}
		}
		printf("%s\n", ans);
	}
	return 0;
}
