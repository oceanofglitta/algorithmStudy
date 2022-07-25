#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n, tri[501][501] = {0}, dp[501][501] = {0};
    int i, j;

    cin >> n;
    for(i=0; i<n; i++) {
        for(j=0; j<=i; j++) {
            cin >> tri[i][j];
        }
    }

    dp[0][0] = tri[0][0];
    for(i=1; i<n; i++) {
        for(j=0; j<=i; j++) {
            if(j-1 < 0)
                dp[i][j] = dp[i-1][j] + tri[i][j];
            else if(j >= i)
                dp[i][j] = dp[i-1][j-1] + tri[i][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + tri[i][j];
        }
    }

    sort(dp[n-1], dp[n-1] + n);
    cout << dp[n-1][n-1];

    return 0;
}