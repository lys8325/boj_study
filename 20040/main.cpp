#include <iostream>
using namespace std;

int n, m;
int parent[500000];

int findParent(int v){
    if(parent[v] == v){
        return v;
    }

    return parent[v] = findParent(parent[v]);
}

bool unionGroup(int s, int e){
    int parentS = findParent(s);
    int parentE = findParent(e);

    if(parentS == parentE){
        return true;
    }

    if(parentS < parentE){
        parent[parentE] = parentS;
    }else{
        parent[parentS] = parentE;
    }

    return false;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<n;++i){
        parent[i] = i;
    }

    int s, e;
    for(int i=1;i<=m;++i){
        cin>>s>>e;
        if(unionGroup(s, e)){
            cout<<i;
            return 0;
        }
    }

    cout<<0;
    return 0;
}