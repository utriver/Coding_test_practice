def solution(numbers, direction):
    if direction == "right":
        right = numbers.pop(len(numbers)-1)
        numbers.insert(0,right)
    else:
        left = numbers.pop(0)
        numbers.append(left)
    return numbers