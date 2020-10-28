#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

vector<pair<int, int>> ks;
int n, k;
int memo[100][100001];

int dp(int num, int total){
    int &v = memo[num][total];
    if(num == n){
        return 0;
    }

    if(v != 0){
        return v;
    }

    if(total + ks[num].first <= k){
        v = dp(num+1, total + ks[num].first) + ks[num].second;
    }

    v = max(v, dp(num+1, total));
    return v;
}

int main() {
    cin>>n>>k;

    int w, v;
    for(int i=0;i<n;++i){
        cin>>w>>v;
        ks.push_back({w, v});
    }

    cout<<dp(0,0);
    return 0;
}
