// Implement strStr().
// Returns a pointer to the first occurrence of needle in haystack, 
// or null if needle is not part of haystack.

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int len1 = strlen(haystack), len2 = strlen(needle);
        if (len2 == 0)
            return haystack;

        for (int i = 0, j = 0; i <= len1-len2; i++) {
            int k = i;
            while (haystack[k] == needle[j]) {
                k++;
                j++;
                if (j == len2)
                    return haystack + i;
            }
            j = 0;
        }
        return NULL;
    }
};
