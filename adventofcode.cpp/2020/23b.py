easymode = [3,8,9,1,2,5,4,6,7]
data = [2,1,5,6,9,4,7,8,3]
next = [-1] + [i+2 for i in range(1000001)]
prev = [-1] + [i for i in range(1000001)]


startval = data[0]
for i in range(1,8):
    next[data[i]] = data[i+1]
    prev[data[i]] = data[i-1]
next[data[0]] = data[1]
prev[data[0]] = 1000000
next[data[8]] = 10
prev[data[8]] = data[7]
prev[10] = data[8]
next[1000000] = data[0]

def move():
    global next, prev, startval
    currentcup = startval
    # picking up cups
    # ourcup, first_to_pick_up, ..., last_to_pick_up, first_after_pick_up
    pickup = [startval,-1,-1,-1,-1]
    for i in range(1,5):
        pickup[i] = next[pickup[i-1]]

    next[pickup[0]] = pickup[4]
    prev[pickup[4]] = pickup[0]

    nextcup = currentcup - 1
    # finding value of next cup
    while(nextcup < 1 or nextcup in pickup[1:4]):
        nextcup = (nextcup - 1) % (1000000+1)

    # place between placedown[0] and placedown[1]
    placedown = [nextcup, next[nextcup]]
    # inserting
    next[placedown[0]] = pickup[1]
    prev[pickup[1]] = placedown[0]
    next[pickup[3]] = placedown[1]
    prev[placedown[1]] = pickup[3]

    startval = next[startval]

def printlist():
    val = 1
    print("printing from 1: ")
    for i in range(10):
        print(val, end = ', ')
        val = next[val]
    print()

def find_res():
    global next
    return next[1]*next[next[1]]

for i in range(10000000):
    move()
    if(i % 100000 == 0):
        print(i/100000, " % done!")

print("When done: ", find_res())
