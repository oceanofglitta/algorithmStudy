#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int N, C, i, count, prev;
    long long x[200001] = {0}, high = -1, low = 1, mid, res = 0;

    cin >> N >> C;
    for(i=0; i<N; i++) {
        cin >> x[i];
    }

    sort(x, x+N);

    for(i=1; i<N; i++) {
        if(x[i]-x[0] > high)
            high = x[i]-x[0];
    }

    while(low <= high) {
        mid = (high+low)/2;

        count = 1;
        prev = x[0];
        for(i=1; i<N; i++) {
            if(x[i] - prev >= mid) {
                count++;
                prev = x[i];
            }
        }

        if(count >= C) {
            if(res < mid)
                res = mid;
            low = mid + 1;
        }

        else
            high = mid - 1;
    }

    cout << res;

    return 0;
}