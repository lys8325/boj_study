#include <iostream>
#include <queue>
#include <algorithm>

# define maxn 100001
using namespace std;
bool road[maxn]={false};
queue<pair<int,int>> position;
int mintime,d,t;int subin,brother;
int answer;

int case1(int p){
    return p+1;
}
int case2(int p){
    return p-1;
}
int case3(int p){
    return p*2;
}

void bfs(){
    int a,b,c;
    while(!position.empty()){
        a=position.front().first;
        b=position.front().second;
        position.pop();
        road[a]=true;
        if(a==brother){
            //++answer;
        }

        c=case3(a);
        if(c==brother){
            mintime=min(mintime,b+1);
            if(b+1 == mintime){
                ++answer;
            }
        }
        if((c<= maxn)&&(c<=2*brother) && b+1<mintime &&road[c]==false){
            position.push({c,b+1});
            //cout<<c<<" "<<b+1<<"\n";
        }

        c=case1(a);
        if(c==brother){
            mintime=min(mintime,b+1);
            if(b+1 == mintime){
                ++answer;
            }
        }
        if((c<= brother) && b+1<mintime &&road[c]==false){
            position.push({c,b+1});
            //cout<<c<<" "<<b+1<<"\n";
        }

        c=case2(a);
        if(c==brother){
            mintime=min(mintime,b+1);
            if(b+1 == mintime){
                ++answer;
            }
        }
        if((c >= 0) && b+1<mintime &&road[c]==false){
            position.push({c,b+1});
            //cout<<c<<" "<<b+1<<"\n";
        }
    }
}

int main() {

    cin>>subin>>brother;
    road[brother]=true;
    d=abs(subin-brother);
    t=0;
    mintime=d;
    position.push({subin,t});
    answer=0;
    if(subin==brother){
        mintime=0;
        answer=1;
    }
    else{
        bfs();
    }
    cout<<mintime<<"\n";
    cout<<answer;
    return 0;
}