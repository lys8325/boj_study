#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

bool dp[41];
vector<pair<int, int>> v(41);

pair<int, int> fib(int num){
    if(num == 0){
        dp[num] = true;
        v[num] = {1, 0};
        return v[num];
    }

    if(num == 1){
        dp[num] = true;
        v[num] = {0, 1};
        return v[num];
    }

    if(dp[num]){
        return v[num];
    }

    dp[num] = true;
    pair<int, int> tmp1 = fib(num-1);
    pair<int, int> tmp2 = fib(num-2);
    v[num] = {tmp1.first+tmp2.first, tmp1.second+tmp2.second};
    return v[num];
}

int main() {
    int t, n;
    cin>>t;

    for(int i=0;i<t;++i){
        cin>>n;
        memset(dp, 0, 4*(n+1));
        v.clear();
        fib(n);
        cout<<v[n].first<<" "<<v[n].second<<"\n";
    }
    return 0;
}
