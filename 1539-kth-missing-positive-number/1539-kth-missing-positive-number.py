class Solution:
  def findKthPositive(self, arr: List[int], k: int) -> int:
    # a,b = 0,l-1
    # while a < b:
    #   m = (a+b)//2
    #   if g[m] <= k:
    #     a = m+1
    #   else:
    #     b = m-1
    #   print(a,b)
    # # print(g)
    # if g[a] > k:
    #   a -= 1
    # d = k-g[a]
    # # print(a,b)
    # print(arr,g,arr[a+1],k,g[a])
    # return arr[a+1]+k-g[a]
    return k + bisect_left(range(len(arr)), k, key=lambda i: arr[i]-i-1)