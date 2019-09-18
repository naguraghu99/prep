from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i,v in enumerate(nums):
            remaining = target - v
            if remaining in seen:
                return [seen[remaining], i]
            seen[v] = i
            
        return []
'''   def twoSum(self, nums: List[int], target: int) -> List[int]:
        sortedList = sorted(nums)
        low = 0
        high = len(sortedList) - 1
        for i in range(len(sortedList)):
            localLow = target - sortedList[high]
            localHigh = target - sortedList[low]
            
            if sortedList[low] == localLow or sortedList[high] == localHigh:
                return [low,high]
            
            if localLow > 0 and localLow > sortedList[low]:
                low = low + 1
                
            if localHigh < sortedList[high]:
                high = high - 1
                
            if high <= low:
                return []
'''


def main():
    s = Solution()
    print(s.twoSum([3,2,4],6))

if __name__ == '__main__':
    main()