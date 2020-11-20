#include <iostream>
using namespace std;

int n;
int outPlace[1000001];

// ==============   quick sort start   ================
int partition(int *arr, int left, int right){
    int i = left;
    int j = right;
    int mid = (i + j) / 2;

    int tmp = arr[mid];
    arr[mid] = arr[i];
    arr[i] = tmp;

    int pivot = arr[i];

    while(i < j){
        while(pivot < arr[j]){
            --j;
        }

        while(i < j && pivot >= arr[i]){
            ++i;
        }

        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    arr[left] = arr[i];
    arr[i] = pivot;

    return i;
}

void quickSort(int arr[], int left, int right){
    if(left < right){
        int pivot = partition(arr, left, right);

        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
    }
}
// ==============   quick sort end  ================


// ==============   merge sort start   ================
void merge(int arr[], int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int idx = left;

    while(i <= mid && j <= right){
        if(arr[i] < arr[j]){
            outPlace[idx] = arr[i];
            ++idx;
            ++i;
        }else{
            outPlace[idx] = arr[j];
            ++idx;
            ++j;
        }
    }

    if(i > mid){
        while(j <= right){
            outPlace[idx] = arr[j];
            ++idx;
            ++j;
        }
    }else{
        while(i <= mid){
            outPlace[idx] = arr[i];
            ++idx;
            ++i;
        }
    }

    idx = left;
    while(idx <= right){
        arr[idx] = outPlace[idx];
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
// ==============   merge sort end  ================

// ==============   heap sort start  ================
void heapify(int arr[], int idx, int heapSize){
    int nextIdx = idx*2;
    if(nextIdx > heapSize){
        return;
    }
    if(nextIdx + 1 <= heapSize){
        if(arr[nextIdx] < arr[nextIdx+1]){
            nextIdx += 1;
        }
    }

    if(arr[nextIdx] > arr[idx]){
        int tmp = arr[idx];
        arr[idx] = arr[nextIdx];
        arr[nextIdx] = tmp;

        heapify(arr, nextIdx, heapSize);
    }
}

void heapSort(int arr[]){
    int heapSize = n;

    for(int i=n/2;i>0;--i){
        heapify(arr, i, n);
    }

    while(heapSize > 0){
        int tmp = arr[1];
        arr[1] = arr[heapSize];
        arr[heapSize] = tmp;
        --heapSize;

        heapify(arr, 1, heapSize);
    }
}
// ==============   heap sort end  ================

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num[1000001];

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>num[i];
    }

    //quickSort(num, 1, n);
    //mergeSort(num, 1, n);
    heapSort(num);

    for(int i=1;i<=n;++i){
        cout<<num[i]<<"\n";
    }

    return 0;
}
