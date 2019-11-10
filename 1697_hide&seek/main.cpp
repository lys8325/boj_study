#include <iostream>
#include <queue>

# define maxn 100001
using namespace std;
bool road[maxn]={false};
queue<pair<int,int>> position;
int mintime,d,t;int subin,brother;

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
            mintime=min(b,mintime);
            return;
        }

        c=case3(a);
        if(c==brother){
            mintime=b+1;
            return;
        }
        if((c<= maxn)&&(c<=2*brother) && b+1<mintime &&road[c]==false){
            position.push({c,b+1});
            //cout<<c<<" "<<b+1<<"\n";
        }

        c=case1(a);
        if(c==brother){
            mintime=b+1;
            return;
        }
        if((c<= brother) && b+1<mintime &&road[c]==false){
            position.push({c,b+1});
            //cout<<c<<" "<<b+1<<"\n";
        }

        c=case2(a);
        if(c==brother){
            mintime=b+1;
            return;
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
    bfs();
    cout<<mintime<<"\n";
    return 0;
}