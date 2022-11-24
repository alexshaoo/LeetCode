class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        def count(i,j,ind,seen):
            if (i,j) in seen or i<0 or j<0 or i>=len(board) or j>=len(board[0]) or board[i][j]!=word[ind]:
                return False

            if ind==len(word)-1:
                return True

            seen.add((i,j))
            l = count(i-1,j,ind+1,seen)
            r = count(i,j+1,ind+1,seen)
            u = count(i,j-1,ind+1,seen)
            b = count(i+1,j,ind+1,seen)
            seen.discard((i,j))

            return l or u or r or b


        m,n = len(board),len(board[0])
        for i in range(m):
            for j in range(n):
                if board[i][j]==word[0]:
                    seen = set()
                    if count(i,j,0,seen):
                        return True
        return False