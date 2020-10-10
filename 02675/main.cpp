#include <iostream>
#include <string>
using namespace std;

int main() {
    int t, r, l;
    string str;
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>r>>str;
        l = str.length();

        string ans;
        for(int j=0;j<l;++j){
            ans.append(r, str[j]);
        }
        cout<<ans<<"\n";
    }

    return 0;
}
