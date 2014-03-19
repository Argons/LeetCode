// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
// of rows like this:
// (you may want to display this pattern in a fixed font for better legibility)
//   P   A   H   N
//   A P L S I I G
//   Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a 
// number of rows:  string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1)
            return s; 
        int len = s.length();
        string result(len, ' ');
        int unit = 2 * (nRows-1); // char number in one unit
        int leftover = len % unit;  
        int midLen = len / unit * 2;
        int endLen = len / unit + (leftover >= nRows);

        for (int i = 0; i*unit < len; i++) { // first row
            result[i] = s[i*unit];
        }
        for (int j = 0; j < endLen; j++) { // last row
            result[len-endLen+j] = s[nRows-1 + j*unit];
        }

        int start = len / unit + (leftover > 0); // start index of the next row
        for (int i = 1; i < nRows-1; i++) {
            int j = 0;
            for (; i + j*unit < len; j++) {
                result[start + 2*j] = s[i + j*unit];
                if (unit-i + j*unit < len) { 
                    // check boundary for the adjacent char in the same unit
                    result[start + 2*j+1] = s[unit-i + j*unit];
                }
            }
            start += 2 * j - (unit-i + (j-1)*unit >= len);
        }
        return result;
    }
};
