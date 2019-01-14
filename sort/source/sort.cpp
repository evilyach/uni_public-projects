#include "sort.h"
#include <vector>
#include <cmath>


void swap(int *x, int *y)
{
    /**
     * Обменивает значения параметров x и y
     *
     * @param[in/out]   x - значение первого элемента
     * @param[in/out]   y - значение второго элемента
     */

    int temp = *x;
    *x = *y;
    *y = temp;
}


void insersion_sort(std::vector<int> &vec)
{
    /**
     * @brief           Сортировка методом простых вставок
     *
     * @param[in/out]   vec - массив
     */

    for (int i = 1; i < vec.size(); ++i)
    {
        int current = vec[i];
        int j = i;

        // Пока не найден элемент с меньшим значением, чем vec[i].
        while (j > 0 && current < vec[j-1])
        {
            // Тогда все элементы сдвигаются на одну позицию вправо
            vec[j] = vec[j-1];
            j--;
        }
        vec[j] = current;
    }
}


void selection_sort(std::vector<int> &vec)
{
    /**
     * @brief           Сортировка методом простого выбора
     *
     * @param[in/out]   vec - массив
     */

    int size = vec.size();
    int min, temp;

    for (int i = 0; i < size-1; ++i)
    {
        // Выбирается минимальный элемент
        min = i;

        for (int j = i+1; j < size; ++j)
            if (vec[j] < vec[min])
                min = j;

        // Если текущий элемент не минимальный, производится обмен
        if (min != i)
             swap(&vec[i], &vec[min]);
    }
}


void bubble_sort(std::vector<int> &vec)
{
    /**
     * @brief           Сортировка методом простого выбора
     *
     * @param[in/out]   vec - массив
     */

    int size = vec.size();

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size-1; ++j)
            if (vec[j] > vec[j+1])
                swap(&vec[j], &vec[j+1]);
}


void shell_sort(std::vector<int> &vec)
{
    /**
     * @brief           Сортировка методом Шелла
     *
     * @param[in/out]   vec - массив
     */

    int size = vec.size();

    // Изначально шаг - это половина размера массива
    int step = size / 2;

    while (step > 0)
    {
        for (int i = step; i < size; ++i)
        {
            int temp = vec[i];
            int j;

            // Сортировка вставками
            for (j = i-step; j >= 0 && vec[j] > temp; j -= step)
                vec[j+step] = vec[j];
            vec[j+step] = temp;
        }
        // Уменьшаем шаг, пока он не станет единицей
        step /= 2;
    }
}


void tetragon_sort(std::vector<int> &vec)
{
    /**
     * @brief           Сортировка квадратичной выборкой
     *
     * @param[in/out]   vec - массив
     */

    int min = 0;
    int n_groups = sqrt(vec.size());
    std::vector<int> additional_list, result_list;

    // Исправление неточностей при взятии корня
    if (n_groups*n_groups < vec.size())
        n_groups++;

    // Заполняем массив бесконечностями
    additional_list.assign(n_groups, INFINITY);

    // Заполнение первичными значениями дополнительного списка
    for (int i = n_groups * min; i < vec.size(); i += n_groups)
    {
        min = i;

        for (int j = i+1; i < i + n_groups && j < vec.size(); ++j)
            if (vec[j] < vec[min])
                min = j;

        additional_list[i / n_groups] = vec[min];
        vec[min] = INFINITY;
    }

    // Основной цикл
    while (true)
    {
        // Формирование списка результатов
        min = 0;
        for (int k = 1; k < additional_list.size(); ++k)
            if (additional_list[k] < additional_list[min])
                min = k;
        result_list.push_back(additional_list[min]);

        // Точка выхода
        if (result_list.size() == vec.size())
            break;

        // Начальная точка выбора
        int i = n_groups * min;
        min = i;
        for (int j = i+1; j < i + n_groups && j < vec.size(); ++j)
            if (vec[j] < vec[min])
                min = j;

        // Добавление элемента в доп. список
        additional_list[i / n_groups] = vec[min];
        vec[min] = INFINITY;
    }
    vec = result_list;
}


void quick_sort(std::vector<int> &vec, int start, int end)
{
    /**
     * @brief           Сортировка методом Хоара (быстрая)
     *
     * @param[in/out]   vec - массив
     * @param[in]       start - левая граница
     * @param[in]       end - правая граница
     */

    if (start >= end)
        return;

    int pivot = partition(vec, start, end);
    quick_sort(vec, start, pivot-1);
    quick_sort(vec, pivot+1, end);
}


int partition(std::vector<int> &vec, int start, int end)
{
    /**
     * @brief           Функция деления массива
     *
     * @param[in/out]   vec - массив
     * @param[in]       start - левая граница
     * @param[in]       end - правая граница
     */
    int marker = start;

    for (int i = start; i <= end; ++i)
        if (vec[i] < vec[end])
        {
            swap(&vec[i], &vec[marker]);
            ++marker;
        }

    swap(&vec[marker], &vec[end]);

    return marker;
}


void merge_sort(std::vector<int> &vec, int start, int end)
{
    /**
     * @brief           Сортировка слиянием
     *
     * @param[in/out]   vec - массив
     * @param[in]       start - левая граница
     * @param[in]       end - правая граница
     */

    if (start >= end)
        return;

    int mid = (start + end) / 2;

    // Рекурсивная сортировка полученных массивов
    merge_sort(vec, start, mid);
    merge_sort(vec, mid+1, end);
    merge(vec, start, end, mid);
}


void merge(std::vector<int> &vec, int start, int end, int mid)
{
    /**
     * @brief           Функция слияния элементов
     *
     * @param[in/out]   vec - массив
     * @param[in]       start - левая граница
     * @param[in]       end - правая граница
     * @param[in]       mid - граница подмассивов
     */

    if (start >= end || mid < start || mid > end)
        return;
    if (end == start+1 && vec[start] > vec[end])
    {
        swap(&vec[start], &vec[end]);
        return;
    }

    std::vector<int> temp(&vec[start], &vec[start] + (end + 1));

    for (int i = start, j = 0, k = mid - start + 1; i <= end; ++i)
        if (j > mid - start)
            vec[i] = temp[k++];
        else if (k > end - start)
            vec[i] = temp[j++];
        else
            vec[i] = (temp[j] < temp[k]) ? temp[j++] : temp[k++];
}
