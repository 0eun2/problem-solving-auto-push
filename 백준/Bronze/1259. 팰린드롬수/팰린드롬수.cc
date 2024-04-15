#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    while(true){
        string s, s_reverse;
        cin >> s_reverse;
        s = s_reverse;
        reverse(s_reverse.begin(), s_reverse.end());
        
        if(s == "0")
            break;
        else if(s == s_reverse)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}