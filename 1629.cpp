#include<iostream>

using namespace std;

int A, B, C;

long long int f(long long int x, long long int n) {
    if(n == 0)
        return 1;
    else if(n == 1)
        return x;
    if(n%2 != 0)
        return f(x, n-1)*x;

    long long int y = f(x, n/2);
    y = y % C;
    return y*y%C;
}

int main() {
    cin >> A >> B >> C;
    cout << f(A, B) % C;

    return 0;
}