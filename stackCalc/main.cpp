#include <iostream>
#include <stack>
#include <map>
using namespace std;

int main() {
    string originStr;
    string postfixStr;
    stack<int> s;
    map<char, int> m;
    m['*'] = 1;
    m['/'] = 1;
    m['+'] = 2;
    m['-'] = 2;
    m['('] = 0;

    cin>>originStr;
    for(char c : originStr){
        if(c == '('){
            s.push(c);
        }else if(c == ')'){
            while(s.top() != '('){
                postfixStr.push_back(s.top());
                s.pop();
            }
            s.pop();
        }else if(48 < c && c < 58){
            postfixStr.push_back(c);
        }else{
            if(s.empty()){
                s.push(c);
            }else{
                if(m[s.empty()] > m[c]){
                    postfixStr.push_back(s.top());
                    s.pop();
                }
                s.push(c);
            }
        }
    }

    while(!s.empty()){
        postfixStr.push_back(s.top());
        s.pop();
    }

    cout<<postfixStr<<"\n";

    int operand1, operand2;
    for(char c : postfixStr){
        if(48<c && c<58){
            s.push(c-48);
        }else{
            operand2 = s.top();
            s.pop();
            operand1 = s.top();
            s.pop();
            if(c == '*'){
                s.push(operand1 * operand2);
            }else if(c == '/'){
                s.push(operand1 / operand2);
            }else if(c == '+'){
                s.push(operand1 + operand2);
            }else if(c == '-'){
                s.push(operand1 - operand2);
            }
        }
    }

    cout<<s.top();
    return 0;
}
