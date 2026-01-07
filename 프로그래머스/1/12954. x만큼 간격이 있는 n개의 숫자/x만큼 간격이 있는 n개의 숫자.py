def solution(x, n):
    s=0
    answer = []
    for i in range(n):
        s+=x
        answer.append(s)
    return answer