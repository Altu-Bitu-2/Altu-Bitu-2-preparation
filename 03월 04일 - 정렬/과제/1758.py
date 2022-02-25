import sys
input = sys.stdin.readline

n = int(input())
tip_arr = [int(input()) for _ in range(n)]
tip_arr.sort(reverse=True)  # 내림차순으로 정렬

answer = 0
for i in range(n):
    # i는 인덱스로, 실제 등수 -1 한 값입니다.
    # i가 tip보다 작아진 순간, 그 이후로는 팁을 받을 수 없으므로 반복문을 종료합니다.
    if tip_arr[i] >= i:
        answer += tip_arr[i] - i
    else:
        break

print(answer)