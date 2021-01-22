#include<iostream>
using namespace std;

int t;

int main(void){
    cin >> t;
    while (t--){
        int n, student[100001], finish[100001], ans = 0;
        bool check[100001];

        cin >> n;
        for (int i = 1; i <= n; i++){
            check[i] = false;
            finish[i] = 0;
        }

        for (int i = 1; i <= n; i++){
            cin >> student[i];
            finish[student[i]]++;
        }

        for (int i = 1; i <= n; i++){
            int now = i;
            while (!check[now] && !finish[now]){
                ans++;
                check[now] = true;
                finish[student[now]]--;
                now = student[now];
            }
        }

        cout << ans << "\n";
    }
    return 0;
}