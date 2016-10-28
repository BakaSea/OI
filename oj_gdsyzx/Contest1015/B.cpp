#include<stdio.h>
#include<stack>
using namespace std;
 
stack<int> a, b;
int n, out[50] = {0};
 
int solve(char c) {
    switch(c) {
        case 'A': {
            out[++out[0]] = a.top();
            a.pop();
            break;
        }
        case 'B': {
            if (b.size() == 5) return 1;
            b.push(a.top());
            a.pop();
            break;
        }
        case 'C': {
            if (b.empty()) return 1;
            out[++out[0]] = b.top();
            b.pop();
            break;
        }
    }
    return 0;
}
 
int main() {
    while (!a.empty()) a.pop();
    while (!b.empty()) b.pop();
    for (int i = 50; i >= 1; i--) a.push(i);
    char temp;
    scanf("%d%*c", &n);
    scanf("%c", &temp);
    while (temp < 32) scanf("%c", &temp);
    if (solve(temp)) {
        printf("No");
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        scanf("%c", &temp);
        if (solve(temp)) {
            printf("No");
            return 0;
        }
    }
    printf("Yes\n");
    for (int i = 1; i <= out[0]; i++) {
        printf("%d\n", out[i]);
    }
    return 0;
}
