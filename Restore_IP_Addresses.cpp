// Given a string containing only digits, restore it by returning all possible 
// valid IP address combinations.

// For example:
// Given "25525511135",
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

class Solution {
public:
    bool isValid(const string &s) {
        if (s.size() > 3 || !s.size() || s.size() > 1 && s[0] == '0')
            return false;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum *= 10;
            sum += s[i] - '0';
        }
        return sum >= 0 && sum <= 255;
    }

    void findIP(const string &s, int start, int count, 
                vector<string> &ret, string &IP) {
        if (count == 3 && isValid(s.substr(start))) {
            ret.push_back(IP+s.substr(start));
            return;
        }
        if (s.length()-start > (4-count)*3) // prune the bad partitions
            return;

        for (int i = 1; i <= 3 && start+i <= s.length(); i++) {
            string str = s.substr(start, i);
            if (isValid(str)) {
                str = IP + str + '.';
                findIP(s, start+i, count+1, ret, str);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string IP;
        findIP(s, 0, 0, ret, IP);
        return ret;
    }
};
