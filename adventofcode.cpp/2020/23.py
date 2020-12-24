easymode = [3,8,9,1,2,5,4,6,7]
data = [2,1,5,6,9,4,7,8,3]

target = data
startindex = 0

def rotate(L):
    tmp = L[0]
    L.pop(0)
    L.append(tmp)


def move():
    global target
    currentcup = target[0]
    # picking up cups
    pick_up = target[1:4]
    for i in range(3):
        target.pop(1)
    nextcup = currentcup - 1
    # finding value of next cup
    while(nextcup < 1 or not(nextcup in target)):
        nextcup = (nextcup - 1) % 10
    # finding index of nextcup:
    newindex = target.index(nextcup)
    # inserting the picked up:
    for i in range(3):
        target.insert(newindex + i + 1, pick_up[i])
    rotate(target)

def find_res():
    global target
    startindex = target.index(1)
    res = target[startindex+1:] + target[0:startindex]
    return "".join(map(str, res))


for i in range(100):
    move()
    #print("after: ",i," we have: ", target)

print()
print("res: ", find_res())
