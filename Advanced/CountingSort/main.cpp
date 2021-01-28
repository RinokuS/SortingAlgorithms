#include <iostream>
#include <string>

using namespace std;

void counting_sort(int *a, int n, int max) {
    int c[max+1];
    int b[n];

    for (int i = 0; i < max+1; i++)
        c[i] = 0;
    for (int i = 0; i < n; i++)
        c[a[i]]++;
    for (int i = 1; i < max+1; i++)
        c[i] += c[i-1];

    for (int i = n - 1; i >= 0; i--)
        b[--c[a[i]]] = a[i];

    for (int i = 0; i < n; ++i)
        a[i] = b[i];
}

int main() {
    int n, max = 0;
    cin >> n;
    int *a = new int [n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max)
            max = a[i];
    }
    counting_sort(a,n,max);
    for (int i = 0; i < n; ++i)
        cout << a[i] << '\n';

    delete[] a;
    return 0;
}