import random  
  
def matrix_print():  
    global matrix  
    matrix = [[0] * 4 for row in range(4)]  
  
    for row in range(4):  
        for column in range(4):  
            matrix[row][column] = random.randint(0, 1)  
  
    for row in matrix:  
        for column in row:  
            print(column, end=' ')  
        print()  
  
def same_row():  
    for i in range(len(matrix)):  
        row_values = matrix[i]  
        is_same = True  
        for j in range(1, len(row_values)):  
            if row_values[j] != row_values[0]:  
                is_same = False  
                break  
        if is_same:  
            print(f"Row {i + 1} has the same number: {row_values[0]}")  
    else:  
        print("No same numbers on a row")  
  
def same_column():  
    for j in range(len(matrix[0])):  
        column_values = [matrix[i][j] for i in range(len(matrix))]  
        is_same = True  
        for i in range(1, len(column_values)):  
            if column_values[i] != column_values[0]:  
                is_same = False  
                break  
        if is_same:  
            print(f"Column {j + 1} has the same number: {column_values[0]}")  
    else:  
        print("No same numbers on a column")  
  
def major_diagonal():  
    diagonal_values = [matrix[i][i] for i in range(len(matrix))]  
    is_same = True  
    for i in range(1, len(diagonal_values)):  
        if diagonal_values[i] != diagonal_values[0]:  
            is_same = False  
            break  
    if is_same:  
        print(f"Major Diagonal has the same number: {diagonal_values[0]}")  
    else:  
        print("No same numbers on the major diagonal")  
  
def sub_diagonal():  
    sub_diagonal_values = [matrix[i][len(matrix) - i - 1] for i in range(len(matrix))]  
    is_same = True  
    for i in range(1, len(sub_diagonal_values)):  
        if sub_diagonal_values[i] != sub_diagonal_values[0]:  
            is_same = False  
            break  
    if is_same:  
        print(f"Subdiagonal has the same number: {sub_diagonal_values[0]}")  
    else:  
        print("No same numbers on the sub-diagonal")  
  
def main():  
    matrix_print()  
    same_row()  
    same_column()  
    major_diagonal()  
    sub_diagonal()
    
main()