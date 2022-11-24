class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def bt(r, c, word_idx):
            if word_idx == len(word):
                return True
            
            if not (0 <= r < len(board) and 0 <= c < len(board[0]) and board[r][c] == word[word_idx]):
                return False
            
            board[r][c], initial_char = None, board[r][c]
            
            for (r2, c2) in ((r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)):
                if bt(r2, c2, word_idx + 1):
                    return True
            
            board[r][c] = initial_char
        
        word_counter = Counter(word)
        board_counter = Counter(sum(board, []))
        
        for char, word_char_count in word_counter.items():
            if board_counter[char] < word_char_count:
                return False
        
        # if the last letter from the word is a less common char on the board than the first letter
        # then we can reverse the word that we're searching for to reduce the search space
        # (because there will be fewer valid starting positions)
        if word_counter[word[-1]] < word_counter[word[0]]:
            word = word[::-1]
        
        for row_idx in range(len(board)):
            for col_idx in range(len(board[0])):
                if bt(row_idx, col_idx, 0):
                    return True
        
        return False