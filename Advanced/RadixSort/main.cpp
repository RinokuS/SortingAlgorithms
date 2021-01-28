#include <iostream>
#include <string>

using namespace std;

void counting_sort(int *a, int n, int e) {
    int c[256] = {0};
    int b[n];

    for (int i = 0; i < n; i++)
        c[(a[i] >> e) % 256]++;
    for (int i = 1; i < 256; i++)
        c[i] += c[i-1];

    for (int i = n - 1; i >= 0; i--)
        b[--c[(a[i] >> e) % 256]] = a[i];

    for (int i = 0; i < n; ++i)
        a[i] = b[i];
}

void radix_sort(int *a, int n, int max) {
    int e = 0;
    for (int i = 1; max / i > 0 ; i *= 256) {
        counting_sort(a, n, e);
        e += 8;
    }
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
    radix_sort(a,n,max);
    for (int i = 0; i < n; ++i)
        cout << a[i] << '\n';

    delete[] a;
    return 0;
}