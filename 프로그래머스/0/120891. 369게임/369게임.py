def solution(order):
    str2num = str(order)
    answer =  str2num.count("3")+str2num.count("6")+str2num.count("9")

    return answer