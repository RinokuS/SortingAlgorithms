#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void insertion_sorting(vector<T>& vec) {
    size_t ind_for_insertion;
    for (size_t i = 1; i < vec.size(); ++i) {
        ind_for_insertion = i;

        for (size_t j = i; j > 0; --j) {
            if (vec[j - 1] > vec[i])
                ind_for_insertion = j - 1;
        }

        if (ind_for_insertion != i) {
            T temp = vec[i];
            vec.erase(vec.begin() + i);
            vec.insert(vec.begin() + ind_for_insertion, temp);
        }
    }
}

int main() {
    vector<int> test = {64, 34, 25, 12, 22, 11, 90, 1, 11};
    insertion_sorting(test);

    for (const auto& elem: test)
        cout << elem << ' ';

    return 0;
}
