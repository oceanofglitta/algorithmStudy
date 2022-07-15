#include<iostream>
#include<deque>

using namespace std;

void print(deque<int> q) {
    while(!q.empty()) {
        cout <<  q.front() << " ";
        q.pop_front();
    }
    cout << endl;
}

int find(deque<int> q, int num) {
    int i;

    for(i=0; i<q.size(); i++) {
        if(q[i] == num) {
            return i;
        }
    }
    return -1;
}

int main() {
    deque<int> q;
    int N, M, i, j, inp[51] = {0};
    int comp;
    int count = 0;

    cin >> N >> M;
    for(i=0; i<M; i++)
        cin >> inp[i];

    for(i=1; i<=N; i++) {
        q.push_back(i);
    }

    for(i=0; i<M; i++) {
        comp = inp[i];
        while(1) {
            if(comp ==  q.front()) {
                q.pop_front();
                break;
            }

            else if(find(q, comp) <= q.size()/2) {
                q.push_back(q.front());
                q.pop_front();
                count++;
            }

            else if(find(q, comp) > q.size()/2) {
                q.push_front(q.back());
                q.pop_back();
                count++;
            }
        }
    }

    cout << count;


    return 0;
}