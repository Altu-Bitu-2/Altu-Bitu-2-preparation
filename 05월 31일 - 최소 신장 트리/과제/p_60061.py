board = []

def delete(x, y, a, n):
    for dx in (-1, 0, 1):
        for dy in (-1, 0, 1):
            nx, ny = x+dx, y+dy
            if 0<= nx <= n and 0 <= ny <= n:
                for j in range(2):
                    if board[nx][ny][j]:
                        if not validate(nx, ny, j, n):
                            return False

    return True

def validate(x, y, a, n):
    # 현재 상태가 조건에 만족하는지 확인 x, y 중심으로 --
    # 기둥
    if a == 0:
        # 바닥 위
        if y == 0:
            return True
        # 보의 왼쪽 끝
        if board[x][y][1]:
            return True
        # 보의 오른쪽 끝
        if x > 0 and board[x-1][y][1]:
            return True
        # 기둥 위
        if y > 0 and board[x][y-1][0]:
            return True
        
    # 보
    else:
        # 왼쪽 끝이 기둥 위
        if y>0 and board[x][y-1][0]:
            return True
        # 오른쪽 끝이 기둥 위
        if x < n and y > 0 and board[x+1][y-1][0]:
            return True
        # 양쪽 끝이 보와 연결
        if 0 < x < n-1 and board[x-1][y][1] and board[x+1][y][1]:
            return True
        
    return False
    

def solution(n, build_frame):
    global board
    board = [[[False]*2 for _ in range(n+1)] for _ in range(n+1)]
    answer = []
    for x, y, a, b in build_frame:
        if b == 0:
            board[x][y][a] = False
            if not delete(x, y, a, n):
                board[x][y][a] = True
        else:
            if validate(x, y, a, n):
                board[x][y][a] = True
                
    for i in range(n+1):
        for j in range(n+1):
            for k in range(2):
                if board[i][j][k]:
                    answer.append([i, j, k])
    return answer