#include <vector>

/// Сортировка вставками
/// \param vec вектор для сортировки
std::vector<int> insertion_sorting(std::vector<int> vec) {
    size_t ind_for_insertion;
    for (size_t i = 1; i < vec.size(); ++i) {
        ind_for_insertion = i;

        for (size_t j = i; j > 0; --j)
            if (vec[j - 1] > vec[i])
                ind_for_insertion = j - 1;

        if (i != ind_for_insertion) {
            int temp = vec[i];
            vec.erase(vec.begin() + i);
            vec.insert(vec.begin() + ind_for_insertion, temp);
        }
    }

    return std::move(vec);
}