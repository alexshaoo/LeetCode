class Solution:
  def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
    def rotate_matrix(m):
      return [[m[j][i] for j in range(len(m))] for i in range(len(m[0])-1,-1,-1)]
    ans=[]
    ans.extend(matrix.pop(0))
    while (matrix):
      matrix = rotate_matrix(matrix)
      ans.extend(matrix.pop(0))
    return ans