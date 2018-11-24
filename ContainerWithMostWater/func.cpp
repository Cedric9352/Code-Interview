#include "header.h"

/**
 * hint: if one is less than minimum height of two side, then ++ or -- because it never contains
 * more water than two side(less height and less length)
 */
int container_with_most_water(std::vector<int> height)
{
    unsigned int e = height.size()-1, b = 0, maxArea = 0;
    while(b < e) {
        int h = height[b] <= height[e] ? height[b] : height[e];
        maxArea = maxArea >= (e-b)*h ? maxArea : (e-b)*h;
        while(b < e && height[b] <= h) { ++b; }
        while(b < e && height[e] <= h) { --e; }
    }
    return maxArea;
}
