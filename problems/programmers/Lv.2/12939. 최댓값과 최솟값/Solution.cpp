#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    stringstream ss(s);
    vector<int> v;

    int n;
    while (ss >> n) {
        v.push_back(n);
    }

    return to_string(*min_element(v.begin(), v.end())) + " " + to_string(*max_element(v.begin(), v.end()));
}