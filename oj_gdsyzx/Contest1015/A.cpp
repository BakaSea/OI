#include<stdio.h>
#include<vector>
using namespace std;
 
int main() {
    int n, m, p;
    vector<int> v;
    while (!v.empty()) v.pop_back();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) v.push_back(i);
    p = 1;
    while (n) {
        p = (p+m-1)%n;
        if (!p) p = n;
        printf("%d ", v[p-1]);
        v.erase(v.begin()+p-1);
        n--;
    }
}
