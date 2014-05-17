class Solution:
    # @return an integer
    def threeSumClosest(self, num, target):
        if len(num) < 3:
            return sum(num)
        num.sort()
        closest = num[0] + num[1] + num[2]
        for i in range(len(num)-2):
            cur = target - num[i]
            start, end = i+1, len(num)-1
            while start < end:
                SUM = num[start] + num[end] 
                if SUM == cur:
                    return target
                elif SUM < cur:
                    start += 1
                else:
                    end -= 1
                if abs(closest-target) > abs(num[i]+SUM-target):
                    closest = num[i] + SUM
        return closest
