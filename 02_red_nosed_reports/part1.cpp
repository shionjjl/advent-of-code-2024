#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

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

        if (nums.size() < 2) {
            continue;
        }

        bool isSafe = true;
        int sign = 0;
        
        for (int i = 1; i < nums.size() && isSafe; i++) {
            int trueDiff = nums[i] - nums[i - 1];
            int diff = abs(trueDiff);
            //cout << diff << endl;
            if (diff < 1 || diff > 3) {
                //cout << "Determined unsafe at numbers: " << nums[i] << ", " << nums[i - 1] << endl;
                isSafe = false;
            }

            int currentSign = (trueDiff > 0) - (trueDiff < 0);

            if (sign == 0) {
                sign = currentSign;
            } else if (currentSign != sign) {
                isSafe = false;
            }
        }
        if (isSafe) {
            safe++;
        }
    }
    cout << safe << endl;
    return 0;
}