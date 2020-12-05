#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;

bool isInQueue[501];
int cycleCheck[501];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, from , to, w, vSize;

    cin>>n>>m;
    vector<vector<pair<int, int>>> v(n+1);
    vector<long long> weight(n+1, INF);
    queue<int> q;

    for(int i=0;i<m;++i){
        cin>>from>>to>>w;
        v[from].push_back({to, w});
    }

    weight[1] = 0;
    q.push(1);
    isInQueue[1] = true;
    while(!q.empty()){
        from = q.front();
        q.pop();
        isInQueue[from] = false;

        vSize = v[from].size();
        for(int i=0;i<vSize;++i){
            to = v[from][i].first;
            w = v[from][i].second;

            if(weight[to] > weight[from] + w){
                weight[to] = weight[from] + w;
                if(!isInQueue[to]){
                    ++cycleCheck[to];
                    if(cycleCheck[to] >= n){
                        cout<<-1;
                        return 0;
                    }
                    q.push(to);
                    isInQueue[to] = true;
                }
            }
        }
    }

    for(int i=2;i<=n;++i){
        if(weight[i] == INF){
            cout<<-1<<"\n";
        }else{
            cout<<weight[i]<<"\n";
        }
    }

    return 0;
}
