#include <stack>
#include "header.h"

/**
 * hint: if there is a number that cannot be found after pushing all numbers in stack,
 *       then it is wrong order
 */
bool is_push_pop_order(const int *push, const int *pop, int length)
{
    bool res = false;
    if(push != nullptr && pop != nullptr && length > 0) {
        const int *pushNext = push, *popNext = pop;
        std::stack<int> s;
        while(popNext - pop < length) {
            while(pushNext - push != length &&
                  (s.empty() || s.top() != *popNext)) {
                s.push(*pushNext++);
            }
            if(s.top() != *popNext) {
                break;
            }
            s.pop();
            ++popNext;
        }
        if(s.empty() && popNext - pop == length) {
            res = true;
        }
    }
    return res;
}
