class Airline:
    def setSrc(self, __src):
        self.__src = __src

    def getSrc(self):
        return self.__src

    def setDst(self, __dst):
        self.__dst = __dst

    def getDst(self):
        return self.__dst

fdata = open("Indigo.txt")
airlines = list()
tempAirlines = list()
directAirlines = list()

for line in fdata.readlines():
    src, dst = line.strip().split(',')
    al = Airline()
    al.setSrc(src)
    al.setDst(dst)
    airlines.append(al)

src = input('Enter source: ').upper()
dst = input('Enter destination: ').upper()

for a in airlines:
    # print(a.getSrc(), a.getDst())
    if a.getSrc() == src and a.getDst() == dst:
        directAirlines.append(a)
    else:
        tempAirlines.append(a)

for k in directAirlines:
    print(k.getSrc(), k.getDst())

for a in tempAirlines:
    if a.getSrc() == src:
        for b in tempAirlines:
            if b.getSrc() == a.getDst() and b.getDst() == dst:
                print(a.getSrc(), a.getDst(), b.getDst())
