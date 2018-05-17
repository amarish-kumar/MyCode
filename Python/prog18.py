print('This program states the names of the months.')
print('Press 0 to quit.')
number = 'x'
while number != 0:
 number = int(input('What month (1-12)? '))
 months = ['January','February','March','April','May','June','July','August','September','October','November','December']

 if 1 <= number <= 12:
     print('The month is ', months[number-1]) 
 elif number == '0':
       exit