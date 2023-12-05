def sumColumn(m, columnIndex):
    # Sum the elements in the specified column
    column_sum = sum(row[columnIndex] for row in m)
    return column_sum

# Get the dimensions of the matrix from the user
rows = int(input("Enter the number of rows: "))
columns = int(input("Enter the number of columns: "))

# Initialize an empty matrix
matrix = []

# Get the matrix elements from the user
for i in range(rows):
    row = []
    for j in range(columns):
        element = int(input(f"Enter the element at position ({i+1}, {j+1}): "))
        row.append(element)
    matrix.append(row)

# Get the column index from the user
column_index = int(input("Enter the column index: "))

# Calculate and print the sum of the specified column
result = sumColumn(matrix, column_index)
print(f"The sum of elements in column {column_index} is: {result}")
