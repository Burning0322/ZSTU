def sumColumn(m, columnIndex):
    matrix=[]
    for i in range(m):
        row=[]
        number=input("请输入数据").split()
        for j in range(columnIndex):
            row.append(float(number[j]))
        matrix.append(row)

    for j in range(columnIndex):
        total = 0
        for i in range(m):
            total+=matrix[i][j]
        print(total)

def main():
    sumColumn(3,4)

main()