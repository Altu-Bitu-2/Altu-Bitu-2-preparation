import sys
input = sys.stdin.readline

"""
 [컨베이어 벨트 위의 로봇 문제]
 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 -> 1 ~ 3까지가 1단계

 [문제 풀이]
 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근
 필요한 컨테이너: 내구도와 로봇의 존재여부를 체크할 배열
 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
"""

n, k = map(int, input().split())
size = 2 * n
belt = list(map(int, input().split()))
robots = [False] * size
count = 0   # 내구도가 0인 칸의 수

up_idx = 0
down_idx = n-1

step = 0

while True:
    step += 1
    up_idx = (up_idx - 1) % size
    down_idx = (down_idx - 1) % size
    
    robots[down_idx] = False

    prev_idx = down_idx
    idx = down_idx - 1
    
    while idx != up_idx:
        if robots[idx] and not robots[prev_idx] and belt[prev_idx] > 0:
            robots[idx] = False
            robots[prev_idx] = True
            belt[prev_idx] -= 1
            if belt[prev_idx] == 0:
                k -= 1
        prev_idx = idx
        idx = (idx - 1) % size

    robots[down_idx] = False

    if belt[up_idx] > 0:
        robots[up_idx] = True
        belt[up_idx] -= 1
        if belt[up_idx] == 0:
            k -= 1

    if k <= 0:
        break

print(step)