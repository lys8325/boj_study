#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    queue<int> q;
    int n, m, target, qSize, num, ans = 0;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        q.push(i);
    }
    for(int i=0;i<m;++i){
        cin>>target;

        qSize = q.size();
        num = 0;
        while(q.front() != target){
            q.push(q.front());
            q.pop();
            ++num;
        }

        q.pop();
        ans += min(num, qSize-num);
    }

    cout<<ans;
    return 0;
}
