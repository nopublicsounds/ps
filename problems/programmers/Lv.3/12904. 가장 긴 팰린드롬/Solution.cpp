#include <string>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 0;
    int n = s.length();

    for (int center = 0; center < n; center++) {
        int left = center;
        int right = center;

        while (left >= 0 && right < n && s[left] == s[right]) {
            answer = max(answer, right - left + 1);
            left--;
            right++;
        }

        left = center;
        right = center + 1;

        while (left >= 0 && right < n && s[left] == s[right]) {
            answer = max(answer, right - left + 1);
            left--;
            right++;
        }
    }

    return answer;
}