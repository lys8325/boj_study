#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
int n, ans = -1;
int memo[101];

int main() {
    int from, to;
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>from>>to;
        v.push_back({from, to});
    }
    sort(v.begin(), v.end());

    for(int i=0;i<n;++i){
        memo[i] = 1;
        for(int j=0;j<i;++j){
            if(v[j].second < v[i].second){
                memo[i] = max(memo[i], memo[j]+1);
            }
        }
        ans = max(ans, memo[i]);
    }

    cout<<n - ans;
    return 0;
}
