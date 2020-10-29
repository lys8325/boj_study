#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int n, num, ans = 0;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num;
        if(num != 0){
            s.push(num);
        }else{
            s.pop();
        }
    }

    while(!s.empty()){
        ans += s.top();
        s.pop();
    }

    cout<<ans;
    return 0;
}
