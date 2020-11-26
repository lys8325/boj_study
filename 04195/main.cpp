#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findSet(vector<pair<int, int>> &v, int set){
    if(set == v[set].first){
        return set;
    }

    v[set].first = findSet(v, v[set].first);
    return v[set].first;
}

int unionSet(vector<pair<int, int>> &v, int set1, int set2){
    int parent1 = findSet(v, set1);
    int parent2 = findSet(v, set2);

    if(parent1 < parent2){
        v[parent2].first = parent1;
        v[parent1].second += v[parent2].second;
        return v[parent1].second;
    }else if(parent1 > parent2){
        v[parent1].first = parent2;
        v[parent2].second += v[parent1].second;
        return v[parent2].second;
    }else{
        return v[parent1].second;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, n, idx, set1, set2;
    string name1, name2;

    cin>>t;
    for(int p=0;p<t;++p){
        cin>>n;
        idx = 1;

        map<string, int> m;
        vector<pair<int, int>> v(1,{0,0});
        for(int i=0;i<n;++i){
            cin>>name1>>name2;
            if(m.find(name1) == m.end()){
                m[name1] = idx;
                v.push_back({idx, 1});
                set1 = idx++;
            }else{
                set1 = m[name1];
            }

            if(m.find(name2) == m.end()){
                m[name2] = idx;
                v.push_back({idx, 1});
                set2 = idx++;
            }else{
                set2 = m[name2];
            }

            cout<<unionSet(v, set1, set2)<<"\n";
        }
    }

    return 0;
}