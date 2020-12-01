#include <iostream>
#include <vector>
using namespace std;

void swapNum(vector<int> &v, int i, int j){
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void print(vector<int> &v){
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<"\n";
}

void bubbleSort(vector<int> v){
    int n = v.size();
    int swapCnt = 0;
    for(int i=0;i<n;++i){
        for(int j=1;j<n-i;++j){
            if(v[j-1] > v[j]){
                swapNum(v,j,j-1);
                ++swapCnt;
            }
        }
    }

    cout<<"   bubble Sort's swapCnt : "<<swapCnt<<" => ";
    print(v);
}

void selectionSort(vector<int> v){
    int n = v.size();
    int minIdx, swapCnt = 0;

    for(int i=0;i<n-1;++i){
        minIdx = i;
        for(int j=i+1;j<n;++j){
            if(v[minIdx] > v[j]){
                minIdx = j;
            }
        }
        swapNum(v, i, minIdx);
        ++swapCnt;
    }

    cout<<"selection Sort's swapCnt : "<<swapCnt<<" => ";
    print(v);

}

void insertionSort(vector<int> v){
    int n = v.size();
    int target, j;

    for(int i=1;i<n;++i){
        target = v[i];
        j = i-1;

        while(j >= 0 && target < v[j]){
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = target;
    }

    print(v);
}

int partition(vector<int> &v, int left, int right){
    int i = left;
    int j = right;
    int pivot = v[i];

    while(i < j){
        while(pivot < v[j]){
            --j;
        }

        while(i < j && pivot >= v[i]){
            ++i;
        }

        swapNum(v, i, j);
    }

    swapNum(v, i, left);
    return i;
}

void quickSort(vector<int> &v, int left, int right){
    if(left < right){
        int pivotIdx = partition(v, left, right);

        quickSort(v, left, pivotIdx-1);
        quickSort(v,pivotIdx+1, right);
    }
}

void merge(vector<int> &v, int left, int mid, int right){
    vector<int> tmp(right-left+1);
    int i = left;
    int j = mid+1;
    int idx = 0;

    while(i <= mid && j <= right){
        if(v[i] <= v[j]){
            tmp[idx++] = v[i++];
        }else{
            tmp[idx++] = v[j++];
        }
    }

    if(i > mid){
        while(j <= right){
            tmp[idx++] = v[j];
        }
    }else{
        while(i <= mid){
            tmp[idx++] = v[i];
        }
    }

    idx = left;
    while(idx <= right){
        v[idx] = tmp[idx-left];
        ++idx;
    }
}

void mergeSort(vector<int> &v, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;

        mergeSort(v, left, mid);
        mergeSort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}

void heapify(vector<int> &v, int idx, int heapSize){
    int nextIdx = idx * 2;

    if(nextIdx > heapSize){
        return;
    }

    if(nextIdx+1 <= heapSize){
        if(v[nextIdx] < v[nextIdx+1]){
            ++nextIdx;
        }
    }

    if(v[idx] < v[nextIdx]){
        swapNum(v, idx, nextIdx);
        heapify(v, nextIdx, heapSize);
    }
}

void heapSort(vector<int> &v){
    int heapSize = v.size()-1; // idx = 1 부터 시작해서 v[0]이 비워져있다.

    for(int i=heapSize/2;i>=1;--i){
        heapify(v,i,heapSize);
    }

    while(heapSize > 0){
        swapNum(v, 1, heapSize);
        --heapSize;

        heapify(v, 1, heapSize);
    }
}

int main() {
    vector<int> num;
    num.push_back(10);
    num.push_back(325);
    num.push_back(21);
    num.push_back(3215);
    num.push_back(6123);
    num.push_back(34);
    num.push_back(4);
    num.push_back(436);
    num.push_back(41);
    num.push_back(231);
    num.push_back(1);
    num.push_back(12);
    num.push_back(7345);
    num.push_back(135);

    vector<int> num2(num);
    vector<int> num3(num);
    vector<int> num4(num);
    num4.push_back(0);
    swapNum(num4, 0, num4.size()-1);

    bubbleSort(num);
    selectionSort(num);
    insertionSort(num);
    quickSort(num2, 0, num2.size()-1);
    print(num2);
    quickSort(num3, 0, num3.size()-1);
    print(num3);
    heapSort(num4);
    print(num4);

    return 0;
}
