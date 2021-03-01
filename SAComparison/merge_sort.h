#include <vector>

std::vector<int> merge(std::vector<int> left, std::vector<int> right) {
    std::vector<int> result;

    while (!left.empty() || !right.empty()) {
        if (!left.empty() && !right.empty()) {
            if (left.front() <= right.front()) {
                result.push_back(left.front());
                left.erase(left.begin());
            } else {
                result.push_back(right.front());
                right.erase(right.begin());
            }
        } else if (!left.empty()) {
            for (int i : left)
                result.push_back(i);
            break;
        } else if (!right.empty()) {
            for (int i : right)
                result.push_back(i);
            break;
        }
    }

    return std::move(result);
}

std::vector<int> merge_sort(std::vector<int> vec) {
    if (vec.size() <= 1)
        return vec;

    std::vector<int> left, right, result;
    int middle = ((int)vec.size() + 1) / 2;

    for (int i = 0; i < middle; i++)
        left.push_back(vec[i]);
    for (int i = middle; i < (int)vec.size(); i++)
        right.push_back(vec[i]);

    left = merge_sort(left);
    right = merge_sort(right);
    result = merge(left, right);

    return std::move(result);
}
