import sys
input = sys.stdin.readline

n = int(input())
arr = [input().rstrip() for _ in range(n)]

def sumDigit(text):
    """
    text(string) -> total(int)
    ---
    문자열 중 숫자를 모두 더한 값을 반환합니다.
    """
    total = 0
    for c in text:
        if '0' <= c <= '9':
            total += int(c)
    return total

# 정렬의 우선순위에 맞춰서 람다함수를 작성합니다.
# 첫번째는 문자열의 길이, 두번째가 숫자의 합, 세번째가 사전순 입니다.
arr.sort(key=lambda x:(len(x), sumDigit(x), x))

print('\n'.join(arr))