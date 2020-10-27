#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n, ans = -1;
int wine[10001];
int memo[10001][3];

void dp(){
    memo[1][0] = 0;
    memo[1][1] = wine[1];
    memo[1][2] = -1;

    memo[2][0] = wine[1];
    memo[2][1] = wine[2];
    memo[2][2] = wine[1] + wine[2];

    for(int i=3;i<=n;++i){
        memo[i][0] = max(memo[i-1][0], max(memo[i-1][1], memo[i-1][2]));
        memo[i][1] = memo[i-1][0] + wine[i];
        memo[i][2] = memo[i-1][1] + wine[i];
    }

    ans = max( memo[n][0], max(memo[n][1], memo[n][2]));
    return;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>wine[i];
    }
    memset(memo,-1,10001*3*4);

    dp();
    cout<<ans;
    return 0;
}