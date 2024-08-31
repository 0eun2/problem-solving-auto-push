#include<iostream>
#include<stack>

using namespace std;

int main() {

    int N;
    string command;
    stack<int> st;

    cin >> N;

    while (N--) {
        cin >> command;

        if (command == "push") {
            int num;
            cin >> num;
            st.push(num);
        } else if (command == "pop") {
            if (st.empty()) {
                cout << -1 << '\n';
            } else {
                cout << st.top() << '\n';
                st.pop();
            }
        } else if (command == "size") {
            cout << st.size() << '\n';
        } else if (command == "empty") {
            if (st.empty()) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (command == "top") {
            if (st.empty()) {
                cout << -1 << '\n';
            } else {
                cout << st.top() << '\n';
            }
        }
    }

    return 0;
}