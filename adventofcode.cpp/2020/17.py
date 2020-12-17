import copy

data = "AAAAA...;.A..AA..;AA.AA.AA;...AAAA.;A.A...AA;.AA...A.;.A.A.AAA;A.A.A..A"
easymode = ".A.;..A;AAA"

mypocket = data.split(";")
for i in range(len(mypocket)):
    mypocket[i] = list(mypocket[i])

startwidth = 8
startheight = 8

# [z][y][x]
pocketdim = [[["." for i in range(startwidth+2*6)] for o in range(startheight+2*6)] for u in range(13)]

for i in range(startheight):
    for o in range(startwidth):
        pocketdim[6][6+i][6+o] = mypocket[i][o]

def update_single(x,y,z):
    global pocketdim
    active_close = 0
    for i in range(max(0,z-1),min(13,z+2)):
        for o in range(max(0,y-1),min(12+startheight, y+2)):
            for u in range(max(0,x-1),min(12+startwidth, x+2)):
                if(pocketdim[i][o][u] == "A" and (i != z or o != y or u != x)):
                    active_close += 1
    if(pocketdim[z][y][x] == "A" and (active_close == 2 or active_close == 3)):
        #print("Keeping active location: ",x-6-1, ", ",y-6-1,", in layer ", z-6)
        return 1
    elif(pocketdim[z][y][x] == "A"):
        #print("Deactivating location: ",x-6-1, ", ",y-6-1,", in layer ", z-6)
        return 0
    elif(pocketdim[z][y][x] == "." and active_close == 3):
        #print("Activating! location: ",x-6-1, ", ",y-6-1,", in layer ", z-6)
        #print(active_close)
        return 1
    else:
        return 0

def sim_cycle():
    global pocketdim
    tmpdim = copy.deepcopy(pocketdim)
    for i in range(0,13):
        for o in range(0,12+startheight):
            for u in range(0,12+startwidth):
                #tmpdim[i][o][u] = update_single(u,o,i)
                if(update_single(u,o,i)):
                    tmpdim[i][o][u] = "A"
                else:
                    tmpdim[i][o][u] = "."
    pocketdim = copy.deepcopy(tmpdim)


def count_done():
    global pocketdim
    res = 0
    for i in range(0,13):
        for o in range(0,12+startheight):
            for u in range(0,12+startwidth):
                if(pocketdim[i][o][u] == "A"):
                    res += 1
    return res


for i in range(6):
    sim_cycle()
print("When done: ", count_done())

# 130 too low
