#include <iostream>
#include <queue>

#define MAXN 100

using namespace std;

int map[MAXN][MAXN];
bool visit[MAXN][MAXN]={false};

queue<int> Q;
int n,v;

void findanswer(int i){
    Q.push(i);
    while(!Q.empty()){
      v=Q.front();
      Q.pop();
      for(int j=0;j<n;++j){
          if((map[v][j]==1||map[v][j]==2) && !visit[i][j] ){
              visit[i][j]=true;
              map[i][j]=2;
              Q.push(j);
          }
      }
  }
}

int main() {
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>map[i][j];
        }
    }
    for(int index=0;index<n;++index){
        findanswer(index);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(map[i][j]==2){
                cout<<"1";
            }
            else{
                cout<<map[i][j];
            }
            if(j==n-1){
                cout<<"\n";
            }
            else{
                cout<<" ";
            }
        }
    }

    return 0;
}