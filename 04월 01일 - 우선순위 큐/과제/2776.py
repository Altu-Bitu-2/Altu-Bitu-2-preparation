import sys
import heapq as hq
input = sys.stdin.readline

testcase = int(input())

# 힙에서 유효하지 않은 값 삭제하는 함수
def remove_invalid_data(heap):
    # 힙에 데이터가 하나라도 있고, top이 invalid 하면 pop해줌
    while heap and not is_valid[heap[0][1]]:
        hq.heappop(heap)
    return

for _ in range(testcase):
    t = int(input())

    max_heap = list()
    min_heap = list()
    is_valid = list()    
    idx = 0
    
    for _ in range(t):
        cmd, n = input().split()
        if cmd == 'D':
            if int(n) == 1:
                remove_invalid_data(max_heap)
                if max_heap:
                    is_valid[hq.heappop(max_heap)[1]] = False
            else:
                remove_invalid_data(min_heap)
                if min_heap:
                    is_valid[hq.heappop(min_heap)[1]] = False
        else:
            hq.heappush(max_heap, (-int(n), idx))
            hq.heappush(min_heap, (int(n), idx))
            is_valid.append(True)
            idx += 1

    remove_invalid_data(max_heap)
    remove_invalid_data(min_heap)

    if max_heap:
        print(-max_heap[0][0], min_heap[0][0])
    else:
        print("EMPTY")