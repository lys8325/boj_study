#include <iostream>

#define maxsize 100
using namespace std;

int box[maxsize][maxsize][maxsize]={0};
bool calc[maxsize][maxsize][maxsize]={false};

int day,num,num_check,past_num;
int m,n,h,result;

int dy[6]={-1,1,0,0,0,0};
int dx[6]={0,0,-1,1,0,0};
int dh[6]={0,0,0,0,1,-1};

void reset(){
    for(int i=0;i<h;++i){
        for(int j=0;j<n;++j){
            for(int p=0;p<m;++p){
                calc[j][p][i]=false;
            }
        }
    }
}

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
    if(past_num==num_check){
        return -1;
    }

    if(num_check == num){
        return 1;
    }
    else{
        past_num=num_check;
        return 2;
    }

}

void effect(int row,int col, int hei){
    int tr,tc,th;
    for(int a=0;a<6;++a){
        tr=row+dy[a];
        tc=col+dx[a];
        th=hei+dh[a];

        if((tr >= 0)&&(tr<n)&&(tc >= 0)&&(tc<m)&&(th >= 0)&&(th<h)&& box[tr][tc][th] == 0){

            calc[tr][tc][th]=true;

            //cout<<tr<<" ";cout<<tc<<" ";cout<<th<<"\n";
        }
    }
}

void dayafter(){
    ++day;
    for(int i=0;i<h;++i){
        for(int j=0;j<n;++j){
            for(int p=0;p<m;++p){
                if(box[j][p][i] == 1){
                    effect(j,p,i);
                }
            }
        }
    }

    for(int i=0;i<h;++i){
        for(int j=0;j<n;++j){
            for(int p=0;p<m;++p){
                if(calc[j][p][i]){
                    box[j][p][i]=1;
                }
            }
        }
    }

    reset();

}

int main() {
    cin>>m>>n>>h;

    for(int i=0;i<h;++i){
        for(int j=0;j<n;++j){
            for(int p=0;p<m;++p){
                cin>>box[j][p][i];
                if(box[j][p][i] != -1){
                    ++num;
                }
            }
        }
    }
    past_num=0;

    result=check();
    if(result==1){
        day=0;
    }
    else{
        while(true){
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
            if(result == 1) break;
            if(result ==-1){
                day=-1;
                break;
            }
        }
    }

    cout<<day;
    return 0;
}

