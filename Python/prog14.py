a = 23
b = -23
def absolute_value(n):
        if n < 0:
          n = -n
        return n
if absolute_value(a) == absolute_value(b):
    print('absolute values of ',a,' and ',b,' are same')
else:
    print('absolute values of ',a,' and ',b,' are not same')