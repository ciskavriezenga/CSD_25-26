

# when passing a immutable like a number to a function
# An adaptation of that variable inside the function
# results in a new object.
# The original variable still references the 'old' object
# which is not adapted.
a = 10
def addFive(x):
    print("X at the start is:", x)
    x += 5
    print("X is now:", x)
    return x

print("a:", a)
addFive(a)
print("a:", a)


# when passing a list (a mutable type) to a function,
# inside the function the list object is referenced,
# an adaptation of the list does result (!) in an
# adaptation of the value in the list
b = [10]
def addFiveToFirstItem(numbers):
    print("First item at the start is: ", numbers[0])
    numbers[0] += 5
    print("Added five to the first item, it is now:", numbers[0])

print("b:", b)
addFiveToFirstItem(b)
print("b:", b)

# in case of the for loop below, item is a copy of the
# value in the list
# the value in the list is thus not adapted
for item in b:
    item += 5
    print("item:", item)

print("b:", b)

# if we do want to alter the value in a list
# within a forloop, the following forloop can
# be used
for index in range(len(b)):
    b[index] += 5

print("We altered b in a forloop, b:", b)
