
class Solution:
    def findNth(self,N):
        #code here
        n = ""
        while(N):
            n = str(N%9) + n
            N = N//9
        return int(n)

N= int(input())
obj = Solution()
s = obj.findNth(N)
print(s)