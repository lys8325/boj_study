#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, ans;
    cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;++i){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    ans = v[0];
    for(int i=1;i<n;++i){
        v[i] += v[i-1];
        ans += v[i];
    }

    cout<<ans;
    return 0;
}
