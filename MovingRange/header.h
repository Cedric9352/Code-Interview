#ifndef HEADER_H
#define HEADER_H
int moving_count(int threshold, int rows, int cols);
int core(int &threshold, int &rows, int &cols, int row, int col, bool *visited);
int get_digit_sum(int num);
#endif // HEADER_H
