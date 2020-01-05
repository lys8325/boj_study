#include <iostream>
#include <queue>
#define maxN 1000
#define maxM maxN*(maxN-1)/2

using namespace std;

queue<int> vertex;
bool visit[maxN+1]; // 이미 방문한( 어떠한 세트에 포함된 ) 정점 체크
bool adjacent[maxN+1][maxN+1]; // 인접행렬
int N,M,answer;
// N = 정점 수, M = 간선 수, answer = 정답
void bfs(){
    int v;
    while(!vertex.empty()){ // 정점 큐가 비지 않을 때 까지 연결된 정점을 큐에 넣는다.
        v = vertex.front();
        visit[v]= true; // 조사중인 정점은 임의의 세트에 연결되어있음!
        vertex.pop();
        for(int i=1;i<=N;++i){
            if(adjacent[v][i] && !visit[i]){ // 정점간 간선으로 연결되어 있고, 아직 어느 세트에도 포함되어 있지 않은 경우
                vertex.push(i); // 큐에 넣고
                visit[i] = true; // 방문 표시
            }
        }
    }
    ++answer; // 연결된 세트의 수 추가
}

int main() {
    int a,b;
    cin>>N>>M;
    answer=0;
    for(int i=0;i<M;++i){ // 그래프 간선 수 만큼 반복하여 인접행렬 작성
        cin>>a>>b;
        adjacent[a][b]= true;
        adjacent[b][a]= true;
    }
    for(int i=1;i<=N;++i){ // 모든 정점을 돌면서 연결 세트를 찾는다.
        if(!visit[i]){ // 이미 방문한 정점은 이미 어느 세트에 연결되어 있으므로 조사되어있으므로 스킵한다.
            vertex.push(i);
            bfs();
        }
    }
    cout<<answer; // 정답 출력
    return 0;
}