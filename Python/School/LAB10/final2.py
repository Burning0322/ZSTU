def sumColumn(rows, columns):

    matrix = [[0]*4 for columns in range(rows)]

    for i in range(rows):
        numbers = input().split()  # Split the input into individual numbers
        for j in range(columns):
            matrix[i][j] = float(numbers[j])
    for i in range(rows):
        column_sum = 0
        for j in range(columns):
            column_sum += matrix[i][j]
        print(column_sum)

def main():
    row=int(input("Row:"))
    column=int(input("Column:"))
    sumColumn(row,column)

main()
