#include <iostream>
#include <queue>
using namespace std;

struct position{
    int t;
    int sPos;
    int bPos;
};

int ds[3] = {1, -1, 0};

int main() {
    queue<position> q;
    int curS, curB, nextS, nextB, curT;
    cin>>curS>>curB;

    q.push({0, curS, curB});
    while(!q.empty()){
        curT = q.front().t;
        curS = q.front().sPos;
        curB = q.front().bPos;
        q.pop();
        ds[2] = curS;

        if(curS == curB){
            cout<<curT;
            return 0;
        }

        nextB = curB + curT+1;
        for(int i=0;i<3;++i){
            nextS = curS + ds[i];

            if(nextS < 0 || nextS > 500000 || nextB < 0 || nextB >500000){
                continue;
            }else{
                q.push({curT+1, nextS, nextB});
            }

        }
    }

    cout<<-1;
    return 0;
}
