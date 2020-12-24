#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string name, type;
    int t, n, tmp, ans;

    cin>>t;
    for(int i=0;i<t;++i){
        map<string, int> m;
        vector<int> v;
        ans = 1;

        cin>>n;
        for(int j=0;j<n;++j){
            cin>>name>>type;
            if(m.find(type) == m.end()){
                m[type] = 1;
            }else{
                ++m[type];
            }
        }

        for(auto e : m){
            ans *= (e.second + 1);
        }

        --ans;
        cout<<ans<<"\n";
    }
    return 0;
}
