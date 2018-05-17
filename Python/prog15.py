def print_options():
       print('Options: ')
       print("'p' print options")
       print("'c' convert from Celsius")
       print("'f' convert from Fahrenheit")
       print("'q' quit")
def c_to_f(C):
       return 9.0/5.0*C+32
def f_to_c(F):
       return (F-32.0)*5.0/9.0
choice = 'p'
while choice != 'q':
 if choice == 'c':
    C = float(input('Celsius temperature: '))
    print('Fahrenheit: ', c_to_f(C))
    choice = input('Option: ')
 elif choice == 'f':
      F = float(input('Fahrenheit temperature: '))
      print('Celsius: ', f_to_c(F))
      choice = input('Option: ')
 elif choice == 'p':
      print_options()
      choice = input('Option: ')