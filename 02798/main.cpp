#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int num[100] = {0,};
    int n, m, sum, ans = -1;
    cin>>n>>m;
    vector<int> v(3, 1);
    for(int i=0;i<n;++i){
        cin>>num[i];
        if(i >= 3){
            v.push_back(0);
        }
    }

    sort(v.begin(), v.end());
    do{
        sum = 0;
        for(int i=0;i<n;++i){
            if(v[i]){
                sum += num[i];
            }
        }
        if(sum <= m){
            ans = max(ans, sum);
        }
    }while(next_permutation(v.begin(), v.end()));

    cout<<ans;
    return 0;
}
