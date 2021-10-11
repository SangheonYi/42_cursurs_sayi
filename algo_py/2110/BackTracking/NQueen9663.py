if __name__ == '__main__':
    n = int(input())
def NQueen(n):
    cnt = [0]
    queen_position = [0] * n
    visited = [False] * n
    def check_diagonal(candidate_row, candidate_column):
        for i in range(candidate_row):
            if candidate_row - i == abs(candidate_column - queen_position[i]):
                return False
        return True
    def dfs(candidate_row, cnt):
        if candidate_row == n:
            cnt[0] += 1
            return
        for candidate_column in range(n):
            if visited[candidate_column]:
                continue
            queen_position[candidate_row] = candidate_column
            if check_diagonal(candidate_row, candidate_column):
                visited[candidate_column] = True
                dfs(candidate_row + 1, cnt)
                visited[candidate_column] = False
    dfs(0, cnt)
    return cnt[0]
if __name__ == '__main__':
    print(NQueen(n), end = '')
