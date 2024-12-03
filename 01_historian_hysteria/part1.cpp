#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> data1;
    vector<int> data2;
    int a, b;
    while (cin >> a >> b) {
        data1.push_back(a);
        data2.push_back(b);
    }

    sort(data1.begin(), data1.end());
    sort(data2.begin(), data2.end());

    int result = 0;

    for (int i = 0; i < data1.size(); i++) {
        result += abs(data1[i] - data2[i]);
    }

    cout << result << endl;

    return 0;
}