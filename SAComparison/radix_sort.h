#include <vector>

/// Вспомогательная функция для Radix сортировки
/// \param vec вектор
/// \param e значение параметра e
void counting_sort_for_radix(std::vector<int> &vec, int e) {
    int c[256] = {0};
    int b[vec.size()];

    for (int i : vec)
        c[(i >> e) % 256]++;
    for (int i = 1; i < 256; i++)
        c[i] += c[i-1];

    for (int i = vec.size() - 1; i >= 0; i--)
        b[--c[(vec[i] >> e) % 256]] = vec[i];

    for (int i = 0; i < vec.size(); ++i)
        vec[i] = b[i];
}

/// Radix сортировка
/// \param vec вектор для сортировки
std::vector<int> radix_sort(std::vector<int> vec) {
    int max = *max_element(vec.begin(), vec.end());

    int e = 0;
    for (int i = 1; max / i > 0 ; i *= 256) {
        counting_sort_for_radix(vec, e);
        e += 8;
    }

    return std::move(vec);
}
