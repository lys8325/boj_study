#include <iostream>
using namespace std;

int n;
int cnt[1000001];

int dp(int len){
    if(len == 1){
        cnt[len] = 1;
        return 1;
    }
    if(len == 2){
        cnt[len] = 2;
        return 2;
    }

    if(cnt[len] > 0){
        return cnt[len];
    }

    cnt[len] = (dp(len-1) + dp(len-2)) % 15746;
    return cnt[len];
}

int main() {
    cin>>n;
    cout<<dp(n);
    return 0;
}
