#include<iostream>
#include<deque>
#include<cstring>
#include<sstream>

using namespace std;

deque<int> stringToDeque(string arr, int arrLength) {
    arr = arr.substr(1, arr.size()-2);
    istringstream ss(arr);
    string stringBuffer;
    deque<int> x;
    x.clear();
    while (getline(ss, stringBuffer, ',')){
        x.push_back(stoi(stringBuffer));
    }

    return x;
}

int main() {
    int T, testcases, numsLength, i;
    string p, numsTemp;
    bool errorFlag = false, reverseFlag = false;
    deque<int> nums, temp;
    
    cin >> T;
    for(testcases=0; testcases<T; testcases++) {
        cin >> p;
        cin >> numsLength;
        cin >> numsTemp;
        nums = stringToDeque(numsTemp, numsLength);
        
        for(i=0; i<p.size(); i++) {
            if(nums.size() == 0 && p[i] == 'D') {
                errorFlag = true;
                break;
            }
            else if(p[i] == 'R') {
                if(!reverseFlag)
                    reverseFlag = true;
                else
                    reverseFlag = false;
            }
            else if(p[i] == 'D') {
                if(reverseFlag)
                    nums.pop_back();
                else
                    nums.pop_front();
            }
        }
         
        if(!errorFlag) {
            cout << '[';
            while(!nums.empty()) {
                if(!reverseFlag) {
                    cout << nums.front();
                    if(!(nums.size() == 1))
                        cout << ',';
                    nums.pop_front();
                }
                else {
                    cout << nums.back();
                    if(!(nums.size() == 1))
                        cout << ',';
                    nums.pop_back();
                }
            }
            cout << ']' << '\n';
        }
        
        else {
            cout << "error\n";
        }
        
        reverseFlag = false;
        errorFlag = false;
    }
    
    return 0;
}
