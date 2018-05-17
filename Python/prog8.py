name = input('Set username: ')
password = input('Set password: ')
print()
print('To lock your computer type lock.')
print()
command = None
input1 = None
input2 = None
while command != 'lock':
 command = input('What is your command: ')
 print()
while (input1 != name) or (input2 != password):
 print('Enter correct Username or Password.')
 print()
 input1 = input('Username: ')
 input2 = input('Password: ')
 print()
print('Welcome back to your system!') 