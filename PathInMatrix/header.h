#ifndef HEADER_H
#define HEADER_H
bool has_path(const char *matrix, const int &rows, const int &cols, const char *str);
bool core(const char *matrix, const int &rows, const int &cols, int row, int col, const char *str, int &pathLength, bool *visited);
#endif // HEADER_H
