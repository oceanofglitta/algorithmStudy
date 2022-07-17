#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, A[100001] = {0}, shouldFind;
    int i;
    
    cin >> N;
    for(i=0; i<N; i++) {
        cin >> A[i];
    }
    sort(A, A+N);
    cin >> M;
    for(i=0; i<M; i++) {
        cin >> shouldFind;
        if(binary_search(A, A+N, shouldFind))
            cout << "1\n";
        else
            cout << "0\n";
    }
    
    return 0;
}
