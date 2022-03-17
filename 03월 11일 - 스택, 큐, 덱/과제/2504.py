import sys
input = sys.stdin.readline

def calc(text):
    bracket = dict()    # 괄호 쌍 저장
    bracket[')'] = '('
    bracket[']'] = '['
    value = dict()      # 괄호 값 저장
    value['('] = 2
    value['['] = 3

    stack = []
    answer = 0
    weight = 1  # 누적값 -> 밖을 감싸고 있는 괄호들의 곱
    prev = None     # 직전 괄호

    for i in text:
        if i == '(' or i =='[':
            # 여는 괄호 시 곱하기
            weight *= value[i]
            stack.append(i)
        else:
            if len(stack) == 0 or stack[-1] != bracket[i]:  # 올바르지 않은 괄호
                return 0
            if prev == bracket[i]:      # (), [] 형태가 있다면, 현재까지 누적된 값을 더해줌
                answer += weight
            
            # 괄호가 닫혔으므로, 누적값 나누기
            weight //= value[bracket[i]]
            stack.pop()
        prev = i

    if len(stack) == 0:
        return answer
    
    return 0

s = input().rstrip()
print(calc(s))