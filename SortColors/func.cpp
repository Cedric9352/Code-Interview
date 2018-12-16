#include "header.h"

/**
 * hint: if we meet a zero, we just swap it with auto-inc start position,
 *       and swap it with auto-dec end position when meet a two
 */
void sort_colors(std::vector<int> &colors)
{
    using st = std::vector<int>::size_type;
    st len = colors.size(), left = 0, right = len-1, i = 0;
    while(i <= right) {
        if(colors[i] == 0) { std::swap(colors[i++], colors[left++]); }
        else if(colors[i] == 2) { std::swap(colors[i++], colors[right--]); }
        else { i++; }
    }
}
