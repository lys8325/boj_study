#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }

    return a.first > b.first;
}

int externalArr[500001];

void merge(int arr[], int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int idx = left;

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            externalArr[idx++] = arr[i++];
        }else{
            externalArr[idx++] = arr[j++];
        }
    }

    if(i > mid){
        while(j <= right){
            externalArr[idx++] = arr[j++];
        }
    }else{
        while(i <= mid){
            externalArr[idx++] = arr[i++];
        }
    }

    idx = left;
    while(idx <= right){
        arr[idx] = externalArr[idx];
        ++idx;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, tmp, maxNum, bias = 4000;
    int arr[500001];
    double sum = 0;
    vector<pair<int, int>> v(8001, {0,0});

    cin>>n;
    for(int i=1;i<=n;++i){
        cin >> tmp;
        arr[i] = tmp;
        sum += tmp;
        v[tmp+bias] = {v[tmp+bias].first+1, tmp};
    }

    mergeSort(arr, 1, n);
    sort(v.begin(), v.end(), cmp);

    cout<<round(sum/n)<<"\n";
    cout<<arr[(1 + n) / 2]<<"\n";
    if(v[0].first == v[1].first){
        cout<<v[1].second<<"\n";
    }else{
        cout<<v[0].second<<"\n";
    }
    cout<<arr[n] - arr[1]<<"\n";

    return 0;
}
