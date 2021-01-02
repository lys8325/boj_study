#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, idx1, idx2, ansIdx1, ansIdx2;
    long long num, tmpSum, sum = -2000000001;
    vector<long long> v;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    idx1 = 0, idx2 = n-1;

    while(sum != 0 && idx1 != idx2){
        tmpSum = v[idx1] + v[idx2];
        if(abs(sum) > abs(tmpSum)){
            sum = tmpSum;
            ansIdx1 = idx1;
            ansIdx2 = idx2;
        }

        if(tmpSum > 0){
            --idx2;
        }else{
            --idx1;
        }
    }

    cout<<v[ansIdx1]<<" "<<v[ansIdx2];
    return 0;
}
