#include <iostream>
#include <queue>
using namespace std;

int findParent(int parent[], int n){
    if(n == parent[n]){
        return n;
    }

    return parent[n] = findParent(parent, parent[n]);
}

void unionSet(int parent[], int n1, int n2){
    int parent1 = findParent(parent, n1);
    int parent2 = findParent(parent, n2);

    if(parent1 < parent2){
        parent[parent2] = parent1;
    }else{
        parent[parent1] = parent2;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int v, e, w, from, to, sum = 0, numEdge = 0;
    int parent[10001];
    cin>>v>>e;
    for(int i=1;i<=v;++i){
        parent[i] = i;
    }

    for(int i=0;i<e;++i){
        cin >> from >> to >> w;
        pq.push({w, {from, to}});
    }

    while(numEdge < v-1){
        w = pq.top().first;
        from = pq.top().second.first;
        to = pq.top().second.second;
        pq.pop();

        if(findParent(parent, from) != findParent(parent, to)){
            sum += w;
            unionSet(parent, from, to);

            ++numEdge;
        }
    }

    cout<<sum;
    return 0;
}
