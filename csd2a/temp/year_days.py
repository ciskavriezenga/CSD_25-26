with open("output.txt", "a") as f:
    numbers = ""

    for i in range(365):
        numbers += str(i + 1)
    print(numbers, file=f)
