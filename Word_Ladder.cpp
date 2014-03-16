// Given two words (start and end), and a dictionary, find the length 
// of shortest transformation sequence from start to end, such that:
// 1. Only one letter can be changed at a time
// 2. Each intermediate word must exist in the dictionary

// For example,
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // breadth first search
        unordered_set<string> visited;
        visited.insert(start);

        queue<string> sq;
        sq.push("#");  // mark the end of each level
        sq.push(start);

        int step = 1;
        string cur;
        while (!sq.empty()) {
            cur = sq.front();
            sq.pop();
            if (cur == "#") {  
                // reach the end of the last level, imply that 
                // all strings at current level are enqued.
                if (!sq.empty()) {
                    step++;
                    sq.push("#");
                    continue;
                } 
                else return 0;  // 'start' cannot convert to 'end'
            }

            for (int i = 0; i < cur.length(); i++) {
                string word = cur;
                for (char j = 'a'; j <= 'z'; j++) {
                    if (j != cur[i])
                        word[i] = j;
                    if (word == end)
                        return step;
                    if (dict.find(word) != dict.end() && 
                        visited.find(word) == visited.end()) {
                        sq.push(word);
                        visited.insert(word);
                    }
                }
            }
        }
        return 0;
    }
};
