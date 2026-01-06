def solution(n):
    answer = 0
    for p in range(1,n+1):
        if (p*6)%n ==0:
            answer = p
            break
    return answer