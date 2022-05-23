SIZE = 10

"""
[양궁대회]

가능한 모든 경우를 백트래킹을 통해 검사
가장 큰 점수 "차이"로 이기는 경우를 구하는 문제
점수 차이가 같은 경우, 더 낮은 점수를 많이 맞힐 경우 선택

- 백트래킹을 할 때, 모든 경우를 연산할 필요 없음
    1. 어피치가 점수 획득을 하는 경우: 이 경우 해당 점수에는 화살을 한 발도 쏘지 않는 것이 이득
    2. 라이언이 점수 획득을 하는 경우: 필요한 최소 화살을 사용하는 것이 이득이므로 어피치보다 정확히 한 발 더 쏘면 된다.
    -> 즉, 각 경우에서 그리디한 선택을 해야 불필요한 연산을 줄일 수 있음
"""

max_diff = 1
answer = [-1]


def backtracking(idx, left, diff, ryan, appeach):
    global max_diff, answer
    if idx == SIZE:
        ryan[idx] = left
        
        if diff > max_diff:
            max_diff = diff
            answer = ryan[:]
        elif diff == max_diff:
            if ryan[::-1] > answer[::-1]:
                answer = ryan[:]
        return
    
    if left > appeach[idx]:
        ryan[idx] = appeach[idx] + 1
        backtracking(idx+1, left - ryan[idx], diff + SIZE - idx, ryan, appeach)
        ryan[idx] = 0

    if appeach[idx]:
        diff -= SIZE - idx
    backtracking(idx+1, left, diff, ryan, appeach)
    return

def solution(n, info):
    ryan = [0]*11
    backtracking(0, n, 0, ryan, info)
    
    return answer


# 디버깅 위한 메인 코드 - 프로그래머스에는 제출 X
if __name__ == "__main__":
    n = 5
    info = [2, 1, 1, 1, 0, 0, 0, 0, 0, 0]

    print(*solution(n, info))