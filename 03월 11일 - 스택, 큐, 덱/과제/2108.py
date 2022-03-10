import sys
from math import floor  # round 함수를 대체할 floor(내림)함수
input = sys.stdin.readline

def find_mode(n, arr):
    # 정렬된 벡터에서 최빈값을 찾아 반환하고, 만약 최빈값이 여러개라면 두번째로 작은 값을 반환하는 함수
    count = [] # [정수의 값, 정수의 개수]으로 구성된 리스트

    current_idx = 0 # 현재 인덱스를 저장하는 변수
    count.append([arr[0], 1])   # 첫번째 값을 미리 입력하여 for문에서 index 에러 방지
    # 주의! 이때 튜플을 사용하면, 값을 업데이트 할 수 없음

    for i in range(1, n):
        # 만약 직전 값과 같은 값이라면
        if arr[i] == arr[i-1]:
            # 개수 + 1
            count[current_idx][1] += 1
        else:
            # 그렇지 않다면, 새로운 값을 count리스트에 추가
            count.append([arr[i], 1])
            current_idx += 1

    # 만약 값이 한 종류라면, 바로 리턴 -> 아래에서 인덱스 에러 방지
    if current_idx == 0:
        return arr[0]

    # 정렬
    # 1. 개수에 대해 내림차순
    # 2. 값에 대해 오름차순
    count.sort(key=lambda x:(-x[1], x[0]))

    # 최빈값이 여러개인지 확인
    if count[0][1] == count[1][1]:
        return count[1][0]
    
    return count[0][0]


def print_values(n, arr):
    # 산술평균
    # python의 round 함수는 사사오입 원칙을 따릅니다.
    # 즉, 반올림 할 숫자가 5이면 앞자리를 짝수로 만들도록 올림/내림합니다.
    # 따라서, 우리가 원하는 출력을 하기 위해서는 round 함수를 쓰면 안됩니다.
    mean = sum(arr) / n
    print(floor(mean + 0.5))    # 0.5를 더해 내림해주면, 우리가 생각한대로 4까지는 내림, 5부터는 올림 연산을 수행하게 됩니다.

    # 중앙값
    print(arr[n//2])

    # 최빈값
    print(find_mode(n, arr))

    # 범위
    print(arr[-1] - arr[0])


n = int(input())
arr = [int(input()) for _ in range(n)]
arr.sort()

print_values(n, arr)