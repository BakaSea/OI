#include<cstdio>
#include<cmath>
using namespace std;
  
double f(double x) {
    //x5 - 15 * x4+ 85 * x3- 225 * x2+ 274 * x - 121 
    return x*x*x*x*x-15*x*x*x*x+85*x*x*x-225*x*x+274*x-121;
}
  
int main() {
    int k = 0;
    double l, r, mid, x;
    l = 1.5; r = 2.4;
    while (k < 20) {
        mid=(l+r)/2;
        x = f(mid);
        if(x > 0) l=mid;
        else r=mid;
        k++;
    }
    printf("%.6lf",mid);
    return 0;
}
