#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main() {
    vector<pair<int, int>> v;
    vector<pair<int, int>> used;
    int n, s, e;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s>>e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end(), cmp);

    int lastE = 0;
    for(int i=0;i<n;++i){
        int tmpS = v[i].first;
        int tmpE = v[i].second;

        if(lastE <= tmpS){
            lastE = tmpE;
            used.push_back({tmpS, tmpE});
        }
    }

    cout<<used.size();
    return 0;
}
