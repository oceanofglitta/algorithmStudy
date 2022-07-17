#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int N, M, i, j;
    long long temp, high = -1, low = 0, res = 0, mid, sumsum;
    vector<int> Hs;

    cin >> N >> M;
    for(i=0; i<N; i++) {
        cin >> temp;
        Hs.push_back(temp);
        if(temp > high)
            high = temp;
    }

    while(low <= high) {
        mid = (high+low)/2;
        sumsum = 0;

        for(j=0; j<N; j++) {
            temp = Hs[j] - mid;
            if(temp < 0)
                temp = 0;
            sumsum += temp;
        }

        if(sumsum >= M) {
            if(res < mid)
                res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << res;
}