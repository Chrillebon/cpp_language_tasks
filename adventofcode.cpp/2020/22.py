import copy
import queue

P1 = [41,33,20,32,7,45,2,12,14,29,49,37,6,11,39,46,47,38,23,22,28,10,36,35,24]
P2 = [17,4,44,9,27,18,30,42,21,26,16,48,8,15,34,50,19,43,25,1,13,31,3,5,40]

easyP1 = [9,2,6,3,1]
easyP2 = [5,8,4,7,10]

# kørten den på skolens computer op til ca. 63 mia uden resultat, så man skal
# altså tænke sig om/man kan løse den smart...
# Hvorfor mangler 44??

q1 = queue.Queue()
q2 = queue.Queue()

def round():
    v1 = q1.get()
    v2 = q2.get()
    if(v1 > v2):
        q1.put(v1)
        q1.put(v2)
    elif(v2 > v1):
        q2.put(v2)
        q2.put(v1)
    else:
        print("ERROR, same value...")

for i in range(len(P1)):
    q1.put(P1[i])
for i in range(len(P2)):
    q2.put(P2[i])


def printqueues():
    vals = []
    print("q1: ")
    while(not(q1.empty())):
        tmp = q1.get()
        vals.append(tmp)
        print(tmp, end = ', ')
    print()
    print("q2: ")
    while(not(q2.empty())):
        tmp = q2.get()
        vals.append(tmp)
        print(tmp, end = ', ')
    print()
    return vals

iterationnum = 0
while(not(q1.empty() or q2.empty())):
    round()


print("When done:")
finalvals = printqueues()

res = 0
for i in range(len(finalvals)):
    res += (len(finalvals)-i)*finalvals[i]

print("som giver: ", res)
