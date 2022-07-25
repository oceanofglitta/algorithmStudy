#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int i, j, dp[101][100001] = {0};
    int N, K, W[101]={0}, V[101]={0};

    cin >> N >> K;
    for(i=1; i<=N; i++) {
        cin >> W[i] >> V[i];
    }

    for(i=1; i<=N; i++) {
        for(j=1; j<=K; j++) {
            if(j - W[i] >=0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][K];

    return 0;
}