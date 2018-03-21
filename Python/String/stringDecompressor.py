import sys

if (len(sys.argv) == 0):
    print ("No inputs")
    sys.exit()

inData = str(sys.argv[1])
out = ""

for i in range(0, len(inData)):
    if (inData[i] > 'a' and inData[i] < 'z' or inData[i] == '#' or inData[i] == '\n'):
        if (inData[i] == '#'):
            if (inData[i-1] != '#'):
                lastchar = inData[i-1]
            out += lastchar
        else:
            out += inData[i]
    else:
        print('INVALID')
        sys.exit()
print (out)
