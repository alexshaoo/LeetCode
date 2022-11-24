class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board: return False
        m,n=len(board),len(board[0])
        target,visited=len(word),set()
        def dfs(i,j,pos,target):
            nonlocal m,n,visited
            if pos==target:
                return True
            if 0<=i<m and 0<=j<n and board[i][j]==word[pos] and (i,j) not in visited:
                visited.add((i,j))
                if dfs(i+1,j,pos+1,target) or dfs(i-1,j,pos+1,target) or dfs(i,j+1,pos+1,target) or dfs(i,j-1,pos+1,target):
                    return True
                visited.remove((i,j)) # backtracking
            return False

        for i in range(m):
            for j in range(n):
                if dfs(i,j,0,target):
                    return True
        return False