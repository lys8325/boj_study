#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int isMember[100001];

struct line{
    int from;
    int to;
};

bool cmp(line a, line b){
    return a.from < b.from;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, from, to, ansVal = 0, ansIdx = 0;
    cin>>n;

    vector<line> num;
    vector<int> v;
    vector<int> seq;
    stack<int> s;

    for(int i=0;i<n;++i){
        cin>>from>>to;
        num.push_back({from, to});
    }
    sort(num.begin(), num.end(), cmp);

    v.push_back(0);
    for(int i=0;i<n;++i){
        if(v.back() < num[i].to){
            v.push_back(num[i].to);
            seq.push_back(v.size()-1);
        }else{
            auto iter = lower_bound(v.begin(), v.end(), num[i].to);
            *iter = num[i].to;
            seq.push_back(iter - v.begin());
        }
    }

    int ans = v.size()-1;
    cout<<n - ans<<"\n";

    for(int i=n-1;i>=0;--i){
        if(seq[i] == ans){
            --ans;
        }else{
            s.push(i);
        }
    }

    while(!s.empty()){
        cout<<num[s.top()].from<<"\n";
        s.pop();
    }
    return 0;
}