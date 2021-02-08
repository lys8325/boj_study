#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, tmp, h, d, sum, ans = -1;
    vector<int> v;

    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int l = 0, r = v[n-1], mid;

    while(l < r){
        sum = 0;
        mid = (l + r) / 2;
        h = v[mid];

        for(int i=mid;i<n;++i){
            d = v[i] - h;
            if(d > 0){
                sum += d;
            }
        }

        if(sum < m){
            r = mid - 1;
        }else{
            l = mid + 1;
            if(sum == m){
                ans = max(ans, h);
            }
        }
    }

    cout<<ans;
    return 0;
}