#include<stdio.h>
#include<string.h>
using namespace std;
 
int n, tmx, b[21] = {0};
char word[21][21], dragon[900], start;
 
void dfs(int step) {
    if (strlen(dragon) > tmx) {
        tmx = strlen(dragon);
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] < 2 || step == 1) {
            int lend = strlen(dragon);
            int len = 0;
            for (int j = lend-1; j >= 0; j--) {
                char s1[21] = {0}, s2[21] = {0};
                len = lend-j;
                if (len == strlen(word[i])) break;
                for (int k = 0; k < len; k++) {
                    s1[k] = dragon[j+k];
                    s2[k] = word[i][k];
                     
                }
                if (!strcasecmp(s1, s2)) break;
            }
            if ((len == lend && step != 1) || len == strlen(word[i])) continue;
            char s3[900] = {0};
            strcpy(s3, dragon);
            for (int p = len; p < strlen(word[i]); p++) {
                dragon[lend+p-len] = word[i][p];
            }
            b[i]++;
            if (dragon[0] == start) {
                dfs(step+1);
            }
            b[i]--;
            memset(dragon, 0, sizeof(dragon));
            strcpy(dragon, s3);
        }
    }
    return;
}
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", word[i]);
    }
    scanf("%*c%c", &start);
    tmx = 0;
    dfs(1);
    printf("%d", tmx);
    return 0;
}
