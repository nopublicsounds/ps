#include <iostream>
#include <vector>
using namespace std;

int sum(int start, int end) {
    int res = 0;
    for (int i = start; i <= end; i++) {
        res += i;
    }

    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int i = 1, j = 1;
    int answer = 0;
    while (j <= n && i <= j) {
        if (sum(i, j) == n) {
            answer++;
            j++;
        }

        else if (sum(i, j) < n) {
            j++;
        }

        else {
            i++;
        }
    }

    cout << answer;
    return 0;
}