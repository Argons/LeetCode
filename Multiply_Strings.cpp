// Given two numbers represented as strings, return multiplication of 
// the numbers as a string.
// Note: The numbers can be arbitrarily large and are non-negative.

class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.length(), l2 = num2.length();
        if (l1 == 0 || l2 == 0)
            return "";
        string ret = "";
        int carry = 0;
        for (int i = 1; i <= l1+l2; i++) {
            int curRet = 0;
            for (int j = 1; j <= i; j++) {  
                // calculate result at the ith bit
                // ret[i] = num1[1]*num2[i] + num1[2]*num2[i-1] + ... 
                //          + num1[i]*num2[1]
                if (l1 - j >= 0 && l2 - (i+1-j) >= 0) {
                    curRet += (num1[l1-j]-'0') * (num2[l2-(i+1-j)]-'0');
                }
            }
            char cur = '0' + (curRet+carry) % 10;
            ret = cur + ret;
            carry = (curRet+carry) / 10;
        }
        int i = 0;
        while (i < ret.length() && ret[i] == '0') {  // clear all 0 at the front
            i++;
        }
        return ret.length() == i ? "0" : ret.substr(i);
    }
};
