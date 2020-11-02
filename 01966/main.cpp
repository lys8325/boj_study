#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m, t, num, target, ans;

    cin>>t;
    for(int i=0;i<t;++i){
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        ans = 0;

        cin>>n>>m;
        for(int j=0;j<n;++j){
            cin>>num;
            if(j == m){
                target  = num;
            }
            pq.push(num);
            q.push({num, j});
        }

        while(true){
            if(q.front().first == target && pq.top() == q.front().first && q.front().second == m){
                cout<<ans+1<<"\n";
                break;
            }else if(q.front().first == pq.top()){
                pq.pop();
                q.pop();
                ++ans;
            }else{
                q.push({q.front().first, q.front().second});
                q.pop();
            }
        }
    }
    return 0;
}
