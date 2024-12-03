#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> data1;
    vector<int> data2;
    int a, b;
    while (cin >> a >> b) {
        data1.push_back(a);
        data2.push_back(b);
    }

    // Use hashmap to store counter 
    unordered_map<int, int> map;
    for (int num : data2) {
        if (map.find(num) == map.end()) {
            map[num] = 1;
        } else {
            map[num]++;
        }
    }

    int score = 0;

    // Iterate through data1 to check if ID is in data2 map
    for (int num : data1) {
        if (!(map.find(num) == map.end())) {
            score += map[num] * num;
        }
    }

    cout << score << endl;

    return 0;
}