/**
 * hint: do backtracking recursively
 */
bool core(const char *matrix, const int &rows, const int &cols, int row, int col, const char *str, int &pathLength, bool *visited)
{
    if(str[pathLength] == '\0') {
        return true;
    }
    bool hasPath = false;
    if(row >= 0 && row <= rows && col >= 0 && col <= cols &&
       matrix[row*cols+col] == str[pathLength] && !visited[row*cols+col]) {
        ++pathLength;
        visited[row*cols+col] = true;
        hasPath = core(matrix, rows, cols, row+1, col, str, pathLength, visited) ||
            core(matrix, rows, cols, row, col+1, str, pathLength, visited) ||
            core(matrix, rows, cols, row-1, col, str, pathLength, visited) ||
            core(matrix, rows, cols, row, col-1, str, pathLength, visited);
        // if no path, back to origin(relatively)
        if(!hasPath) {
            --pathLength;
            visited[row*cols+col] = false;
        }
    }
    return hasPath;
}
bool has_path(const char *matrix, const int &rows, const int &cols, const char *str)
{
    if(matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr) {
        return false;
    }
    bool visited[rows*cols] = {false};
    int pathLength = 0;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(core(matrix, rows, cols, i, j, str, pathLength, visited)) {
                return true;
            }
        }
    }
    return false;
}
