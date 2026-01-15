def solution(n):
    answer = 0
    #n을  제곱근을 씌운다. -> 정수형 변환씌운것과 같으면 x+1, 아니면 -1
    x=n**(1/2)
    if int(x)==x:
        answer = (x+1)**2
    else:
        answer = -1
    return answer