#include <iostream>
#include <memory.h>
using namespace std;

long long memo[91];

long long dp(int num){
    if(num == 0){
        memo[num] = 0;
        return 0;
    }

    if(num == 1){
        memo[num] = 1;
        return 1;
    }

    if(memo[num] != -1){
        return memo[num];
    }

    memo[num] = dp(num-1) + dp(num-2);
    return memo[num];
}

int main(){
    int n;
    cin>>n;

    memset(memo,-1,728);
    cout<<dp(n);

    return 0;
}