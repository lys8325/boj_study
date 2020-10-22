#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int num[501][501];
int memo[501][501];

int dp(int y, int x){
    int &v = memo[y][x];
    if(y == 1){
        v = num[y][x];
        return v;
    }

    if(v != -1){
        return v;
    }

    if(x == 1){
        v = dp(y-1, x) + num[y][x];
    }else if(x == y){
        v = dp(y-1, x-1) + num[y][x];
    }else{
        v = max(dp(y-1, x), dp(y-1, x-1)) + num[y][x];
    }

    return v;
}

int main() {
    int n, ans = -1;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            cin>>num[i][j];
        }
    }

    memset(memo, -1, 501*501*4);
    for(int i=1;i<=n;++i){
        ans = max(ans, dp(n, i));
    }

    cout<<ans;
    return 0;
}
