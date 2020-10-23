#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, ans = 0;
    cin>>n;

    int num[n], s[n];
    for(int i=0;i<n;++i){
        cin>>num[i];
    }

    s[0] = num[0];
    ans = s[0];
    for(int i=1;i<n;++i){
        s[i] = max(s[i-1]+num[i], num[i]);
        ans = max(ans, s[i]);
    }

    cout<<ans;
    return 0;
}
