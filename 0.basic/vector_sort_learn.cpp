#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> vec = {{3, 4}, {1, 2}, {3, 1}, {1, 3}, {2, 2}};

    // 使用lambda表达式进行排序
    sort(vec.begin(), vec.end(), [](const vector<int> &a, const vector<int> &b) { // []代表的是一种匿名函数
        if (a[0] == b[0]) // 如果第一个元素相等，则比较第二个元素
            return a[1] < b[1];
        return a[0] < b[0];
    });

    // 打印排序结果
    for (const auto &v : vec) {
        cout << v[0] << ", " << v[1] << endl;
    }

    return 0;
}
