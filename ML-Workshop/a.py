import sys
for line in sys.stdin:
    eid, ename, age, gender, sal = line.strip().split(",")
    ename = ename.upper()
    str = " ".join([eid, ename, age, gender, sal])
    print(str)
