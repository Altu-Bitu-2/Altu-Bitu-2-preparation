import sys
input = sys.stdin.readline

"""
[분산처리] - 브루트포스 풀이

- a^b의 일의 자리를 구하는 문제
- 곱한 후 계속 10으로 모듈러 연산 -> 일의 자리만 남기기
- 0이 나올 경우 10번 컴퓨터가 처리하므로, 0이 출력되지 않도록 예외처리
- 직접 b번을 하나씩 다 곱하는 풀이이므로, 효율성이 좋지 않은 코드 -> pypy3로 제출해야 제한 시간 안에 돌아간다.
"""

# 입력
t = int(input())

# 입력 + 연산
for _ in range(t):
    a, b = map(int, input().split())
    a %= 10
    
    temp = 1
    for _ in range(b):
        temp *= a
        temp %= 10

    if temp == 0:
        print(10)
        continue

    print(temp)