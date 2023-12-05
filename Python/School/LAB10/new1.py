matrix = []

def sumColumn(m, columnIndex):
    for i in range(m):
        r = input(f"Enter a {m}-by-{columnIndex} matrix row {i}: ").split()
        # Convert input values to float and append to the row
        row=[]
        for val in r:
            row.append(float(val))
        matrix.append(row)

    for j in range(columnIndex):
        total = 0
        for i in range(m):
            total += matrix[i][j]
        print(f"Sum of the elements at column {j} is {total}")

def main():
    sumColumn(3, 4)

if __name__ == "__main__":
    main()
