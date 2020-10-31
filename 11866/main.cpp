#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k, idx = 0;
    queue<int> q, ans;

    cin>>n>>k;

    if(n == 1){
        cout<<"<1>";
        return 0;
    }

    for(int i=1;i<=n;++i){
        q.push(i);
    }

    --k;
    while(idx < n){
        for(int i=0;i<k;++i){
            q.push(q.front());
            q.pop();
        }
        ans.push(q.front());
        q.pop();
        ++idx;
    }

    for(int i=0;i<n;++i){
        if(i == 0){
            cout<<"<"<<ans.front()<<", ";
        }else if (i == n-1){
            cout<<ans.front()<<">";
        }else{
            cout<<ans.front()<<", ";
        }
        ans.pop();
    }

    return 0;
}
