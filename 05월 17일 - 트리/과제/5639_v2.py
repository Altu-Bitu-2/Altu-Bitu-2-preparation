import sys
sys.setrecursionlimit(10**6)

"""
 Ver2. 트리를 직접 작성하지 않고, 바로바로 출력하는 풀이

 전위순회 - V L R
 후위순회 - L R V
    -> 왼쪽 서브트리와 오른쪽 서브트리를 나누어서 재귀적으로 후위순회를 구함
"""

def preorder_to_postorder(start, end):
    if start > end:
        return

    curr = preorder[start]

    # 오른쪽 자식이 없는 경우
    if preorder[end] <= curr:
        idx = end + 1
    else:
        # 오른쪽 자식이 시작되는 인덱스 찾기
        for i in range(start+1, end+1):
            if preorder[i] > curr:
                idx = i
                break

    preorder_to_postorder(start + 1, idx-1) # 왼쪽 서브 트리
    preorder_to_postorder(idx, end) # 오른쪽 서브 트리
    postorder.append(curr)

# 입력 & 연산
preorder = [int(i) for i in sys.stdin]
postorder = []

preorder_to_postorder(0, len(preorder)-1)
print(*postorder)