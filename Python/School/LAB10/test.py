def sumColumn(m, columnIndex):
    for i in range(m):
        row = []
        for j in range(columnIndex):
            value = int(input(f"Enter the element at position ({i+1}, {j+1}): "))
            row.append(value)
        matrix.append(row)
    print(matrix)

def main():
    sumColumn(3,4)

main()