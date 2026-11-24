#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, c;
    cin >> n >> c;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i]==c) {
            cout << 1;
            return 0;
        }
    }
    sort(v.begin(), v.end());

    int i = 0, j = n - 1;
    while (i < j) {
        if (v[i] + v[j] == c) {
            cout << 1;
            return 0;
        }

        else if (v[i] + v[j] < c) {
            i++;
        }

        else {
            j--;
        }
    }

    for (int i = 0; i < n - 2; i++) {
        int s = i + 1, e = n - 1;
            while (s < e) {
            if (v[s] + v[e] == c - v[i]) {
                cout << 1;
                return 0;
            }

            else if (v[s] + v[e] < c - v[i]) {
                s++;
            }

            else {
                e--;
            }
        }
    }
    cout << 0;
    return 0;
}