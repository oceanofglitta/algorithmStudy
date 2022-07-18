#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int N, k;
    int i, high, low = 1, mid, count = 0, res=0;
    cin >> N >> k;
    high = k;

    while(low <= high) {
        mid = (high+low)/2;
        count = 0;

        for(i=1; i<=N; i++)
            count += min(N, mid/i);

        if(count >= k) {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << res;

    return 0;
}