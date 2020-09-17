#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct edge{
    int end;
    int value;
};

int n, m, k;
vector<edge> edge[1001]; // 간선 정보, edge[시작점] = { 도착점, 가중치 }
priority_queue<int> vertex[1001]; // 1로 시작해서 [인덱스 정점] 으로 도달했을 때까지의 경로 길이,
                                  // 긴 경로 길이 순서로 저장되며, k 개 까지만 저장 되도록 관리
                                  // 현재 구한 경로 길이가 k 개 까지 찬 pq[정점] top 보다 작다면 pop & push
                                  // => top 이 k 번째 경로!
queue<pair<int, int>> q; // 경로상의 좌표 정
void dijkstra(){
    int start, value, eSize, nextS, nextV, pCount;
    vertex[1].push(0); // 1 -> 1 인 k 번째 경로를 구해야할 때, 항상 1번째 경로 길이는 0이다.
    q.push(make_pair(1,0)); // 경로의 시작은 1, 가중치 0
    while(!q.empty()){
        start = q.front().first;
        value = q.front().second;
        eSize = edge[start].size();
        q.pop();
        for(int i=0;i<eSize;++i){
            nextS = edge[start][i].end;
            nextV = value + edge[start][i].value;
            pCount = vertex[nextS].size(); // 현재 pq[도착정점] 에 저장된 경로 길이의 개수.

            if(pCount < k){ // 개수가 아직 k 개가 안되었다면
                vertex[nextS].push(nextV); // 무조건 삽입
                q.push(make_pair(nextS, nextV));
            }else if(vertex[nextS].top() > nextV){ // k개가 이미 구해졌지만 그 중 최대값 보다
                                                   // 짧은 경로가 발견되었다면, pop & push
                vertex[nextS].pop();
                vertex[nextS].push(nextV);
                q.push(make_pair(nextS, nextV));
            } // 위 조건들에 해당하지 않으면 즉, 이미 k개의 경로길이가 구해졌고 지금 구한 nextV도 pq.top 보다 길다면
              // k+1 번째 이상의 경로 길이이기 때문에 조사할 필요 없음.
        }
    }
    // 1에서 모든 정점까지의 k개의 경로를 구했다면 출력.
    for(int i=1;i<=n;++i){
        if(vertex[i].size()<k){ // k개의 경로가 존재하지 않는다면 -1 출력
            printf("-1\n");
        }else{ // 아니면 k 번째 즉, pq[정점].top 출력.
            printf("%d\n", vertex[i].top());
        }
    }
}

int main() {
    int s,e,v;

    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<m;++i){
        scanf("%d %d %d", &s, &e, &v);
        edge[s].push_back({e,v});
    }
    dijkstra();
    return 0;
}

