def solution(a, b):
    lst=[a,b]
    x=max(lst)
    y=min(lst)
    answer = sum([i for i in range(y,x+1)])
    return answer