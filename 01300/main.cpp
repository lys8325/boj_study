#include <cstdio>
#include <algorithm>
using namespace std;

long long n, k;
int main() {
    scanf("%lld %lld", &n, &k);
    long long left = 1;
    long long right = n * n;
    long long mid;
    long long ans, tmp;

    while(left <= right){
        tmp = 0;
        mid  = (left + right) / 2;
        for(int i=1;i<=n;++i){
            tmp += min( mid/i, n);
        }
        if(k <= tmp){
            ans = mid;
            right = mid -1;
        }else{
            left = mid + 1;
        }
    }
    printf("%d", ans);
    return 0;
}