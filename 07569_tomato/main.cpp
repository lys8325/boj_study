#include <iostream>
#include <queue>

#define maxsize 100
using namespace std;

int box[maxsize][maxsize][maxsize]={0};
bool calc[maxsize][maxsize][maxsize]={false};

struct info{
    int ir;
    int ic;
    int ih;
    int id;
};

queue<info> Q;

int day,num,num_check,past_num;
int m,n,h,result;

int dy[6]={-1,1,0,0,0,0};
int dx[6]={0,0,-1,1,0,0};
int dh[6]={0,0,0,0,1,-1};

int check(){
    num_check=0;
    for(int i=0;i<h;++i){
        for(int j=0;j<n;++j){
            for(int p=0;p<m;++p){
                if(box[j][p][i] == 1){
                    ++num_check;
                }
            }
        }
    }
    if(num_check == num){
        return 1;
    }
    else{
        return  -1;
    }
}

void effect(int row,int col, int hei,int dd){
    int tr,tc,th;
    for(int a=0;a<6;++a){
        tr=row+dy[a];
        tc=col+dx[a];
        th=hei+dh[a];

        if((tr >= 0)&&(tr<n)&&(tc >= 0)&&(tc<m)&&(th >= 0)&&(th<h)&& box[tr][tc][th] == 0 && !calc[tr][tc][th]){
            Q.push({tr,tc,th,dd+1});
            calc[tr][tc][th]=true;
            box[tr][tc][th]=1;

            //cout<<tr<<" ";cout<<tc<<" ";cout<<th<<"\n";
        }
    }
}

void dayafter(){
    int t1,t2,t3,t4;
    while(!Q.empty()){
        t1=Q.front().ir;
        t2=Q.front().ic;
        t3=Q.front().ih;
        t4=Q.front().id;
        day=t4;
        Q.pop();
        effect(t1,t2,t3,t4);
    }
}

int main() {
    cin>>m>>n>>h;

    for(int i=0;i<h;++i){
        for(int j=0;j<n;++j){
            for(int p=0;p<m;++p){
                cin>>box[j][p][i];
                if(box[j][p][i] != -1){
                    if(box[j][p][i]==1){
                        Q.push({j,p,i,0});
                        calc[j][p][i]= true;
                    }
                    ++num;
                }
            }
        }
    }
    result=check();
    if(result==1){
        day=0;
    }
    else{
        dayafter();
        result = check();
        /*
        for(int i=0;i<h;++i){
            for(int j=0;j<n;++j){
                for(int p=0;p<m;++p){
                    cout<<box[j][p][i]<<" ";
                }
                cout<<"\n";
            }
            cout<<"-----------------\n";
        }cout<<"\n";
        */
        if(result == -1){
            day=-1;
        }
    }
    cout<<day;
    return 0;
}