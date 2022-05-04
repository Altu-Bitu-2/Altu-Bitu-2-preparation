import sys
from collections import deque
input = sys.stdin.readline

"""
[Puyo Puyo] - bfs, 시뮬레이션 문제

1. bfs 탐색을 통해 4개 이상의 뿌요가 모였는지 확인
2. 4개 이상의 뿌요가 모였다면, 해당되는 영역을 '.'으로 바꾸어 비워줌
3. 전체 필드에 대해 1~2를 다 수행한 후, 뿌요를 떨어뜨림
    - 바닥부터 시작해서 남아있는 뿌요들을 모으고, 남은 부분은 '.'으로 채우는 방식
4. 터뜨릴 수 없을 때까지 반복

여기서, 3번 과정을 편하게 하기 위해 12*6으로 들어오는 입력을 6*12로 바꾸어준다.
그 이후는, 같은 열에 있는 데이터를 다루는 것보다 같은 행에 있는 데이터를 다루는 것이 편하기 때문이다.
"""

def bfs(i, j):
    dr = [-1, +1, 0, 0]
    dc = [0, 0, -1, +1]
    que = deque()
    
    que.append((i, j))
    visited = [[False]*12 for _ in range(6)]
    visited[i][j] = True
    color = board[i][j]
    count = 1   # 모여있는 뿌요의 개수
    cords = []  # 포함된 좌표 저장할 리스트

    while que:
        cords.append(que[0])
        r, c = que.popleft()
        for x in range(4):
            nr, nc = r+dr[x], c+dc[x]
            if not (0 <= nr < 6 and 0 <= nc < 12):
                continue
            if not visited[nr][nc] and board[nr][nc] == color:
                visited[nr][nc] = True
                que.append((nr, nc))
                count += 1
    
    if count < 4:
        return False

    for r, c in cords:
        board[r][c] = '.'

    return True

# 뿌요를 터뜨린 이후의 새 필드를 작성하는 함수
def make_new_board(board):
    new_board = []
    for i in range(6):
        temp = []
        for j in range(12):
            if board[i][j] != '.':
                temp.append(board[i][j])
        while len(temp) < 12:
            temp.append('.')
        new_board.append(temp[:])
    return new_board

# 입력
board = [[None]*12 for _ in range(6)]

for i in range(12):
    line = input().rstrip()
    for j in range(6):
        board[j][12-i-1] = line[j]
        
ans = 0

while True:
    flag = False
    for i in range(6):
        for j in range(12):
            if board[i][j] == '.':
                continue
            if bfs(i, j):
                flag = True
    
    if flag:
        ans += 1
        board = make_new_board(board)
    else:
        break

print(ans)