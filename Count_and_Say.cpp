// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string.

class Solutions {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        // get the n-1 sequence
        string before = countAndSay(n-1);
        string current = "";

        int len = before.length();
        int count = 1;
        for (int i = 1; i < len; i++) {
            if (before[i] == before[i-1]) {
                count++;
            }
            // meet different digit, append the former(repeating) digit.
            else {
                current += char('0'+count);
                current += before[i-1];
                count = 1;
            }
        }
        // append the last digit
        current += char('0'+count);
        current += before[len-1];
        return current;
    }
};
