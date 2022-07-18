#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int i, j=0;
    int N;
    int temp;
    vector<int> A;

    A.push_back(-1);

    cin >> N;
    for(i=0; i<N; i++) {
        cin >> temp;
        if(temp > A.back()) {
            A.push_back(temp);
            j++;
        }
        else {
            vector<int>::iterator iter = lower_bound(A.begin(), A.end(), temp);
            *iter = temp;
        }
    }

    cout << j;

    return 0;
}