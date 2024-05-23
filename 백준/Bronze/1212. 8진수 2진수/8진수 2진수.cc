#include <iostream>
#include <vector>

using namespace std;

int main() {
    string oct;
    vector<string> bin = {"000", "001", "010", "011", "100", "101", "110", "111"};

    cin >> oct;

    for (int i = 0; i < oct.length(); i++) {
        if(i == 0){
            cout << stoi(bin[oct[i] - '0']);
        }
        else{
            cout << bin[oct[i] - '0'];
        }
    }

    return 0;
}
