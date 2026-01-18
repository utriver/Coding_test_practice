def solution(s):
    #key-value -> s발견하면 svlaue에 +=1, P발견하면  P_vlaue에 +=1, s나 p가 아니면 other key
    ky = {"y":0, "p":0}
    #반복문 돌리면서 값 확인 -> value접근
    for i in s:
        if i=="y" or i=="Y":
            ky["y"]+=1
        elif i == "p" or i == "P":
            ky["p"]+=1
            
    if ky.get("y")==0 and ky.get("p")==0:
        return True
        
    elif ky.get("y") == ky.get("p"):
        return True
    elif ky.get("y") != ky.get("p"):
        return False
    


