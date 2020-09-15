#include <iostream>
#include <queue>

#define max_n 1001

using namespace std;
int graph[max_n][max_n]={0};
bool visit[max_n]={false};
bool visit2[max_n]={false};
int n,e,s,y,x;
queue<int> Q;
queue<int> Q2;

void dfs(int start){
    for(int j=1;j<=n;++j){
        if(!visit[j] && graph[start][j]==1) {
            Q.push(j);
            visit[j] = true;
            dfs(j);
        }
    }
}

void bfs(){
    while(!Q.empty()){
        y=Q.front();
        Q.pop();
        for(int j=1;j<=n;++j){
            if(!visit2[j]&&graph[y][j]==1){
                Q.push(j);
                Q2.push(j);
                visit2[j]=true;

            }
        }
    }
}

int main() {
    cin>>n>>e>>s;
    int temp;
    for(int i=0;i<e;++i){
        cin>>y>>x;
        graph[y][x]=1;
        graph[x][y]=1;
    }

    visit[s]=true;
    Q.push(s);
    dfs(s);

    while(!Q.empty()){
       temp=Q.front();
       Q.pop();
       cout<<temp<<" ";
    }
    cout<<"\n";

    visit2[s]=true;
    Q.push(s);
    Q2.push(s);
    bfs();

    while(!Q2.empty()){
        temp=Q2.front();
        Q2.pop();
        cout<<temp<<" ";
    }

    return 0;
}