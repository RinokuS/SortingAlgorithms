#include <vector>

/// Сортировка выбором
/// \param vec вектор для сортировки
std::vector<int> selection_sorting(std::vector<int> vec) {
    int unsorted_begin = 0;

    while (unsorted_begin != vec.size() - 1) {
        int ind_of_unsorted_min = unsorted_begin;

        for (int i = unsorted_begin; i < vec.size(); ++i) {
            if (vec[i] < vec[ind_of_unsorted_min])
                ind_of_unsorted_min = i;
        }

        if (ind_of_unsorted_min != unsorted_begin)
            std::swap(vec[unsorted_begin], vec[ind_of_unsorted_min]);
        unsorted_begin++;
    }

    return std::move(vec);
}
