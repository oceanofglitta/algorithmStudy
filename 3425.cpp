#include<iostream>
#include<stack>
#include<cstring>
#include<cstdlib>

using namespace std;

int main() {
    string input;
    bool inputFlag = 0;
    int theOperators[100001] = {0};
    long numOperands[100001] = {0};
    int i = 0, operandsNum = 0;
    long theOperands;
    stack<long> operatingStack;

    while(1) {
        if(inputFlag == 0) {
            getline(cin, input);
            if(input == "QUIT")
                break;

            if(input == "END") {
                inputFlag = 1;
                continue;
            }
            else if(input == "POP") {
                theOperators[i] = 1;
                i++;
            }
            else if(input == "INV") {
                theOperators[i] = 2;
                i++;
            }
            else if(input == "DUP") {
                theOperators[i] = 3;
                i++;
            }
            else if(input == "SWP") {
                theOperators[i] = 4;
                i++;
            }
            else if(input == "ADD") {
                theOperators[i] = 5;
                i++;
            }
            else if(input == "SUB") {
                theOperators[i] = 6;
                i++;
            }
            else if(input == "MUL") {
                theOperators[i] = 7;
                i++;
            }
            else if(input == "DIV") {
                theOperators[i] = 8;
                i++;
            }
            else if(input == "MOD") {
                theOperators[i] = 9;
                i++;
            }
            else if(input.substr(0, 3) == "NUM") {
                theOperators[i] = 10;
                string temp = input.substr(4);
                long NUM_input = stol(temp);
                numOperands[i] = NUM_input;
                i++;
            }
        }

        else if(inputFlag == 1) {
            cin >> operandsNum;
            for(int j=0; j<operandsNum; j++) {
                bool errorFlag = false;
                cin >> theOperands;
                operatingStack.push(theOperands);
                for(int k=0; k<i; k++) {
                    if(theOperators[k] == 1) {
                        if(operatingStack.empty()) {
                            errorFlag = true;
                            break;
                        }
                        operatingStack.pop();
                    }
                    else if(theOperators[k] == 2) {
                        if(operatingStack.empty()) {
                            errorFlag = true;
                            break;
                        }
                        long tempN = operatingStack.top();
                        tempN = tempN * (-1);
                        operatingStack.pop();
                        operatingStack.push(tempN);
                    }
                    else if(theOperators[k] == 3) {
                        if(operatingStack.empty()) {
                            errorFlag = true;
                            break;
                        }
                        operatingStack.push(operatingStack.top());
                    }
                    else if(theOperators[k] == 4) {
                        if(operatingStack.size() < 2) {
                            errorFlag = true;
                            break;
                        }
                        long tempF = operatingStack.top();
                        operatingStack.pop();
                        long tempS = operatingStack.top();
                        operatingStack.pop();
                        operatingStack.push(tempF);
                        operatingStack.push(tempS);
                    }
                    else if(theOperators[k] == 5) {
                        if(operatingStack.size() < 2) {
                            errorFlag = true;
                            break;
                        }
                        long tempF = operatingStack.top();
                        operatingStack.pop();
                        long tempS = operatingStack.top();
                        operatingStack.pop();
                        operatingStack.push(tempF + tempS);
                    }
                    else if(theOperators[k] == 6) {
                        if(operatingStack.size() < 2) {
                            errorFlag = true;
                            break;
                        }
                        long tempF = operatingStack.top();
                        operatingStack.pop();
                        long tempS = operatingStack.top();
                        operatingStack.pop();
                        operatingStack.push(tempS - tempF);
                    }
                    else if(theOperators[k] == 7) {
                        if(operatingStack.size() < 2) {
                            errorFlag = true;
                            break;
                        }
                        long tempF = operatingStack.top();
                        operatingStack.pop();
                        long tempS = operatingStack.top();
                        operatingStack.pop();
                        operatingStack.push(tempS * tempF);
                    }
                    else if(theOperators[k] == 8) {
                        if(operatingStack.size() < 2) {
                            errorFlag = true;
                            break;
                        }
                        long tempF = operatingStack.top();
                        operatingStack.pop();
                        long tempS = operatingStack.top();
                        operatingStack.pop();
                        if(tempF == 0) {
                            errorFlag = true;
                            break;
                        }
                        long tempR;
                        if(tempF < 0 && tempS > 0) {
                            tempR = tempS / abs(tempF);
                            tempR = tempR * (-1);
                        }
                        else if(tempF > 0 && tempS < 0) {
                            tempR = abs(tempS) / tempF;
                            tempR = tempR * (-1);
                        }
                        else {
                            tempR = abs(tempS) / abs(tempF);
                        }
                        operatingStack.push(tempR);
                    }
                    else if(theOperators[k] == 9) {
                        if(operatingStack.size() < 2) {
                            errorFlag = true;
                            break;
                        }
                        long tempF = operatingStack.top();
                        operatingStack.pop();
                        long tempS = operatingStack.top();
                        operatingStack.pop();
                        if(tempF == 0) {
                            errorFlag = true;
                            break;
                        }
                        long tempR;
                        if(tempF < 0 && tempS > 0) {
                            tempR = tempS % abs(tempF);
                            tempR = tempR * (-1);
                        }
                        else if(tempF > 0 && tempS < 0) {
                            tempR = abs(tempS) % tempF;
                            tempR = tempR * (-1);
                        }
                        else {
                            tempR = abs(tempS) % abs(tempF);
                        }
                        operatingStack.push(tempS % tempF);
                    }
                    else if(theOperators[k] == 10) {
                        operatingStack.push(numOperands[k]);
                    }
                }

                if(errorFlag || operatingStack.empty() || operatingStack.size() > 1) {
                    errorFlag = false;
                    cout << "ERROR\n";
                    while(!operatingStack.empty())
                        operatingStack.pop();
                }
                else if(abs(operatingStack.top()) > 1000000000) {
                    cout << "ERROR\n";
                    while(!operatingStack.empty())
                        operatingStack.pop();
                }
                else {
                    cout << operatingStack.top() << "\n";
                    operatingStack.pop();
                }
            }
            cout << "\n";
            inputFlag = 0;
            for(int j=0; j<i; j++) {
                theOperators[i] = 0;
                numOperands[i] = 0;
            }
            i=0;
        }
    }
    return 0;
}