#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void quick_sort(vector<T>& vec, size_t left_bound, size_t right_bound) {
    size_t left = left_bound,
    right = right_bound,
    middle = (right_bound + left_bound) / 2;

    while (left <= middle && right >= middle && left < right) {
        while (vec[left] < vec[middle])
            left++;
        while (vec[right] > vec[middle])
            right--;

        if (left <= right)
            swap(vec[left++], vec[right--]);
    }

    if (right > left_bound)
        quick_sort(vec, left_bound, right);
    if (left < right_bound)
        quick_sort(vec, left, right_bound);
}

int main() {
    vector<int> test = {64, 34, 25, 12, 22, 11,11, 90, 1, 11};
    quick_sort(test, 0, test.size() - 1);

    for (const auto& elem: test)
        cout << elem << ' ';

    return 0;
}
