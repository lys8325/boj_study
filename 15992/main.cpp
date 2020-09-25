#include <cstdio>
#include <cstring>
using namespace std;

int t, n, m;
int dp[1001][1001];

int calc(int tmpN, int tmpM){
    if(tmpN < 0 || tmpM < 0){
        return 0;
    }
    if(tmpN == 0 && tmpM == 0){
        return 1;
    }
    long long ret = dp[tmpN][tmpM];
    if(ret != -1){
        return (int)ret;
    }

    ret = 0;
    for(int i=1;i<=3;++i){
        ret += calc(tmpN-i, tmpM-1) % 1000000009;
    }

    ret %= 1000000009;
    dp[tmpN][tmpM] = (int)ret;
    return  (int)ret;
}

int main() {
    scanf("%d", &t);
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<t;++i){
        scanf("%d %d", &n, &m);
        printf("%d\n",calc(n, m));
    }
    return 0;
}
