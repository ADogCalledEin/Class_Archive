

#used interput cuz input is reserved
interput = [57, 24, 4, 0, 49, 23, 2, 57, 50, 18]
output = []

for i in range(0, len(interput)):
    new = interput[i] % 19 # Change this number to change M
    output.append(new)

print "Key : Index"

for i in range(0, len(output)):
    print "%d : %d" %(interput[i], output[i])
