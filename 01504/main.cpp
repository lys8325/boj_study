#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#define INF 160000001
using namespace std;

int n, e;
vector<pair<int, int>> vList[801];

int cost[3][801];
int start[3];

void sol(){
    for(int i=0;i<3;++i){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        int s = start[i];
        int v, w, eNum, nextV, nextW;

        pq.push({0,s});
        while(!pq.empty()){
            w = pq.top().first;
            v = pq.top().second;
            pq.pop();
            eNum = vList[v].size();

            for(int j=0;j<eNum;++j){
                nextW = vList[v][j].first;
                nextV = vList[v][j].second;

                if(w + nextW < cost[i][nextV]){
                    cost[i][nextV] = w + nextW;
                    pq.push({cost[i][nextV], nextV});
                }
            }
        }
    }

    return;
}

int main() {
    int from, to, w, tmp1, tmp2, ans;
    cin>>n>>e;
    for(int i=0;i<e;++i){
        cin>>from>>to>>w;
        vList[from].push_back({w, to});
        vList[to].push_back({w, from});
    }
    start[0] = 1;
    cin>>start[1]>>start[2];

    for(int i=1;i<=n;++i){
        cost[0][i] = INF;
        cost[1][i] = INF;
        cost[2][i] = INF;
    }
    cost[0][1] = 0;
    cost[1][start[1]] = 0;
    cost[2][start[2]] = 0;

    sol();

    if(cost[0][start[1]] == INF || cost[1][start[2]] == INF || cost[2][n] == INF){
        tmp1 = INF;
    }else{
        tmp1 = cost[0][start[1]]+cost[1][start[2]]+cost[2][n];
    }

    if(cost[0][start[2]] == INF || cost[2][start[1]] == INF || cost[1][n] == INF){
        tmp2 = INF;
    }else{
        tmp2 = cost[0][start[2]]+cost[2][start[1]]+cost[1][n];
    }

    if(tmp1 == INF && tmp2 == INF){
        ans = -1;
    }else{
        ans = min(tmp1, tmp2);
    }

    cout<<ans;
    return 0;
}