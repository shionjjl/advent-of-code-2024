#include <iostream>
#include <regex>
#include <string>
using namespace std;

int calculate(string s) {
    //cout << "string: " << s << endl;
    smatch m;
    regex r("(\\d+),(\\d+)");
    
    
    /*for (int i = 0; i < m.size(); i++) {
        cout << m[i] << " ";
    }
    cout << endl;
    */
    
    if (regex_search(s, m, r) && m.size() > 2) {
        int num1 = stoi(m[1].str());
        int num2 = stoi(m[2].str());
        //cout << "nums: " << num1 << " " << num2 << endl;
        return num1 * num2;
    }

    //cout << "no numbers found in " << s << endl;
    return 0;
}

int main() {
    string s;
    cout << s;
    regex r("mul\\((\\d+,\\d+)\\)");
    smatch m;

    int res = 0;
    /*
    regex_search(s, m, r);
    for (int i = 0; i < m.size(); i++) {
        cout << m[i] << " ";
    }
    cout << endl;*/

    while (cin >> s) {
        while (regex_search(s, m, r)) {
            string match = m[1].str();
            //cout << "match: " << match << endl;
            res += calculate(match);
            s = m.suffix().str();
        }
    }
    cout << "result: " << res << endl;
    return 0;
}