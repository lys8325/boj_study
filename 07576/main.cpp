#include <iostream>
#include <queue>

#define maxsize 1000
using namespace std;
struct info{
    int y;
    int x;
    int d;
};

queue<info> Q;

int m,n,day,num,check_num;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

int box[maxsize][maxsize];
bool visit[maxsize][maxsize]={false};

int check(){
    check_num=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(box[i][j]==1){
                ++check_num;
            }
        }
    }
    if(num == check_num){
        return 1;
    }
    else{
        return -1;
    }
}

void effect(int row,int col, int date){
    int tempy,tempx;
    for(int a=0;a<4;++a){
        tempy=row+dy[a];
        tempx=col+dx[a];
        if(tempy>=0 && tempy<n && tempx>=0 && tempx<m && !visit[tempy][tempx] && box[tempy][tempx]==0){
            visit[tempy][tempx]=true;
            Q.push({tempy,tempx,date+1});
            box[tempy][tempx]=1;
        }
    }
}

void bfs(){
    int ty,tx,td;
    while(!Q.empty()){
        ty=Q.front().y;
        tx=Q.front().x;
        td=Q.front().d;
        day=td;
        Q.pop();
        effect(ty,tx,td);
    }
}

int main() {
    int result=0;
    cin>>m>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>box[i][j];
            if(box[i][j]!=-1){
                ++num;
                if(box[i][j]==1){
                    visit[i][j]=true;
                    Q.push({i,j,0});
                }
            }
        }
    }

    result=check();
    if(result==1){
        day=0;
    }
    else{
        bfs();
        result=check();
        if(result==-1){
            day=-1;
        }
    }
    cout<<day;
    return 0;
}