#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<pair<int, int> , vector<pair<int,int>>, greater<pair<int,int>>> en;
priority_queue<pair<int, int> , vector<pair<int,int>>, greater<pair<int,int>>> info;
priority_queue<pair<int, int> , vector<pair<int,int>>, greater<pair<int,int>>> num;
int n,s,e,p;

using namespace std;
int main() {
    int temp;
    int ne;int arr[100001]={0};
    bool check[100001]={false};
    p=0;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s>>e;
        info.push({s,e});
    }
    en.push({-1,1});
    check[1]=true;
    while(!info.empty()){
        while(info.top().first >= en.top().first && !en.empty() ){
            check[en.top().second]= false;
            en.pop();
        }
       for(int i=1;i<=100000;++i){
           if(!check[i]){
               temp=i;
               break;
           }
       }
        check[temp]=true;
        en.push({info.top().second,temp});
        ++arr[temp];
        p=max(p,temp);
        info.pop();
    }
    //p=en.size();
    cout<<p<<"\n";

    for(int j=1;j<=p;++j){
        cout<<arr[j]<<" ";
    }
    return 0;
}