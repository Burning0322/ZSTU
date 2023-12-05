import random

# 1. Declare a 4x4 matrix
array = [[0] * 4 for _ in range(4)]

# 2. Use nested loops to assign random values (0 or 1) to the matrix and print it
for i in range(4):
    for j in range(4):
        array[i][j] = random.randint(0, 1)
        print(array[i][j], end='')
    print()

# 3. Initialize variables to store the row and column with the most 1s
largest_row = 0
count_row = 0
temp_row = 0

# 4. Find the row with the most 1s
for i in range(4):
    temp_row = sum(array[i])
    if count_row < temp_row:
        count_row = temp_row
        largest_row = i

# 5. Find the column with the most 1s
largest_col = 0
count_col = 0
temp_col = 0

for j in range(4):
    temp_col = sum(array[i][j] for i in range(4))
    if count_col < temp_col:
        count_col = temp_col
        largest_col = j

# 6. Output the row and column indices with the most 1s
print("The largest row index:", largest_row)
print("The largest column index:", largest_col)
