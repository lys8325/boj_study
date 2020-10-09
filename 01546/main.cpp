#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, sum=0, tmp, maxN = -1;
    double ans;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>tmp;
        maxN = max(maxN, tmp);
        sum += tmp;
    }

    ans = (double)sum * 100 / maxN / n;
    cout<<ans;

    return 0;
}
