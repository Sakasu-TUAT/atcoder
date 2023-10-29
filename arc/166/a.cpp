#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 部分文字列の操作を適用する関数
string applyOperations(string X) {
    vector<char> stack;

    for (char c : X) {
        if (c == 'A' && !stack.empty() && stack.back() == 'B') {
            stack.pop_back(); // 'BA' を消去
        } else {
            stack.push_back(c); // A または B をスタックに追加
        }
    }

    string result(stack.begin(), stack.end());
    return result;
}

bool canTransform(string X, string Y) {
    // X と Y に同じ部分文字列が含まれていることを確認
    if (X.find("AB") == string::npos || Y.find("AB") == string::npos) {
        return false;
    }

    // 部分文字列の操作を適用
    X = applyOperations(X);
    Y = applyOperations(Y);

    return X == Y;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        string X, Y;
        cin >> N >> X >> Y;

        if (canTransform(X, Y)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
