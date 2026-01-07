def solution(n):
    l=[i for i in range(1,n) if (n-1)%i==0]
    l.pop(0)
    return min(l)