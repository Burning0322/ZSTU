def sumMajorDiagonal():
    matrix=[]
    for i in range(4):
        row = []
        numbers = input().split()
        for number in numbers:
            if number:
                row.append(float(number))
        matrix.append(row)
    total=0
    for row in range(len(matrix)):
        for column in range(len(matrix)):
            total+=matrix[column][row]
    print(total)

sumMajorDiagonal()