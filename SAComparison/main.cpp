/*
 * АиСД-2, 2021, задание 5
 * Соколовский Вацлав Антонович
 * БПИ191
 * CLion
 * Реализовано:
 *  Функция вывода векторов в файлы для защиты
 *  Функция проверки факта отсортированности вектора
 *  Игнорирование первых трех сортировок
 *  Подсчет времени сортировки 10 раз и усреднение времени
 *  Подсчет времени для всех размеров данных, всех видов данных и 8 типов сортировок
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

#include "data_creator.h"

#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "counting_sort.h"
#include "radix_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"

using namespace std;

const vector<string> columns = {"Bubble Random 0-5", "Bubble Random 0-4000", "Bubble Almost Sorted", "Bubble Reversed Sorted",
                          "Selection Random 0-5", "Selection Random 0-4000", "Selection Almost Sorted", "Selection Reversed Sorted",
                          "Insertion Random 0-5", "Insertion Random 0-4000", "Insertion Almost Sorted", "Insertion Reversed Sorted",
                          "Counting Random 0-5", "Counting Random 0-4000", "Counting Almost Sorted", "Counting Reversed Sorted",
                          "Radix Random 0-5", "Radix Random 0-4000", "Radix Almost Sorted", "Radix Reversed Sorted",
                          "Merge Random 0-5", "Merge Random 0-4000", "Merge Almost Sorted", "Merge Reversed Sorted",
                          "Quick Random 0-5", "Quick Random 0-4000", "Quick Almost Sorted", "Quick Reversed Sorted",
                          "Heap Random 0-5", "Heap Random 0-4000", "Heap Almost Sorted", "Heap Reversed Sorted"};

/// Метод для вывода векторов в файл (для удобства защиты)
/// \tparam T тип элементов
/// \param vec вектор для вывода
/// \param file_name имя файла
template <typename T>
void write_to_file(const vector<T> &vec, const string &file_name) {
    ofstream os {file_name + ".txt"};

    for (const auto &elem: vec)
        os << elem << ' ';
}

/// Метод для проверки, отсортирован ли массив
/// \param vec массив для проверки
/// \return булка - да или нет
bool is_sorted(const vector<int> &vec) {
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1])
            return false; // возвращаем false, если находим элемент, который меньще предыдущего
    }

    return true;
}

/// Метод для нахождения среднего арифметического элементов вектора
/// фактически нужен только для подсчета среднего по времени сортировок :)
/// \param numbers вектор элементов
/// \return среднее арифметическое
unsigned long long mean(const vector<unsigned long long> &numbers) {
    unsigned long long sum = 0;
    for (const auto &i: numbers)
        sum += i;

    return sum / numbers.size();
}

/// Метод для генерации данных и проведения замеров
/// \param output_file_name название файла для вывода
/// \param st левая граница размерности массивов
/// \param end правая граница размерности массивов
/// \param step шаг увеличения размерности
void make_samples(const string &output_file_name, int st, int end, int step) {
    ofstream os {output_file_name + ".csv"};
    clock_t start;
    vector<unsigned long long> durations(10);

    vector<function<vector<int> (vector<int>)>> sorts = {bubble_sorting, selection_sorting,
                                                         insertion_sorting, counting_sort, radix_sort,
                                                         merge_sort, quick_sort, heap_sort};
    vector<vector<int>> data(4); // массив векторов всех видов (всего 4 вида)


    for (const auto &c: columns)
        os << ';' << c; // записываем названия столбцов в файл
    os << '\n';

    for (int size = st; size <= end; size += step) {
        os << size;
        data[0] = make_one_to_five(size);
        data[1] = make_one_to_four_t(size); // генерируем массивы (один раз для всех сортировок, конечно же)
        data[2] = make_almost_sorted(size);
        data[3] = make_reversed(size);

        for (auto &s: sorts) { // проход по всем сортировкам
            for (auto &vec: data) { // проход по всем массивам
                for (int i = 0; i < 13; ++i) { // делаем 13 замеров (по факту 10)
                    start = clock(); // старт таймера
                    vector<int> sorted_vec = s(vec); // сортировка

                    if (i >= 3) // пропускаем первые три замера, как советовали в презентации :)
                        durations[i - 3] = (std::clock() - start); // записываем время (в тиках)

                    if (!is_sorted(sorted_vec)) // проверка на отсортированность
                        cout << "Something went wrong!";
                }

                os << ';' << mean(durations);
            }
        }

        os << '\n';
    }
}

int main() {
    make_samples("small", 50, 300, 50); // запуск проверки на малых размерностях
    make_samples("big", 100, 4100, 1000); // запуск проверки на больших размерностях

    return 0;
}
