#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; // убрать

int charAt(const string &s, int d) {
    if (d < s.length()) return s[d];
    else return -127;
}

// hi-hi
// haha

void MSDsort(vector<string> &a, int low, int high, int d, vector<string> &aux) {
    if (high <= low) return;
    
    const int R = 256;  // Размер алфавита (для ASCII символов)
    vector<int> count(R + 2, 0);
    
    for (int i = low; i <= high; i++) {
        int c = charAt(a[i], d);
        count[c + 127]++;
    }
    
    for (int r = 0; r < R + 1; r++) {
        count[r + 1] += count[r];
    }
    
    vector<int> cnt_copy = count;

    for (int i = low; i <= high; i++) {
        int c = charAt(a[i], d);
        aux[--cnt_copy[c + 127]] = a[i];
    }
    
    for (int i = low; i <= high; i++) {
        a[i] = aux[i - low];
    }
    
    for (int r = 0; r < R; r++) {
        MSDsort(a, low + count[r], low + count[r + 1] - 1, d + 1, aux);
    }
}

void MSDsort(vector<string> &a) {
    int n = a.size();
    vector<string> aux(n);
    MSDsort(a, 0, n - 1, 0, aux);
}

void runTest(const vector<string> &testData) {
    auto copy = testData;
    vector<string> data = testData;
    MSDsort(data);
    std::sort(copy.begin(), copy.end());
    assert(copy == data);
    for (const auto &str : data) {
        cout << str << endl;
    }
    cout << "------" << endl;
}

int main() {
    // Тест 1

    cout << "Тест 1:" << endl;
    vector<string> testData1 = {"dab", "cab", "lab", "dab", "lab", "cab", "dab"};
    runTest(testData1);

    // Тест 2
    cout << "Тест 2:" << endl;
    vector<string> testData2 = {"apple", "banana", "grape", "cherry", "mango", "peach", "berry"};
    runTest(testData2);

    // Тест 3
    cout << "Тест 3:" << endl;
    vector<string> testData3 = {"123", "321", "213", "132", "231", "312"};
    runTest(testData3);

    // Тест 4
    cout << "Тест 4:" << endl;
    vector<string> testData4 = {"a", "ab", "abc", "abcd", "abcde"};
    runTest(testData4);

    // Тест 5
    cout << "Тест 5:" << endl;
    vector<string> testData5 = {"xyz", "wxyz", "vwxyz", "uvwxyz"};
    runTest(testData5);

    return 0;
}
