#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n, tmp, idx = 0;
    vector<int> v;
    vector<char> ans;
    stack<int> s;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>tmp;
        v.push_back(tmp);
    }

    for(int i=1;i<=n;++i){
        s.push(i);
        ans.push_back('+');

        while(!s.empty() && v[idx] == s.top()){
            s.pop();
            ans.push_back('-');
            ++idx;
        }
    }

    int len = ans.size();
    if(s.empty()){
        for(int i=0;i<len;++i){
            cout<<ans[i]<<"\n";
        }
    }else{
        cout<<"NO\n";
    }
    return 0;
}