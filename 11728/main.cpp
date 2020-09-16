#include <iostream>
using namespace std;

int n, m;
int a[1000000];
int b[1000000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<m;++i){
        cin>>b[i];
    }

    int indexA=0,indexB=0;
    while(indexA < n && indexB < m){
        if(a[indexA] >= b[indexB]){
            cout<<b[indexB++]<<" ";
        }else{
            cout<<a[indexA++]<<" ";
        }
    }
    if(indexA == n){
        while(indexB < m){
            cout<<b[indexB++]<<" ";
        }
    }else{
        while(indexA < n){
            cout<<a[indexA++]<<" ";
        }
    }

    return 0;
}
