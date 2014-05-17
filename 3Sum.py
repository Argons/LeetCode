class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, num):
        ret = []
        num.sort()
        i = 0
        while i < len(num) - 2:
            if num[i] > 0 or num[-1] < 0:
                break
            target = -num[i]
            start, end = i + 1, len(num) - 1
            
            while start < end:
                if num[start] + num[end] == target:
                    ret.append([num[i], num[start], num[end]])
                    start += 1
                    end -= 1
                    
                    while start < end and num[start] == num[start-1]:
                        start += 1
                    while start < end and num[end] == num[end+1]:
                        end -= 1
                        
                elif num[start] + num[end] < target:
                    start += 1
                else: 
                    end -= 1
            while i < len(num)-2 and num[i] == num[i+1]:
                i += 1
            i += 1
        return ret
