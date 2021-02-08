#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long n, m, tmp, h, d, sum;
    pair<long, long> ans = {9223372036854775807LL, 0};
    vector<long> v;

    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int l = 0, r = v[n-1], mid;

    while(l <= r){
        sum = 0;
        h = (l + r) / 2;

        for(auto iter = lower_bound(v.begin(), v.begin(), mid);iter<v.end();++iter){
            d = *iter - h;

            if(d > 0){
                sum += d;
            }
        }

        if(sum < m){
            r = h - 1;
        }else{
            l = h + 1;
            if(ans.first > sum - m){
                ans = {sum-m, h};
            }
        }
    }

    cout<<ans.second;
    return 0;
}