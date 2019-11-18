#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int> , vector<pair<int,int>>, greater<pair<int,int>>> end_info;
priority_queue<pair<int, int> , vector<pair<int,int>>, greater<pair<int,int>>> time_info;
priority_queue<int,vector<int>,greater<int>> pc_list;
int n,s,e,pc_num;

using namespace std;
int main() {
    int temp;
    int arr[100001]={0};
    bool check[100001]={false};
    pc_num=0;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s>>e;
        time_info.push({s,e});
    }
    for(int i=2;i<=100000;++i){
        pc_list.push(i);
    }
    end_info.push({-1, 1});
    check[1]=true;
    while(!time_info.empty()){
        while(time_info.top().first >= end_info.top().first && !end_info.empty() ){
            check[end_info.top().second]= false;
            pc_list.push(end_info.top().second);
            end_info.pop();
        }
        temp=pc_list.top();
        check[temp]=true;
        pc_list.pop();
        end_info.push({time_info.top().second, temp});
        ++arr[temp];
        pc_num=max(pc_num, temp);
        time_info.pop();
    }
    cout << pc_num << "\n";

    for(int j=1; j <= pc_num; ++j){
        cout<<arr[j]<<" ";
    }
    return 0;
}