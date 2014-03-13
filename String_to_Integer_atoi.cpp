// Implement atoi to convert a string to an integer.

// Hint: Carefully consider all possible input cases. If you want a challenge, 
// please do not see below and ask yourself what are the possible input cases.

// Notes: It is intended for this problem to be specified vaguely, You are 
// responsible to gather all the input requirements up front.

class Solution {
public:
    int atoi(const char *str) {
        int ret = 0;
        int sign = 1;
        while (*str != '\0' && *str == ' ') {
            str++;  // omit spaces
        }
        if (*str == '+') {
            str++;  
        }
        if (*str == '-') {
            sign = -1;  // check sign of integer
            str++;
        }
        while (*str != '\0') {
            if (*str < '0' || *str > '9')
                break; 
            if (ret > INT_MAX/10 || (ret == INT_MAX/10) && 
                                    (*str-'0') > INT_MAX%10) {  
                // check overflow
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ret = 10 * ret + (*str - '0');
            str++;
        }
        return sign * ret;
    }
};
