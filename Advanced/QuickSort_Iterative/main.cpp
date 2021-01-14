#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template<typename T>
T stack_get(stack<T>& st) {
    T temp = st.top();
    st.pop();

    return temp;
}

template<typename T>
void quick_sort(vector<T> &vec) {
    size_t i, j,
    left_bound, right_bound;
    stack<size_t> call_stack;
    size_t middle;

    call_stack.push(0);
    call_stack.push(vec.size() - 1);

    while(!call_stack.empty()) {
        right_bound = stack_get(call_stack);
        left_bound = stack_get(call_stack);

        while (left_bound < right_bound) {
            middle = (left_bound + right_bound) / 2;
            i = left_bound;
            j = right_bound;

            while (i <= j) {
                while (vec[i] < vec[middle]) i++;
                while (vec[middle] < vec[j]) j--;

                if (i <= j)
                    swap(vec[i++], vec[j--]);
            }

            if (i < middle) {
                if (i < right_bound) {
                    call_stack.push(i);
                    call_stack.push(right_bound);
                }
                right_bound = j;
            } else {
                if (j > left_bound) {
                    call_stack.push(left_bound);
                    call_stack.push(j);
                }
                left_bound = i;
            }
        }
    }
}

int main() {
    vector<int> test = {64, 34, 25, 12, 22, 11, 11, 90, 1, 11};
    quick_sort(test);

    for (const auto &elem: test)
        cout << elem << ' ';

    return 0;
}
