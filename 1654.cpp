#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int K, N, i, j, gaesu = 0;
    int meters[10001] = {0}, res = 0;
    long long high = -999, low = 1, mid;
    
    cin >> K >> N;
    for(i=0; i<K; i++) {
        cin >> meters[i];
        if(high<meters[i])
            high = meters[i];
    }
    

    while(low <= high) {
        mid = (high+low)/2;
        
        for(j=0; j<K; j++) {
            gaesu += meters[j]/mid;
        }
        if(gaesu >= N) {
            if(res < mid)
                res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
        gaesu = 0;
    }
    cout << res;
    
    return 0;
}
