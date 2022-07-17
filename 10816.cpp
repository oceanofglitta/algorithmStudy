#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M, i;
    int cards[500001] = {0}, shouldFind;
    
    cin >> N;
    for(i=0; i<N; i++) {
        cin >> cards[i];
    }
    sort(cards, cards+N);
    cin >> M;
    for(i=0; i<M; i++) {
        cin >> shouldFind;
        cout << upper_bound(cards, cards+N, shouldFind) - lower_bound(cards, cards+N, shouldFind) << ' ';
    }
    
    return 0;
}
