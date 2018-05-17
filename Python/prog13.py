print('This program calculates average.')
print('Enter 0 to show the average.')
count = 0
sum = 0.0
number = 1
while number != 0:
 number = float(input('Enter a number: '))
 if number != 0:
  count = count + 1
  sum = sum + number
 if number == 0:
  print('Average was: ',sum / count)