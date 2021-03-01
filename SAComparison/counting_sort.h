#include <vector>

/// Сортировка подсчетом
/// \param vec вектор для сортировки
std::vector<int> counting_sort(std::vector<int> vec) {
    int max = *max_element(vec.begin(), vec.end());

    int c[max+1];
    int b[vec.size()];

    for (int i = 0; i < max+1; i++)
        c[i] = 0;
    for (int i : vec)
        c[i]++;
    for (int i = 1; i < max+1; i++)
        c[i] += c[i-1];

    for (int i = vec.size() - 1; i >= 0; i--)
        b[--c[vec[i]]] = vec[i];

    for (int i = 0; i < vec.size(); ++i)
        vec[i] = b[i];

    return std::move(vec);
}