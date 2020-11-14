#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main() {
    vector<int> v;
    vector<int> num;
    vector<vector<int>> ans;
    int n, m, tmp;
    cin>>n>>m;

    for(int i=0;i<n;++i){
        cin>>tmp;
        num.push_back(tmp);
        if(i < n-m){
            v.push_back(0);
        }else{
            v.push_back(1);
        }
    }
    sort(num.begin(), num.end(), cmp);

    do{
        vector<int> tmp;
        for(int i=n-1;i>=0;--i){
            if(v[i]){
                tmp.push_back(num[i]);
            }
        }
        do{
            ans.push_back(tmp);
        }while(next_permutation(tmp.begin(), tmp.end()));
    }while(next_permutation(v.begin(), v.end()));

    sort(ans.begin(), ans.end());
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
