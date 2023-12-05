import random

#定义输出matrix
def matrix_print():  
    #定义全局变量
    global matrix  
    #初始化matrix
    matrix = [[0] * 4 for row in range(4)]  
    #创建行
    for row in range(4): 
        #创建列
        for column in range(4):  
            #替换0或1在每一行和每一列
            matrix[row][column] = random.randint(0, 1)  
    #输出matrix
    for row in matrix:  
        for column in row:  
            print(column, end=' ')  
        print()

#找相同的行
def same_row(): 
    #遍历每一行
    #一开始i=0,row_values=matrix[0]
    for i in range(len(matrix)):  
        #当前那一行,i=0就是第一行
        row_values = matrix[i]  
        is_same = True 
        
        # 遍历当前行的每个元素，从第二个元素开始比较
        for j in range(1,len(row_values)):  
            #检查是不是相同的
            if row_values[j] != row_values[0]:  
                # 如果不相同，将is_same设置为False并跳出内层循环，就会到第二行去
                is_same = False  
                break  
        #同一行就输出
        if is_same:  
            print(f"Row {i + 1} has the same number: {row_values[0]}")  
    else:  
        print("No same numbers on a row")  

def same_column():  
    #每一行
    for j in range(len(matrix[0])):  
        #和row的i和j一样是倒反的,就刚才说的
        """ 横的是j，竖的是i
            0 1 2 3
        0
        1
        2
        3
        """
        #获取当前列的值，并存储在变量中
        column_values = [matrix[i][j] for i in range(len(matrix))]  
        is_same = True  
        #下面也是一样的
        for i in range(1,len(column_values)):  
            if column_values[i] != column_values[0]:  
                is_same = False  
                break  
        if is_same:  
            print(f"Column {j + 1} has the same number: {column_values[0]}")  
    else:  
        print("No same numbers on a column") 

def major_diagonal():  
    #这个对角线就是
    """
        0 1 2 3
    0   a
    1     a
    2       a
    3          a
    """
    #用ii是因为是他的矩阵的主对角线上，主对角线是从矩阵的左上角到右下角的对角线
    #如果用ij的话有可能你的i和j不是完整的好像这样
    """
        0 1 2
    0   a
    1     a
    2       a
    3   1 2 4     
    """
    #看得懂吗看不懂再微信我，我和你解释哈哈哈
    diagonal_values = [matrix[i][i] for i in range(len(matrix))]  
    is_same = True  
    #这里也是判断是不是那个数字
    for i in range(1,len(diagonal_values)):  
        if diagonal_values[i] != diagonal_values[0]:  
            is_same = False  
            break  
    if is_same:  
        print(f"Major Diagonal has the same number: {diagonal_values[0]}")  
    else:  
        print("No same numbers on the major diagonal")  

def sub_diagonal():  
    #这个比较绕
    """
        0 1 2 3
    0         a
    1       a
    2     a
    3   a
    """
    #你的那个第一行的话就
    #加入你的len(matrix)是4
    #matrix[i=0][i=4-当前的i然后-1]
    sub_diagonal_values = [matrix[i][len(matrix) - i - 1] for i in range(len(matrix))]  
    is_same = True  
    #和上面一样的
    for i in range(1,len(sub_diagonal_values)):  
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