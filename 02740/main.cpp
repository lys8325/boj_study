#include <iostream>
#include <algorithm>

using namespace std;
int N, M, K;
int arrA[100][100];
int arrB[100][100];
int arrResult[100][100];

void consoleInput() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &arrA[i][j]);

    scanf("%d %d", &M, &K);
    for (int i = 0; i < M; i++) for (int j = 0; j < K; j++) scanf("%d", &arrB[i][j]);



    return;
}
void printArr(int arr[100][100], int i_size, int j_size) {
    for (int i = 0; i < i_size; i++) {
        for (int j = 0; j < j_size; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
}
int main() {
    consoleInput();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) arrResult[i][j] += (arrA[i][k] * arrB[k][j]);
        }
    }
    printArr(arrResult, N, K);
    return 0;
}