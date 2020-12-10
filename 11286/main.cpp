#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first){
            return a.second > b.second;
        }

        return a.first > b.first;
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, num, tmp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num;

        if(num == 0){
            if(pq.empty()){
                cout<<0<<"\n";
            }else{
                cout<<pq.top().second<<"\n";
                pq.pop();
            }
        }else{
            pq.push({abs(num), num});
        }
    }

    return 0;
}
