def square(a):
     return a*a
def rectangle(width,height):
     return width*height
def circle(radius):
     return 3.14*radius**2

def Options():
     print()
     print('Options:')
     print('s = calculate the area of a square')
     print('r = calculate the area of a rectangle')
     print('c = calculate the area of a circle')
     print('q = quit')
     print()

print('This program will calculate the area of a square, rectangle or circle.')

choice = 'x'
while choice != 'q':
       Options()
       choice = input('Please enter your choice: ')
       if choice == 's':
          a = float(input('Side: '))
          print('Area of the Square = ', square(a))
       elif choice == 'r':
            w = float(input('Width: '))
            h = float(input('Height: '))
            print('Area of the rectangle = ', rectangle(w,h))
       elif choice == 'c':
            r = float(input('Radius: '))
            print('Area of the circle = ', circle(r))
       elif choice == 'q':
            print(' ',end='')
       else: 
           print('Unrecognized option.')
          
