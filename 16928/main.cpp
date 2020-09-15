#include <iostream>
#include <queue>
#include <map>
#define maxNM 15

using namespace std;
int n,m;
map<int,int> ladder;
map<int,int> snake;
queue<pair<int,int>> position;
bool visit[101]= {false};
int answer = 0;

int findAnswerBfs(){
    int p,a;
    position.push({1,0});
    visit[1] = true;
    while(!position.empty()){
        p = position.front().first;
        a = position.front().second;
        position.pop();
        for(int i=6;i>0;--i){
            if(p+i == 100){
                answer = a+1;
                return answer;
            }
            else if(p+i > 100 || visit[p+i]){
                continue;
            }
            else if(ladder.find(p+i) != ladder.end()){
                position.push({ladder.find(p+i)->second,a+1});
                visit[ladder.find(p+i)->second] = true;
            }
            else if(snake.find(p+i) != snake.end()) {
                position.push({snake.find(p+i)->second,a+1});
                visit[snake.find(p+i)->second] = true;
            }
            else{
                position.push({p+i,a+1});
            }
            visit[p+i] = true;
        }
    }
}

int main() {
    cin>>n>>m;
    int k,v;
    for(int i=0;i<n;++i){
        cin>>k>>v;
        ladder[k] = v;
    }
    for(int i=0;i<m;++i){
        cin>>k>>v;
        snake.insert(make_pair(k,v));
    }
    cout<<findAnswerBfs();
    return 0;
}
