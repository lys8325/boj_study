#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int n, mid, num;
    cin>>n>>mid;
    cout<<mid<<"\n";
    for(int i=1;i<n;++i){
        cin>>num;
        if(num < mid){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }

        if(maxHeap.size() > minHeap.size()){
            minHeap.push(mid);
            mid = maxHeap.top();
            maxHeap.pop();
        }else if(maxHeap.size() > minHeap.size()){
            maxHeap.push(mid);
            mid = minHeap.top();
            minHeap.pop();
        }
        cout<<mid<<"\n";
    }
    return 0;
}
