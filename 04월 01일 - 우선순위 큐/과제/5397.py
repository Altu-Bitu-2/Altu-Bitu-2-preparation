import sys
from collections import deque
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    front = deque() # 커서 이전 내용을 저장
    back = deque()  # 커서 이후 내용을 저장

    log = input().rstrip()
    
    for c in log:
        # 현재 커서 앞에 있는 글자를 지운다.
        if c == '-':
            if front:
                front.pop()
        # 커서를 왼쪽으로 이동 -> front의 마지막 원소를 back 앞에 삽입
        elif c == '<':
            if front:
                back.appendleft(front.pop())
        # 커서를 오른쪽으로 이동 -> front의 마지막 원소를 back 앞에 삽입
        elif c == '>':
            if back:
                front.append(back.popleft())
        # 문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 front에 삽입
        else:
            front.append(c)
    
    print(''.join(front)+''.join(back))