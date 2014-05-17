class Solution:
    def reverseWords(self, s):
        string = s.split()
        string.reverse()
        ret = ''
        for i in string:
            ret += i + ' '
        return ret[:-1]
