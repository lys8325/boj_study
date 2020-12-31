#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int isMember[100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, from, to, ansVal = 0, ansIdx = 0;
    cin>>n;

    vector<pair<int, int>> v(n);
    vector<pair<int, int>> num(n);

    for(int i=0;i<n;++i){
        cin>>from>>to;
        num.push_back({from, to});
    }
    sort(num.begin(), num.end());

    for(int i=0;i<n;++i){
        v[i] = {1, i};
        for(int j=0;j<i;++j){
            if(num[i].second > num[j].second){
                if(v[i].first < v[j].first + 1){
                    v[i] = {v[j].first + 1, j};
                }
            }
        }
        if(ansVal < v[i].first){
            ansVal = v[i].first;
            ansIdx = i;
        }
    }

    for(auto a : v){
        cout<<a.first<<" ";
        cout<<a.second<<"\n";
    }
    cout<<ansVal<<"\n"<<ansIdx;
    return 0;
}

