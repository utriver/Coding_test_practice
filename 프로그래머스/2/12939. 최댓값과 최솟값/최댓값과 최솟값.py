def solution(s):
    answer =''
    new_list=s.split(' ')
    new_list = [int(i) for i in new_list]
    new_list.sort()
    answer = str(new_list[0])+' '+str(new_list[-1])
    return answer