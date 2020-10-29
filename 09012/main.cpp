#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        stack<int> s;
        string str;
        char c;
        cin>>str;
        int len = str.length();

        for(int j=0;j<len;++j){
            c = str[j];
            if(c == '('){
                s.push(c);
            }else{
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }else{
                    s.push(c);
                }
            }
        }

        if(s.empty()){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
