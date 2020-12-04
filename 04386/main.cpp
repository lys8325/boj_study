#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> pq;
vector<pair<float, float>> v(1,{0,0});
bool visit[101];

void addEdge(int to){
    int vSize = v.size();
    float toX = v[to].first;
    float toY = v[to].second;

    for(int i=1;i<vSize;++i){
        if(!visit[i]){
            float dx = abs(v[i].first - toX);
            float dy = abs(v[i].second - toY);
            float d = sqrt(pow(dx,2) + pow(dy, 2));

            pq.push({d, i});
        }
    }
}

int main() {
    int n, to, edgeNum = 0;
    float x, y, sum = 0;

    scanf("%d", &n);
    for(int i=1;i<=n;++i){
        scanf("%f %f", &x, &y);
        v.push_back({x, y});
    }

    visit[1] = true;
    addEdge(1);
    while(edgeNum < n-1){
        while(visit[pq.top().second]){
            pq.pop();
        }
        sum += pq.top().first;
        to = pq.top().second;
        pq.pop();
        visit[to] = true;
        addEdge(to);

        ++edgeNum;
    }

    printf("%.2f", sum);
    return 0;
}
