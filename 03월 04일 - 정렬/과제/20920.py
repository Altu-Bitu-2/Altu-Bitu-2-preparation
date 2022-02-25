import sys
input = sys.stdin.readline

n, k = map(int, input().split())
# 기본 input() 함수와 달리, readline은 줄 끝에 개행문자('\n')까지 입력됩니다.
word = [input().rstrip() for _ in range(n)]
print(word)