// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, 
// such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> store;
        string dir = "";
        path += '/'; // easier for dealing with the last dir

        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/') {
                if (dir == "..") {
                    if (!store.empty()) {
                        store.pop();
                    }
                } else if (!dir.empty() && dir != ".") { // ignore "//" or "./"
                    store.push(dir);
                }
                dir.clear();
            } else {
                dir += path[i];
            }
        }

        string ret = "";
        while (!store.empty()) {
            ret = '/' + store.top() + ret;
            store.pop();
        }
        return ret.empty() ? "/" : ret;
    }
};
