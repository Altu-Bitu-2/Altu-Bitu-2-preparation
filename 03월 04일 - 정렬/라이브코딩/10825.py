import sys
input = sys.stdin.readline  # 기본 input()보다는 readline이 입력 속도가 빠릅니다.

# 입력함수 작성 - 이름, 국어점수, 영어점수, 수학점수 순으로 입력이 들어오므로, 1,2,3번 인덱스의 요소들을 int형으로 바꿔줍니다.
# ex) ['Junkyu', '50', '60', '100'] -> ['Junkyu', 50, 60, 100] 
initializeInput = lambda x:[x[0], int(x[1]), int(x[2]), int(x[3])]

n = int(input())
arr = [initializeInput(input().split()) for _ in range(n)]
# sort()가 2차원 리스트를 정렬할 때, 기본적으로 리스트에 첫번째 요소부터 오름차순으로 비교를 합니다.
# 따라서 정렬 순서를 바꾸기 위해서는 key값에 람다 함수를 작성합니다.
# 람다 함수는 비교 순서대로 작성하되, 내림차순이 필요한 경우 음수를 붙여줍니다.
arr.sort(key=lambda x:(-x[1], x[2], -x[3], x[0]))

for info in arr:
    print(info[0])