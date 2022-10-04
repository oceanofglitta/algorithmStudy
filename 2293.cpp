#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k;

    cin >> n >> k;
    vector<int> vctr(n);
    vector<int> dp(k+1);
    for(int i=0; i<n; i++)
        cin >> vctr[i];

    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=vctr[i]; j<=k; j++) {  // vctr[i]는 동전 가격, 동전 가격보다 작은 액수는 만들 수 없으므로 arr[i]부터 시작
            dp[j] += dp[j-vctr[i]];
        }    
    }

    cout << dp[k];

    return 0;
}

// dp[i] = i원을 만들 수 있는 동전 갯수