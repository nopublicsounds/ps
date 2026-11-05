#include <string>
#include <vector>
#include <stack>
using namespace std;

bool solution(string s) {
    stack<int> st;
    for (char c : s) {
        if (c == '(') {
            st.push(1);
        }

        else {
            if (st.empty()) {
                return false;
            }

            st.pop();
        }
    }

    if (st.empty()) {
        return true;
    }

    return false;
}