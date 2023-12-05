def sortRows(m):
    # 定义函数sortRows，接受一个二维矩阵m作为参数，返回每行元素升序排序后的新矩阵。
    sorted_matrix = [sorted(row) for row in m]
    return sorted_matrix  # 返回排序后的矩阵

def displayMatrix(matrix):
    # 定义函数displayMatrix，接受一个矩阵matrix作为参数，逐行打印矩阵的元素。
    for row in matrix:
        print(row)

# 测试程序
def main():
    # 提示用户输入行数和列数
    rows = int(input("Enter the number of rows: "))  # 用户输入行数
    cols = int(input("Enter the number of columns: "))  # 用户输入列数

    # 提示用户输入矩阵元素
    matrix = []
    for _ in range(rows):
        row = []
        numbers = input("Enter row values separated by space: ").split()
        for number in numbers:
            row.append(float(number))
        matrix.append(row)

    # 显示原始矩阵
    print("\nOriginal Matrix:")
    displayMatrix(matrix)

    # 对行进行排序并显示排序后的矩阵
    sorted_matrix = sortRows(matrix)
    print("\nSorted Matrix:")
    displayMatrix(sorted_matrix)

if __name__ == "__main__":
    main()
# 如果脚本作为主模块运行，则调用main函数
