#include <iostream>
#include <string.h>
using namespace std;

int n;
int memo[101][11];

int dp(int len, int num){
    int &v = memo[len][num];

    if(len <= 1){
        return v;
    }

    if(len == 2){
        switch (num) {
            case 0:
                v = 1;
                break;
            case 1:
                v = 1;
                break;
            case 9:
                v = 1;
                break;
            default:
                v = 2;
                break;
        }
        return v;
    }

    if(v != -1){
        return v;
    }

    switch (num) {
        case 0:
            v = dp(len-1,1);
            break;
        case 1:
            v = dp(len-1,0)+dp(len-1,2);
            break;
        case 2:
            v = dp(len-1,1)+dp(len-1,3);
            break;
        case 3:
            v = dp(len-1,2)+dp(len-1,4);
            break;
        case 4:
            v = dp(len-1,3)+dp(len-1,5);
            break;
        case 5:
            v = dp(len-1,4)+dp(len-1,6);
            break;
        case 6:
            v = dp(len-1,5)+dp(len-1,7);
            break;
        case 7:
            v = dp(len-1,6)+dp(len-1,8);
            break;
        case 8:
            v = dp(len-1,7)+dp(len-1,9);
            break;
        case 9:
            v = dp(len-1,8);
            break;
    }

    v %= 1000000000;
    return v;
}

int main() {
    cin>>n;
    int ans = 0;

    memset(memo,-1,101*11*4);
    memo[0][0] = 0;
    memo[1][0] = 0;
    for(int i=1;i<10;++i){
        memo[0][i] = 0;
        memo[1][i] = 1;
    }

    for(int i=0;i<10;++i){
        ans += dp(n,i);
        ans %= 1000000000;
    }

    cout<<ans;
    return 0;
}
