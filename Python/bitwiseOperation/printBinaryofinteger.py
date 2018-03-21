#Python string to binary

inData = '7'

if (len(inData.split('.')) > 1):
    print('Error')
else:
    output = bin(int(inData))
    print(output[2:])
