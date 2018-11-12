#include "header.h"

/**
 * hint: dynamic programming, boolean array represents string from i to j is a palindrome or not
 * you need not only [i,i], but also [i,i+1] as initial value
 */
std::string longest_palindrome(std::string s)
{
    int n = s.length();
    if(n == 0) { return s; }
    int b = 0, max_len = 0;
    bool dp[n][n];
    for(int i = n-1; i >= 0; --i) {
        for(int j = i; j < n; ++j) {
            if(i == j) { dp[i][j] = true; }
            else if(i == j-1) {
                dp[i][j] = s[i] == s[j] ? true : false;
            } else {
                if(s[i] == s[j]) { dp[i][j] = dp[i+1][j-1]; }
                else { dp[i][j] = false; }
            }
            if(dp[i][j] && max_len <= j-i+1) {
                b = i;
                max_len = j-i+1;
            }
        }
    }
    return s.substr(b, max_len);
}
