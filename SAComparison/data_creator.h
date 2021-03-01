#include <vector>

std::vector<int> make_one_to_five(int size) {
    std::vector<int> res(size);
    srand(time(0)); // задаем сид

    for (auto& elem: res)
        elem = rand() % 5;

    return res;
}

std::vector<int> make_one_to_four_t(int size) {
    std::vector<int> res(size);
    srand(time(0)); // задаем сид

    for (auto& elem: res)
        elem = rand() % 4000;

    return res;
}

std::vector<int> make_almost_sorted(int size) {
    std::vector<int> res(size);
    int i = 0;

    for (auto& elem: res)
        elem = i++;
    for (int j = 1; j < size; j += 200)
        std::swap(res[j - 1], res[j]); // свапаем 2 элемента с шагом в 200

    return res;
}

std::vector<int> make_reversed(int size) {
    std::vector<int> res(size);
    int i = 1;

    for (auto& elem: res)
        elem = i++;

    reverse(res.begin(), res.end());

    return res;
}
