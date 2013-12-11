// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    string intToRoman(int num) {
    	map<int, char> roman;
        m[1]   	= 'I';
        m[5]   	= 'V';
        m[10]  	= 'X';
        m[50]  	= 'L';
        m[100]  = 'C';
        m[500]  = 'D';
        m[1000] = 'M';
    	
    	string res;
    	for (int i = num; i; i /= 10) {
    		int digit = i % 10;
    		if ()
    	}
    }
};
