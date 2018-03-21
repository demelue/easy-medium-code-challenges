class RangeModule:
    def __init__(self):
        self.rangeList = []

    def AddRange(self, lower, upper):
        if len(self.rangeList) == 0:
            self.rangeList.append([lower, upper])
            return

        for i in range(0, len(self.rangeList)):
            if self.rangeList[i][0] <= lower <= self.rangeList[i][1]: #true: lower is covered
                if upper >= self.rangeList[i][1]: #true: we have to extend out coverage
                    self.rangeList[i][1] = upper
                    # print(self.rangeList)
                    return
            else:
                #ensure we are only adding at the end of our range list
                if upper > self.rangeList[i][1] and (i + 1) == len(self.rangeList):
                    self.rangeList.append([lower, upper])
                    # print(self.rangeList)

                #check middle then insert to keep order
                elif self.rangeList[i][1] < upper < self.rangeList[i+1][0]:
                    # print(i,lower,upper)
                    self.rangeList.insert(i + 1, [lower, upper])
                    return




    def QueryRange(self, lower, upper):
        i = 0
        while i < len(self.rangeList):
            if self.rangeList[i][0] <= lower <= self.rangeList[i][1]:
                if upper <= self.rangeList[i][1]:
                    return True
            i += 1
        return False

    def findAnOverlap(self, lower, upper): #helper function
        lowerIndex = -1
        upperIndex = -1
        i = 0
        while i < len(self.rangeList):
            if self.rangeList[i][0] <= lower <= self.rangeList[i][1]:
                lowerIndex = i
            if self.rangeList[i][0] <= upper <= self.rangeList[i][1]:
                upperIndex = i
            i += 1

        return lowerIndex, upperIndex

    def RemoveRange(self, lower, upper):
        if lower < self.rangeList[0][0] and upper > self.rangeList[len(self.rangeList)-1][1]:
            return
        #find first to see if there is anything to remove before attempting to remove
        lowerIndex, upperIndex  = self.findAnOverlap(lower, upper)
        if lowerIndex + upperIndex != -2:#true: there is an overlap
            if lowerIndex == upperIndex:#check if change is confined to one interval
                index = lowerIndex
                self.rangeList.insert(index + 1, [upper + 1, self.rangeList[index][1]])
                self.rangeList[index][1] = lower - 1
            elif lowerIndex + upperIndex == 1: #across 2 intervals
                index = lowerIndex
                self.rangeList[index + 1][0] = upper + 1
                self.rangeList[index][1] = lower - 1
            elif lowerIndex > upperIndex: #inbetween 2 intervals, so adjust only lower side
                self.rangeList[lowerIndex][1] = lower - 1
            elif lowerIndex < upperIndex:
                self.rangeList[upperIndex][0] = upper + 1
                self.rangeList.pop(upperIndex-1)
            print(self.rangeList)


    def printCurrentRange(self):
        print(self.rangeList)


if __name__ == '__main__':
    rangeTester = RangeModule()
    rangeTester.AddRange(10,200)
    rangeTester.AddRange(250,500)
    rangeTester.AddRange(550,600)
    # rangeTester.AddRange(67,190)
    # rangeTester.AddRange(300,315)
    # rangeTester.AddRange(302,400)
    # rangeTester.AddRange(196,220)
    # rangeTester.AddRange(191,195)
    # rangeTester.AddRange(221,299)
    # rangeTester.printCurrentRange()
    # rangeTester.RemoveRange(50,150)
    # rangeTester.RemoveRange(50,205)
    # rangeTester.RemoveRange(50,255)
    # rangeTester.RemoveRange(205,255)
    # print(rangeTester.QueryRange(23,134))
    rangeTester.RemoveRange(50,580)
