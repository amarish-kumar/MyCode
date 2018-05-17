menu_item = 9
list = []
print('This is a list making program by BlueZ.')
while menu_item != 5:
       print('-----------------------------------')
       print('1. Print the list')
       print('2. Add an item to the list')
       print('3. Remove an item from the list')
       print('4. Change an item in the list')
       print('5. Exit')
       print()
       menu_item = int(input('Choose an option: '))
       if menu_item == 1:
           current = 0
           if len(list) > 0:
               while current < len(list):
                      print(current,'.', list[current])
                      current = current + 1
           else:
                print('List is empty.')
       elif menu_item == 2:
             name = input('Type an item to add: ')
             list.append(name)
       elif menu_item == 3:
             del_name = input('Type an item to remove: ')
             if del_name in list:
                 list.remove(del_name)
             else:
                  print(del_name,'was not found!')
       elif menu_item == 4:
             old_name = input('Type an item to change: ')
             if old_name in list:
                 item_num = list.index(old_name)
                 new_name = input('Change it to: ')
                 list[item_num] = new_name
             else:
                  print(old_name,'was not found!')
print('Goodbye!')
                  