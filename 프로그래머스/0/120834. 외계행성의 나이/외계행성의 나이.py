def solution(age):
    alist = list(map(chr,range(97,123)))
    answer = ''
    age2str = str(age)
    for i in age2str:
        answer+=alist[int(i)]
    return answer