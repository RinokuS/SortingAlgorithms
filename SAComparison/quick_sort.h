#include <vector>
#include <stack>

template<typename T>
T stack_get(std::stack<T>& st) {
    T temp = st.top();
    st.pop();

    return temp;
}

std::vector<int> quick_sort(std::vector<int> vec) {
    long i, j,
            left_bound, right_bound;
    std::stack<long> call_stack;
    long middle;

    call_stack.push(0);
    call_stack.push(vec.size() - 1);

    while(!call_stack.empty()) {
        right_bound = stack_get(call_stack);
        left_bound = stack_get(call_stack);

        while (left_bound < right_bound) {
            middle = (left_bound + right_bound) / 2;
            int pivot = vec[middle];
            i = left_bound;
            j = right_bound;

            while (i <= j) {
                while (vec[i] < pivot) i++;
                while (pivot < vec[j]) j--;

                if (i <= j)
                    std::swap(vec[i++], vec[j--]);
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

    return std::move(vec);
}