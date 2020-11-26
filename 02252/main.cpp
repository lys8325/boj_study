#include <iostream>
#include <vector>;
#include <queue>
using namespace std;

bool visit[32001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, a, b, cur;
    cin>>n>>m;

    queue<int> topology, ans;
    priority_queue<int, vector<int>, greater<int>> zeroList;
    vector<int> edgeIn(n+1, 0);
    vector<vector<int>> edge(n+1);

    for(int i=0;i<m;++i){
        cin>>a>>b;
        edge[a].push_back(b);
        ++edgeIn[b];
    }

    for(int i=1;i<=n;++i){
        if(edgeIn[i] == 0){
            zeroList.push(i);
        }
    }

    if(!zeroList.empty()){
        topology.push(zeroList.top());
        zeroList.pop();
    }

    while(!topology.empty()){
        cur = topology.front();
        topology.pop();
        ans.push(cur);
        visit[cur] = true;

        for(int i : edge[cur]){
            --edgeIn[i];
            if(edgeIn[i] == 0){
                zeroList.push(i);
            }
        }

        if(!zeroList.empty()){
            topology.push(zeroList.top());
            zeroList.pop();
        }
    }

    for(int i=1;i<=n;++i){
        if(!visit[i]){
            ans.push(i);
        }
    }

    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }

    return 0;
}