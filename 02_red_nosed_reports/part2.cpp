#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

bool isSafeRemoval(const vector<int>& nums) {
    if (nums.size() < 2) {
        return false;
    }
    int sign = 0;
    for (int i = 1; i < nums.size(); i++) {
        int diff = nums[i] - nums[i - 1];
        int absDiff = abs(diff);

        if (absDiff < 1 || absDiff > 3) {
            return false;
        }

        int currentSign = (diff > 0) - (diff < 0);

        if (sign == 0) {
            sign = currentSign;
        } else if (currentSign != sign) {
            return false;
        }
    }
    return true;
}

int main() {
    int safe = 0;
    string line;
    while (getline(cin, line)) {
        vector<int> nums;
        int num;

        stringstream ss(line);
        while (ss >> num) {
            nums.push_back(num);
        }

        if (isSafeRemoval(nums)) {
            safe++;
            continue;
        }

        bool isSafe = false;
        // not the best time complexity but its the most clear so far
        for (size_t i = 0; i < nums.size(); i++) {
            vector<int> modified = nums;
            modified.erase(modified.begin() + i);
            if (isSafeRemoval(modified)) {
                safe++;
                break;
            }
        }
    }
    cout << safe << endl;
    return 0;
}