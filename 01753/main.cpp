#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 3000000
using namespace std;

struct edge{
    int end;
    int weight;
};

vector<edge> vertex[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int v, e, initial;
int  dijkstra[20001];

int main() {
    int a, b, c, start, path, eSize, nextS, nextP;

    scanf("%d %d %d", &v, &e, &initial);
    for(int i=0;i<e;++i){
        scanf("%d %d %d", &a, &b, &c);
        vertex[a].push_back({b, c});
    }

    for(int i=1;i<=v;++i){
        dijkstra[i] = INF;
    }

    pq.push({0, initial});
    dijkstra[initial] = 0;
    while(!pq.empty()){
        start = pq.top().second;
        path = pq.top().first;
        eSize = vertex[start].size();
        pq.pop();

        for(int i=0;i<eSize;++i){
            nextS = vertex[start][i].end;
            nextP = vertex[start][i].weight + path;

            if(nextP < dijkstra[nextS]){
                dijkstra[nextS] = nextP;
                pq.push({nextP, nextS});
            }
        }
    }

    for(int i=1;i<=v;++i){
        if(dijkstra[i] == INF){
            printf("INF\n");
        }else{
            printf("%d\n", dijkstra[i]);
        }
    }

    return 0;
}
