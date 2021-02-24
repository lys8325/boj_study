#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    set<int> s;
    int n, num;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num;
        s.insert(num);
    }

    for(auto i : s){
        cout<<i<<" ";
    }
    return 0;
}
