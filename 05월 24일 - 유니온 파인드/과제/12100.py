import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

"""
 [2048]

 - 최대 5번을 이동시키는 모든 경우를 구한 후, 가장 큰 블록 찾는 문제 - 백트래킹 탐색
 - 움직이는 함수는 하나만 짜고, 보드를 돌려가면서 상, 하, 좌, 우 모든 방향의 움직임을 만들 수 있다.

 - 상 <-> 하: 행 순서를 뒤집어서 해결
 - 상/하 <-> 좌/우: Transpose Matrix를 만들면 된다.

 - zip(): 두개 이상의 iterable한 객체를 인자로 받아서, 순서대로 하나씩 묶어서 반환한다.
    ex) zip([1, 2, 3], ['a', 'b', 'c']) -> [1, 'a'], [2, 'b'], [3, 'c']
    따라서 zip의 인자로 각 행을 넣어주면, 행과 열이 바뀐 Transpose matrix가 나오게 된다.
"""

def up(board):
    temp = [[0]*n for _ in range(n)]
    for c in range(n):
        idx = 0
        prev = 0
        for r in range(n):
            if not board[r][c]:
                continue
            if board[r][c] == prev:
                temp[idx-1][c] *= 2
                prev = 0
            else:
                temp[idx][c] = board[r][c]
                prev = board[r][c]
                idx += 1

    return temp

def backtracking(cnt, board):
    global ans
    if cnt == 5:
        for line in board:
            ans = max(ans, max(line))
        return

    # Transpose matrix 구하기 (상 -> 좌 / 하 -> 우)
    board_t = list(zip(*board))

    # 위로
    backtracking(cnt+1, up(board))
    # 아래로
    backtracking(cnt+1, up(board[::-1]))
    # 왼쪽으로
    backtracking(cnt+1, up(board_t))
    # 오른쪽으로
    backtracking(cnt+1, up(board_t[::-1]))

    return

# 입력
n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]

ans = 0
backtracking(0, board)

# 출력
print(ans)