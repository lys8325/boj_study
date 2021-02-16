#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, num1, num2, num3, l, r, idx;
    vector<int> v;
    long long sum = 3000000000, tmpSum;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num1;
        v.push_back(num1);
    }
    sort(v.begin(), v.end());

    l = 0; r = n-1;
    while(l < r-1){
        tmpSum = v[l] + v[r];
        idx = lower_bound(v.begin(), v.end(), -tmpSum) - v.begin();
        tmpSum += v[idx];

        if(sum > abs(tmpSum)){
            sum = abs(tmpSum);

            num1 = v[l];
            num2 = v[idx];
            num3 = v[r];
        }

        if(tmpSum > 0){
            --r;
        }else if(tmpSum < 0){
            ++l;
        }else{
            break;
        }
    }

    cout<<num1<<" "<<num2<<" "<<num3;
}
