#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v(1,0);
int n, heapSize;

void heapify(int idx){
    if(heapSize == 0 || idx == 0){
        return;
    }

    int nextIdx = 2 * idx;
    if(nextIdx > heapSize){
        return;
    }

    if(nextIdx+1 <= heapSize){
        if(v[nextIdx] > v[nextIdx+1]){
            ++nextIdx;
        }
    }

    if(v[idx] > v[nextIdx]){
        int tmp = v[idx];
        v[idx] = v[nextIdx];
        v[nextIdx] = tmp;

        heapify(nextIdx);
    }
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, tmp;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num;

        if(num == 0){
//            if(heapSize != 0){
//                cout<<v[1]<<"\n";
//
//                tmp = v[1];
//                v[1] = v[heapSize];
//                v[heapSize] = tmp;
//                v.pop_back();
//                --heapSize;
//                heapify(1);
//            }else{
//                cout<<0<<"\n";
//            }
            if(pq.empty()){
                cout<<0<<"\n";
            }else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }else{
//            v.push_back(num);
//            ++heapSize;
//            heapify(heapSize/2);
            pq.push(num);
        }
    }
    return 0;
}
