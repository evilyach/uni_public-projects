#ifndef MAIN_H
#define MAIN_H

#include <vector>

void swap(int *, int *);
void insersion_sort(std::vector<int> &);
void selection_sort(std::vector<int> &);
void bubble_sort(std::vector<int> &);
void shell_sort(std::vector<int> &);
void tetragon_sort(std::vector<int> &);
void quick_sort(std::vector<int> &, int, int);
int partition(std::vector<int> &, int, int);
void merge_sort(std::vector<int> &, int, int);
void merge(std::vector<int> &, int, int, int);

#endif // MAIN_H
