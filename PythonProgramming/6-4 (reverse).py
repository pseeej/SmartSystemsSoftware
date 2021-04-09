customer = ['Jane', 'Mark', 'Tom', 'Amy', "Bob"]


# without using reversed function

def reverseList(list):
    res = []
    for i in range(1, len(list)+1):
        res.append(list[-i])
    return res

print(reverseList(customer))


# using reversed function
'''
def reverseList(list):
    list.reverse()
    return list

print(reverseList(customer))
'''
