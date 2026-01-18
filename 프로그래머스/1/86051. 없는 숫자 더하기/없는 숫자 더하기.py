def solution(numbers):
    z2n={0,1,2,3,4,5,6,7,8,9}
    answer_lst = z2n-set(numbers)
    answer = sum(list(answer_lst))
    return answer