#include <vector>

void heapify(std::vector<int> &vec, int n, int i) {
    int ind_of_max = i,
            left_node = 2 * i + 1,
            right_node = 2 * i + 2;

    if (left_node < n && vec[left_node] > vec[ind_of_max])
        ind_of_max = left_node;
    if (right_node < n && vec[right_node] > vec[ind_of_max])
        ind_of_max = right_node;

    if (ind_of_max != i) {
        std::swap(vec[i], vec[ind_of_max]);

        heapify(vec, n, ind_of_max);
    }
}

std::vector<int> heap_sort(std::vector<int> vec) {
    // node of the element will be 2*ind + 1 or 2*ind + 2
    // so we start our iteration from last node with leaves
    for (int i = vec.size() / 2 - 1; i >= 0; i--)
        heapify(vec, vec.size(), i);

    for (int i = vec.size() - 1; i > 0; i--) {
        // Move current root (first element) to the end of unsorted part
        std::swap(vec[0], vec[i]);
        // re-heapify unsorted part
        heapify(vec, i, 0);
    }

    return std::move(vec);
}
