#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int i;
    int n;
    int arr[100001] = {0}, dp[100001] = {0};

    cin >> n;
    for(i=0; i<n; i++)
        cin >> arr[i];

    if(n == 1) {
        cout << arr[0];
        return 0;
    }
    
    dp[0] = arr[0];
    for(i=1; i<n; i++) {
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
    }

    sort(dp, dp+n);

    cout << dp[n-1];

    return 0;
}