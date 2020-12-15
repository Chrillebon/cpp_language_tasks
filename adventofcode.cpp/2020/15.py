easymode1 = [0,3,6];
easymode2 = [1,3,2];
easymode3 = [2,1,3];
easymode7 = [3,1,2];
data = [0,1,5,10,3,12,19];

numbervisit = {}

mynums = data

for i in range(1,len(mynums)):      # springer lige sidste over...
    numbervisit[mynums[i-1]] = i

lastnum = mynums[len(mynums)-1]

maxit = 30000000        # for 15b er dette 30.000.000, for 15 er det 2020
for i in range(len(mynums), maxit):
    #print("ved spoken number ", i," bliver der sagt ", lastnum)
    if(lastnum in numbervisit):
        tmp = i - numbervisit[lastnum]
        numbervisit[lastnum] = i                # update timestamp
        lastnum = tmp                           # "speak" new number
    else:
        numbervisit[lastnum] = i                # insert into hashmap
        lastnum = 0

print("Efter, ",maxit," iterationer har vi tal: ", lastnum)
