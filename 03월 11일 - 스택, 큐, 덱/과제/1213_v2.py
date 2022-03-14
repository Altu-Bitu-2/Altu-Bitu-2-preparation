import sys
from collections import Counter
input = sys.stdin.readline

def make_palindrome(text):
    # 각 알파벳의 수를 가지고 팰린드롬 문자열을 리턴하는 함수
    # 만들 수 없으면 "I'm Sorry Hansoo" 리턴
    part1 = ""  # 대칭되는 부분
    part2 = ""  # 가운데 문자 (최대 1개)

    # Counter(text): 각 문자가 몇개씩 들어있는지 dictionary 형태로 돌려줌
    # .items() : key와 value를 짝 지어서 돌려줌
    # sorted - 사전적으로 가장 앞서는 문자열을 만들기 위해 정렬
    alphabets = sorted(Counter(text).items())

    for key, value in alphabets:
        if value % 2 == 1:
            # 만약 가운데 글자가 있다면 더 이상 불가능
            if (len(part2) > 0):
                # 주의! 문자열에 '가 들어있기 때문에, ""로 감싸주어야 합니다.
                return "I'm Sorry Hansoo"
            # 비어있다면, 할당
            part2 = key
        
        part1 += key * (value//2)
    
    return part1 + part2 + part1[::-1]

# 입력
text = input().rstrip()

# 연산 + 출력
print(make_palindrome(text))