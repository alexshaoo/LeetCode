class Solution:
    def exist(self, board, word):
        if not board: return False
        if not word: return True
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.dfs(board, word, i, j):
                    return True
        return False

    def dfs(self, board, word, i, j):
        if word[0] == board[i][j]:
            board[i][j] = '#'
            if len(word) == 1 or (i > 0 and self.dfs(board, word[1:], i-1, j)) or (i < len(board)-1 and self.dfs(board, word[1:], i+1, j)) or (j > 0 and self.dfs(board, word[1:], i, j-1)) or (j < len(board[0])-1 and self.dfs(board, word[1:], i, j+1)):
                return True
            board[i][j] = word[0]
        return False