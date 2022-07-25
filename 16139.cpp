#include<iostream>
#include<cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL); 
    cin.tie(NULL);
    
    string S;
    int q, l, r, i, j;
    char a;
    int arr[26][250000];

    cin >> S;
    cin >> q;

    arr[S[0]-'a'][0]++;
    for(i=1; i<S.size(); i++) {
        for(j=0; j<26; j++) 
            arr[j][i] = arr[j][i-1];
        arr[S[i]-'a'][i]++;
    }

    for(i=0; i<q; i++) {
        int ll = 0, rr;
        cin >> a >> l >> r;
        
        if(l > 0)
            ll = arr[a-'a'][l-1];
        rr = arr[a-'a'][r];

        cout << rr - ll << '\n';
    }

    return 0;
}