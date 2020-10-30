#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    int len;
    char c;

    while(1){
        stack<char> s;
        getline(cin,str);
        if(str == "."){
            break;
        }

        len = str.length();
        for(int i=0;i<len;++i){
            c = str[i];
            if(c == '(' || c == '['){
                s.push(c);
            }else if(c == ')'){
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }else{
                    s.push(c);
                }
            }else if(c == ']'){
                if(!s.empty() && s.top() == '['){
                    s.pop();
                }else{
                    s.push(c);
                }
            }
        }

        if(s.empty()){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
    return 0;
}
