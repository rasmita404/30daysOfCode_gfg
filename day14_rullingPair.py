class Solution:
    def RulingPair(self, arr, n):
        # Your code goes here
        dic = {}  # to store the maximum number present for a particular digit sum
        for e in arr:
            sumn = 0
            strr = str(e)
            sumn = sum(list(map(int, strr.strip())))
            if sumn not in dic:
                dic[sumn] = list()  # create the key
            dic[sumn].append(e)  # append element with same sum as key
        s = -9999
        pairs = 0
        for val in dic.values():
            # print(val)
            size = len(val)
            if size >= 2:
                val.sort()
                pairs += 1
                s = max(s, val[size - 1] + val[size - 2])

        if pairs == 0:
            return -1
        else:
            return s

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        obj = Solution();
        print(obj.RulingPair(arr,n))
