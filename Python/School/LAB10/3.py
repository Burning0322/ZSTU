import random

def print_matrix():
    global matrix
    matrix = [[0]*4 for row in range(4)] 
    for row in range(4):
        for column in range(4):
            matrix[row][column]=random.randint(0,1)

    for row in matrix:
        for column in row:
            print(column,end=' ')
        print()

def max():
    # 3. Initialize variables to store the row and column with the most 1s
    largest_row = 0
    count_row = 0
    temp_row = 0

    # 4. Find the row with the most 1s
    for i in range(4):
        temp_row = sum(matrix[i])
        if count_row < temp_row:
            count_row = temp_row
            largest_row = i

    # 5. Find the column with the most 1s
    largest_col = 0
    count_col = 0
    temp_col = 0

    for j in range(4):
        temp_col = sum(matrix[i][j] for i in range(4))
        if count_col < temp_col:
            count_col = temp_col
            largest_col = j

    # 6. Output the row and column indices with the most 1s
    print("The largest row index:", count_row)
    print("The largest column index:", count_col)

    

def main():
    print_matrix()
    max()

main()