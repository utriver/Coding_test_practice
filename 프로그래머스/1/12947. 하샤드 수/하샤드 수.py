def solution(x):
    #x의 자릿수 합으로 x가 나누어 떨어져야함: 12->12/(1+2), 11->11/(1+1)
    #새로운 변수 선언-> 각 자리 수 합을 구해야함
    #각 자리수는 정수를 str로 변환 -> 반복문으로 다시 int변환 후 합쳐서 새로운 변수에 할당
    #조건 문으로 true, false구분
    answer = True
    num = 0
    n2s=str(x)
    for i in n2s:
        num+=int(i)
    if x%num!=0:
        answer = False
    return answer