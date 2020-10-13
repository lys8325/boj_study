#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool stableSort(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main() {
    vector<pair<int, string>> v;
    int n, age;
    string name;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>age>>name;
        v.push_back({age, name});
    }

    stable_sort(v.begin(), v.end(), stableSort);

    for(int i=0;i<n;++i){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }

    return 0;
}