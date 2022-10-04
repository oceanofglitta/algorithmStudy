#include<iostream>
#include<vector>
#include<stack>

using namespace std;


vector<int> v[101];
int visited[101]={0};
int cnt = 0;

void dfs(int now) {
    int res;
    visited[now] = 1;

    for(int i=0; i<v[now].size(); i++) {
        if(!visited[v[now][i]]) {
            dfs(v[now][i]);
            cnt++;
        }
    }
} 

int main() {
    int N, M;
    cin >> N >> M;

    for(int i=0; i<M; i++) {
        int temp, temp2;
        cin >> temp >> temp2;
        v[temp].push_back(temp2);
        v[temp2].push_back(temp);
    }

    dfs(1);

    cout << cnt;

    return 0;
}