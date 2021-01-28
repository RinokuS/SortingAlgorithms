#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void selection_sorting(vector<T>& vec) {
    size_t unsorted_begin = 0;

    while (unsorted_begin != vec.size() - 1) {
        int ind_of_unsorted_min = unsorted_begin;

        for (int i = unsorted_begin; i < vec.size(); ++i) {
            if (vec[i] < vec[ind_of_unsorted_min])
                ind_of_unsorted_min = i;
        }

        if (ind_of_unsorted_min != unsorted_begin)
            swap(vec[unsorted_begin++], vec[ind_of_unsorted_min]);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (auto& i: vec)
        cin >> i;
    selection_sorting(vec);

    for (const auto& elem: vec)
        cout << elem << ' ';

    return 0;
}
