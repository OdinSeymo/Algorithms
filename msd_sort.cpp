#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Функция для получения символа в строке по индексу, если индекс за пределами строки - возвращаем -1
int charAt(const string &s, int d) {
    if (d < s.length()) return s[d];
    else return -1;
}

// Функция MSD сортировки
void MSDsort(vector<string> &a, int low, int high, int d, vector<string> &aux) {
    if (high <= low) return;
    
    const int R = 256;  // размер алфавита (для ASCII символов)
    vector<int> count(R + 2, 0);
    
    // Подсчитываем количество символов
    for (int i = low; i <= high; i++) {
        int c = charAt(a[i], d);
        count[c + 2]++;
    }
    
    // Преобразуем count в индексы
    for (int r = 0; r < R + 1; r++) {
        count[r + 1] += count[r];
    }
    
    // Распределяем элементы
    for (int i = low; i <= high; i++) {
        int c = charAt(a[i], d);
        aux[count[c + 1]++] = a[i];
    }
    
    // Копируем обратно
    for (int i = low; i <= high; i++) {
        a[i] = aux[i - low];
    }
    
    // Рекурсивно сортируем подмассивы
    for (int r = 0; r < R; r++) {
        MSDsort(a, low + count[r], low + count[r + 1] - 1, d + 1, aux);
    }
}

void MSDsort(vector<string> &a) {
    int n = a.size();
    vector<string> aux(n);
    MSDsort(a, 0, n - 1, 0, aux);
}

int main() {
    vector<string> data = {"dab", "cab", "lab", "dab", "lab", "cab", "dab"};
    MSDsort(data);
    for (const auto &str : data) {
        cout << str << endl;
    }
    return 0;
}

