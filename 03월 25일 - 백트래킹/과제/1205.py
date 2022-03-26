import sys
input = sys.stdin.readline

"""
[등수 구하기]

1. n = 0일 때, 고려
2. 등수는 p보다 작지만, 랭킹 리스트에 들어가지 못하는 경우 고려

.find(value): value가 있는 첫번째 인덱스를 리턴, 없으면 에러 발생
입력된 점수를 기존 리스트에 넣고 인덱스 구하기 -> 해당 점수의 첫번째 인덱스 리턴
입력된 점수 -1를 기존 리스트에 넣고 인덱스 구하기 -> 해당 점수의 마지막 인덱스 리턴

마지막 인덱스로 구한 등수가 p를 넘지 않으면, 첫번째 인덱스로 구한 등수가 정답
"""

# 입력
n, new_score, p = map(int, input().split())

if n == 0:
    answer = 1
else:
    # 입력
    scores = list(map(int, input().split()))
    
    # 해당 점수의 가장 상위 등수 구하기
    scores.append(new_score)
    scores.sort(reverse=True)
    first_idx = scores.index(new_score)

    # 해당 점수의 가장 하위 등수 구하기
    scores[first_idx] -= 1
    scores.sort(reverse=True)
    second_idx = scores.index(new_score - 1)

    # 이미 스코어 보드가 다 찬 경우
    if second_idx + 1 <= p:
        answer = first_idx + 1
    else:
        answer = -1

print(answer)