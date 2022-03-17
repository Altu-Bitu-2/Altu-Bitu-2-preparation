import sys
from itertools import combinations_with_replacement # 중복선택이 가능한 조합
input = sys.stdin.readline

"""
[Four Squares]
자연수 n에 대해 최소 몇개의 제곱수의 합으로 표현할 수 있는지 찾는 문제
"""

MAX = 50000

def find_min_number(n):
    squares = [i*i for i in range(1, int(MAX**(1/2))+1)]

    if (int(n**(1/2)))**2 == n:
        return 1
    
    for num in range(2, 4):
        combi = combinations_with_replacement(squares, num)
        sum_list = list(map(lambda x:sum(x), combi))
        if n in sum_list:
            return num
        
    return 4


n = int(input())
print(find_min_number(n))