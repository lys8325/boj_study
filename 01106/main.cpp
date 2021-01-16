#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int c, n;
int memo[1001];
pair<int, int> city[20];

int dp(int cnt){
    if(cnt <= 0){
        return 0;
    }

    int &v = memo[cnt];
    if(v != -1){
        return v;
    }

    v = INT_MAX;
    for(int i=0;i<n;++i){
        v = min(v, dp(cnt - city[i].second) + city[i].first);
    }

    return v;
}

int main() {
    int cost, people;

    cin>>c>>n;
    for(int i=0;i<n;++i){
        cin>>cost>>people;
        city[i] = {cost, people};
    }

    memset(memo, -1, c*4+4);
    cout<<dp(c);
    return 0;
}
