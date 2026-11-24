#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        m[s]++;
    }

    int value = 0;
    string res;

    for (auto [k, v] : m) {
        if (v > value) {
            value = v;
            res = k;
        }
    }

    cout << res;
}
