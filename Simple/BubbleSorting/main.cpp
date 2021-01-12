#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void bubble_sorting(vector<T>& vec) {
    for (size_t i = 0; i < vec.size() - 1; i++)
        for (size_t j = 0; j < vec.size() - i - 1; j++)
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
}

int main() {
    vector<int> test = {64, 34, 25, 12, 22, 11, 90, 1};
    bubble_sorting(test);

    for (const auto& elem: test)
        cout << elem << ' ';

    return 0;
}
