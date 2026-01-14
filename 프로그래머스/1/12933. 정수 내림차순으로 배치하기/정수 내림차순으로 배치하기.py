def solution(n):
    answer = [int(i) for i in str(n)]
    answer.sort(reverse = 1)
    answer_st = ""
    for i in answer:
        answer_st+=str(i)
    answer = int(answer_st)
    return answer