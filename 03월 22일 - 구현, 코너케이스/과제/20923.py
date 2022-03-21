import sys
input = sys.stdin.readline

"""
[숫자 할리갈리 게임] - 시뮬레이션 문제
- 언어별 추가시간이 없으므로, pypy3으로 제출

- 카드 덱과 그라운드의 카드를 관리하기 위해 덱 사용

1. 차례가 되면, 상단 카드를 그라운드에 놓는다.
2. 누군가의 카드 덱이 비는 즉시 게임 종료
3. 종을 치면, 상대방의 그라운드 카드를 뒤집어서 카드 더미의 밑에 넣는다.
"""

def play_game(cards, ground):
    player = 0
    
    ground[0].append(-1)    # index 에러 방지
    ground[1].append(-1)

    for _ in range(m):
        ground[player].append(cards[player].pop())
        
        if len(cards[player]) == 0:
            return 1 - player

        player = 1 - player     # 다음 플레이어

        if ground[0][-1] == 5 or ground[1][-1] == 5:
            hit = 0     # 도도
        elif (ground[0][-1] + ground[1][-1] == 5):
            hit = 1     # 수연
        else:
            continue

        temp = 1 - hit  # 옮길 그라운드의 번호

        for _ in range(2):
            # index 에러 방지 -1 제거
            ground[temp].popleft()

            while (ground[temp]):
                cards[hit].appendleft(ground[temp].popleft())
            
            ground[temp].append(-1) # 인덱스 방지 -1 다시 추가
            temp = 1 - temp
        
    if len(cards[0]) > len(cards[1]):
        return 0
    elif len(cards[0]) < len(cards[1]):
        return 1
    else:
        return 2

n, m = map(int, input().split())

cards = [deque() for _ in range(2)]
ground = [deque() for _ in range(2)]
name = ["do", "su", "dosu"]     # 출력할 이름

for _ in range(n):
    a, b = map(int, input().split())
    cards[0].append(a)
    cards[1].append(b)

print(name[play_game(cards, ground)])