# Suppose a sorted array is rotated at some pivot unknown to you beforehand.
# (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). Find the minimum element.
# You may assume no duplicate exists in the array.

class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        if not num: return 
        i, j = 0, len(num)-1
        while i <= j:
            mid = (i+j) / 2
            if num[mid] < num[i]:
                if num[mid] < num[mid-1]: return num[mid]
                j = mid - 1
            elif num[mid] > num[i]:
                if num[mid] > num[j]: i = mid + 1
                else: j = mid - 1
            else: return min(num[i], num[j])
