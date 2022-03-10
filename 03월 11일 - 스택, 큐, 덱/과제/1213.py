import sys
input = sys.stdin.readline

SIZE = 26
ORD_A = ord('A')    # A의 

def count_alphabet(text):
    # text의 알파벳 개수를 세어 리턴하는 함수
    count = [0] * SIZE  # A-Z까지 문자의 개수를 저장할 리스트
    for c in text:
        # ord(): 문자를 아스키 코드로 바꾸는 함수
        # 0번 인덱스부터 저장하기 위해 'A'의 아스키 코드를 빼줌
        count[ord(c) - ORD_A] += 1
    
    return count

def make_palindrome(count):
    # 각 알파벳의 수를 가지고 팰린드롬 문자열을 리턴하는 함수
    # 만들 수 없으면 "I'm Sorry Hansoo" 리턴
    part1 = ""  # 대칭되는 부분
    part2 = ""  # 가운데 문자 (최대 1개)

    for i in range(SIZE):
        # 만약 알파벳의 수가 홀수라면
        if (count[i] % 2 == 1):
            # 만약 가운데 글자가 있다면 더 이상 불가능
            if (len(part2) > 0):
                # 주의! 문자열에 '가 들어있기 때문에, ""로 감싸주어야 합니다.
                return "I'm Sorry Hansoo"
            # 비어있다면, 할당
            # chr(): 아스키코드를 문자로 바꾸는 함수
            part2 = chr(i + ORD_A)
        
        # 남은 수의 반을 나누어 part1에 덧붙인다.
        for j in range(count[i]//2):
            part1 += chr(i + ORD_A)
    
    return part1 + part2 + part1[::-1]

# 입력
text = input().rstrip()

# 연산 + 출력
count = count_alphabet(text)
print(make_palindrome(count))