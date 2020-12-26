data = [8184785, 5293040]
easymode = [5764801, 17807724]

# [cards public key, doors public key]

def loop_it(num, sub):
    num *= sub
    num = num % 20201227
    return num

cardval = 1
doorval = 1

icard = 0
idoor = 0
while(cardval != data[0]):
    cardval = loop_it(cardval,7)
    icard += 1

while(doorval != data[1]):
    doorval = loop_it(doorval,7)
    idoor += 1

print("testing: ", icard, " and ", idoor)

cardres = 1
doorres = 1

for i in range(icard):
    doorres = loop_it(doorres,data[1])

for i in range(idoor):
    cardres = loop_it(cardres,data[0])

print("When done: ", cardres, " and ",doorres)
