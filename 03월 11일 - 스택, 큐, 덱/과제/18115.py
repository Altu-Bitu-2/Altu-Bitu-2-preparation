import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
cmd = list(map(int, input().split()))

card = list(range(n, 0, -1))
playing = deque()

for i in cmd[::-1]:
    if i == 1:
        playing.append(card.pop())
    elif i == 2:
        temp = playing.pop()
        playing.append(card.pop())
        playing.append(temp)
    else:
        playing.appendleft(card.pop())

for i in range(n):
    print(playing.pop(), end=' ')