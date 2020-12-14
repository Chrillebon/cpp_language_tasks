allbusses = [17,37,571,13,23,29,401,41,19]
#pos = [1,12,18,36,41,47,49,59,68]
#actualpos = [1,12,18,10,18,18,49,18,11]
zeroindexpos = [17,11,17,9,17,17,48,17,10]      # kan ikke ramme 0, skal i stedet ramme 17
alllcm = 972831826422131;
somelcm = [57225401554243,26292752065463,1703733496361,74833217417087,42297035931397,33545925049039,2426014529731,23727605522491,51201675074849]
# ^^ er LCM af alle tal PÅNÆR den plads som den står på (fundet med maple!)
# benyttes til at incremente t, uden at påvirke kørselstidspunkter
# for alle pånær 1 ad gangen!

t = 0

# tager 1 ad gangen
for i in range(len(allbusses)):
    # indtil de matcher deres rigtige index!
    while((allbusses[i] - (t % allbusses[i])) != zeroindexpos[i]):
        t += somelcm[i];

    # print("done med ", allbusses[i], " ved t = ", t)


print("Virker???: ", t)
# 4118172538898811 var too high, skal altså reducerer med alles lcm

# finder den mindste, så reducerer alle med alles lcm til vi finder den mindste!
o = 0
while(t-o*alllcm >= 0):
    o += 1

o -= 1
print("Mindste er: ", t-o*alllcm)
# mindste ikke-negative:   226845233210287 (too low...)



# mere matematik end programmering...
# (17-(t%17)) = 1
# (37-(t%37)) = 12
# (571-(t%571)) = 18
# (13-(t%13)) = 36
# (23-(t%23)) = 41
# (29-(t%29)) = 47
# (401-(t%401)) = 49
# (41-(t%41)) = 59
# (19-(t%19)) = 68

# runder lige ned, så det passer:
# print(68 % 19)

# (17-(t%17)) = 1
# (37-(t%37)) = 12
# (571-(t%571)) = 18
# (13-(t%13)) = 10
# (23-(t%23)) = 18
# (29-(t%29)) = 18
# (401-(t%401)) = 49
# (41-(t%41)) = 18
# (19-(t%19)) = 11


# t%17 = 16
# t%37 = 25
# t%571 = 553
# t%13 = 3
# t%23 = 5
# t%29 = 11
# t%401 = 352
# t%41 = 23
# t%19 = 8


# sker ved:

# t = 16 + 17*x1
# t = 37-12 + 37*x2
# t = 571-18 + 571*x3
# t = 13-10 + 13*x4
# t = 23-18 + 23*x5
# t = 29-18 + 29*x6
# t = 401-49 + 401*x7
# t = 41-18 + 41*x8
# t = 19-11 + 19*x9

# ligner lineær algebra...
# A := Matrix(9, 10, [[17, 0, 0, 0, 0, 0, 0, 0, 0, t - 1], [0, 37, 0, 0, 0, 0, 0, 0, 0, t - 12], [0, 0, 571, 0, 0, 0, 0, 0, 0, t - 18], [0, 0, 0, 13, 0, 0, 0, 0, 0, t - 10], [0, 0, 0, 0, 23, 0, 0, 0, 0, t - 18], [0, 0, 0, 0, 0, 29, 0, 0, 0, t - 18], [0, 0, 0, 0, 0, 0, 401, 0, 0, t - 49], [0, 0, 0, 0, 0, 0, 0, 41, 0, t - 18], [0, 0, 0, 0, 0, 0, 0, 0, 19, t - 11]])

# Skal nu finde least common multiple af alle faktorerne, som t deles med efter reducedrowechelonform:
# ilcm(17, 37, 571, 13, 23, 29, 401, 41, 19);                =>                        972831826422131
# var too high...
