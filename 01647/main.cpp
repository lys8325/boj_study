#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge {
    int start, end, cost;
    bool operator < (const Edge &other) const {
        return cost < other.cost;
    }
};

int Parent[100001];

int Find(int x){
    if (x == Parent[x]){
        return x;
    }
    return Parent[x] = Find(Parent[x]);
}

bool Merge(int x, int y){
    x = Find(x);
    y = Find(y);

    if (x == y) return false;
    Parent[x] = y;
    return true;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++){
        Parent[i] = i;
    }

    vector<Edge> E;
    for (int i = 0; i < M; i++){
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        E.push_back({from, to, cost});
    }

    sort(E.begin(), E.end());
    int ans = 0;
    int cnt = 0;

    for (int i = 0; i < M; i++){
        Edge cur = E[i];

        if (Merge(cur.start, cur.end)){
            ans += cur.cost;
            cnt++;
        }

        if (cnt == N - 2){
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}