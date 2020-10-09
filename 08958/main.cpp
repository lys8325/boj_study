#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, len, cnt, ans;
    string str;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>str;
        len = str.length();
        cnt = 0;
        ans = 0;
        for(int j=0;j<len;++j){
            if(str[j] == 'O'){
                ++cnt;
                ans += cnt;
            }else{
                cnt = 0;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
