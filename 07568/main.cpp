#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> v;
    int n, w, h, rank;
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>w>>h;
        v.push_back({w, h});
    }

    for(int i=0;i<n;++i){
        rank = 0;
        for(int j=0;j<n;++j){
            if(i == j){
                continue;
            }
            if(v[i].first < v[j].first && v[i].second < v[j].second){
                ++rank;
            }
        }
        cout<<rank+1<<" ";
    }
    return 0;
}
