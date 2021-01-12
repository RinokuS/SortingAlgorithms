#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void selection_sorting(vector<T>& vec) {
    size_t unsorted_begin = 0;

    while (unsorted_begin != vec.size() - 1) {
        int ind_of_unsorted_min = unsorted_begin;

        for (int i = unsorted_begin; i < vec.size(); ++i)
            if (vec[i] < vec[ind_of_unsorted_min])
                ind_of_unsorted_min = i;

        swap(vec[unsorted_begin++], vec[ind_of_unsorted_min]);
    }
}

int main() {
    vector<int> test = {64, 34, 25, 12, 22, 11, 90, 1, 11};
    selection_sorting(test);

    for (const auto& elem: test)
        cout << elem << ' ';

    return 0;
}
