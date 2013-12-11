// Given a roman numeral, convert it to an integer.
// Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        if (len == 0)
            return 0;
            
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int sum = m[s[len-1]];
        for (int i = len-2; i >= 0; i--) {
            if (m[s[i+1]] <= m[s[i]])
                sum += m[s[i]];
            else
                sum -= m[s[i]]; // IV, IX, XL, ...
        }
        return sum;
    }
};
