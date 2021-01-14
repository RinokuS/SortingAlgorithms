#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
template<typename T>
void heapify(vector<T> &vec, int n, int i) {
    int ind_of_max = i,
    left_node = 2 * i + 1,
    right_node = 2 * i + 2;

    if (left_node < n && vec[left_node] > vec[ind_of_max])
        ind_of_max = left_node;
    if (right_node < n && vec[right_node] > vec[ind_of_max])
        ind_of_max = right_node;

    if (ind_of_max != i) {
        swap(vec[i], vec[ind_of_max]);

        heapify(vec, n, ind_of_max);
    }
}

template<typename T>
void heap_sort(vector<T> &vec) {
    // node of the element will be 2*ind + 1 or 2*ind + 2
    // so we start our iteration from last node with leaves
    for (int i = vec.size() / 2 - 1; i >= 0; i--)
        heapify(vec, vec.size(), i);

    for (int i = vec.size() - 1; i > 0; i--) {
        // Move current root (first element) to the end of unsorted part
        swap(vec[0], vec[i]);
        // re-heapify unsorted part
        heapify(vec, i, 0);
    }
}

int main() {
    vector<int> test = {64, 34, 25, 12, 22, 11, 11, 90, 1, 11};
    heap_sort(test);

    for (const auto &elem: test)
        cout << elem << ' ';

    return 0;
}
