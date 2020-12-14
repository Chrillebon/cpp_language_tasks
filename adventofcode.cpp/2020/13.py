data = "17,37,571,13,23,29,401,41,19"
easymode = "7,13,59,31,19"

starttime = 1000655

allbusses = data.split(",")

for i in range(len(allbusses)):
    num = int(allbusses[i])
    wait = num - (starttime % int(allbusses[i]))
    print("For ID: ", num, " skal der ventes ", wait, " der ganget sammen giver: ", num*wait)
