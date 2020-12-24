import copy
import collections

P1 = [41,33,20,32,7,45,2,12,14,29,49,37,6,11,39,46,47,38,23,22,28,10,36,35,24]
P2 = [17,4,44,9,27,18,30,42,21,26,16,48,8,15,34,50,19,43,25,1,13,31,3,5,40]

easyP1 = [9,2,6,3,1]
easyP2 = [5,8,4,7,10]

# koerten den paa skolens computer op til ca. 63 mia uden resultat, saa man skal
# altsaa taenke sig om/man kan loese den smart...
# Hvorfor mangler 44??

q1 = collections.deque()
q2 = collections.deque()

for i in range(len(P1)):
    q1.append(P1[i])
for i in range(len(P2)):
    q2.append(P2[i])


def printqueues():
    vals = []
    print("q1: ")
    for i in range(len(q1)):
        tmp = q1.popleft()
        print(tmp)
        q1.append(tmp)
        vals.append(tmp)
    print()
    print("q2: ")
    for i in range(len(q2)):
        tmp = q2.popleft()
        print(tmp)
        q2.append(tmp)
        vals.append(tmp)
    print()
    return vals

def round():
    v1 = q1.popleft()
    v2 = q2.popleft()
    if(v1 > v2):
        q1.append(v1)
        q1.append(v2)
    elif(v2 > v1):
        q2.append(v2)
        q2.append(v1)
    else:
        print("ERROR, same value...")

def equal_queue(thisq1, thisq2):
    if(len(thisq1) != len(thisq2)):
        return 0
    else:
        thissize = len(thisq1)
    returnval = 1
    tmpq = [-1 for i in range(2*thissize)]
    for i in range(thissize):
        tmpq[2*i] = thisq1.popleft()
        tmpq[2*i + 1] = thisq2.popleft()
        if(tmpq[2*i] != tmpq[2*i + 1]):
            returnval = 0
    for i in range(thissize):
        thisq1.append(tmpq[2*i])
        thisq2.append(tmpq[2*i + 1])
    return returnval

iteration = 0

def game(queue1, queue2):
    global iteration
    # 1 for player 1 win, 2 for player 2 win
    all_previous1 = []
    all_previous2 = []
    while(len(queue1) != 0 and len(queue2) != 0):
        if(len(queue1)+len(queue2) == 50):
            print(iteration)
            iteration += 1
        # stopping infinite loops...
        for i in range(len(all_previous1)):
            if(equal_queue(all_previous1[i], queue1)):
                return 1
        all_previous1.append(copy.deepcopy(queue1))
        for i in range(len(all_previous2)):
            if(equal_queue(all_previous2[i], queue2)):
                return 1
        all_previous2.append(copy.deepcopy(queue2))
        # saa gaar vi i gang...
        v1 = queue1.popleft()
        v2 = queue2.popleft()
        if(len(queue1) >= v1 and len(queue2) >= v2):
            # rekursion foelger
            c1 = copy.deepcopy(queue1)
            c2 = copy.deepcopy(queue2)
            while(len(c1) != v1):
                c1.pop()
            while(len(c2) != v2):
                c2.pop()
            if(game(c1, c2) == 1):
                queue1.append(v1)
                queue1.append(v2)
            else:
                queue2.append(v2)
                queue2.append(v1)
        else:
            # almindeligt spil...
            if(v1 > v2):
                queue1.append(v1)
                queue1.append(v2)
            else:
                queue2.append(v2)
                queue2.append(v1)
    if(len(queue1) == 0):
        return 2
    else:
        return 1


print("Spillet: ", game(q1,q2), " som nu har elementerne: ")
finalvals = printqueues()

res = 0
for i in range(len(finalvals)):
    res += (len(finalvals)-i)*finalvals[i]

print("som giver: ", res)
