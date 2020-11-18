#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    int tmp;

    for(int i=0;i<n;++i){
        for(int j=1;j<n-i;++j){
            if(arr[j-1] > arr[j]){
                tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void selectionSort(int arr[], int n){
    int tmp;
    int minIdx;

    for(int i=0;i<n-1;++i){
        minIdx = i;
        for(int j=i+1;j<n;++j){
            if(arr[minIdx] > arr[j]){
                minIdx = j;
            }
        }

        tmp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = tmp;
    }
}

void insertionSort(int arr[], int n){
    int tmp;
    int idx;

    for(int i=1;i<n;++i){
        tmp = arr[i];
        idx = i-1;
        while(idx >= 0 && arr[idx] > tmp){
            arr[idx+1] = arr[idx];
            --idx;
        }

        arr[idx+1] = tmp;
    }
}

int main() {
    int arr[1000];
    int n, tmp;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>tmp;
        arr[i] = tmp;
    }

    insertionSort(arr, n);
    //selectionSort(arr, n);
    //bubbleSort(arr, n);

    for(int i=0;i<n;++i){
        cout<<arr[i]<<"\n";
    }
    return 0;
}
