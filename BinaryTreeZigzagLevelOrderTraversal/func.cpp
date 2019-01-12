#include "header.h"
#include "deque"
std::vector<std::vector<int>> zigzagLevelOrder(tree_node<int> *root) {
    std::deque<tree_node<int>*> dq;
    std::vector<std::vector<int>> result;
    if(root != nullptr) {
        dq.push_back(root);
        bool reverse = true;
        while(!dq.empty()) {
            int sz = dq.size();
            std::vector<int> bucket;
            reverse = !reverse;
            while(sz--) {
                if(reverse) {
                    tree_node<int> *currNode = dq.front();
                    dq.pop_front();
                    bucket.push_back(currNode->_t);
                    if(currNode->_right != nullptr) { dq.push_back(currNode->_right); }
                    if(currNode->_left != nullptr) { dq.push_back(currNode->_left); }
                } else {
                    tree_node<int> *currNode = dq.back();
                    dq.pop_back();
                    bucket.push_back(currNode->_t);
                    if(currNode->_left != nullptr) { dq.push_front(currNode->_left); }
                    if(currNode->_right != nullptr) { dq.push_front(currNode->_right); }
                }
            }
            result.push_back(bucket);
        }
    }
    return result;
}
