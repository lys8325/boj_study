#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[101];

int main() {
    int n, m, src, dst, dstSize, ans = 0;

    vector<int> network[101];
    queue<int> q;

    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>src>>dst;
        network[src].push_back(dst);
        network[dst].push_back(src);
    }

    q.push(1);
    visit[1] = true;
    while(!q.empty()){
        src = q.front();
        q.pop();

        dstSize = network[src].size();
        for(int i=0;i<dstSize;++i){
            dst = network[src][i];
            if(!visit[dst]){
                q.push(dst);
                visit[dst] = true;
                ++ans;
            }
        }
    }

    cout<<ans;
    return 0;
}
