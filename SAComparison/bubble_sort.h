#include <vector>

/// Сортировка пузырьком
/// \param vec вектор для сортировки
std::vector<int> bubble_sorting(std::vector<int> vec) {
    for (size_t i = 0; i < vec.size() - 1; i++) {
        for (size_t j = 0; j < vec.size() - i - 1; j++)
            if (vec[j] > vec[j + 1])
                std::swap(vec[j], vec[j + 1]);
    }

    return std::move(vec);
}
