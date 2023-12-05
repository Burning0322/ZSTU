def selectionSort(lst):
    for i in range(0,len(lst)-1):
        currentMin=lst[i]
        currentMinIndex=i
        for j in range(i+1,len(lst)):
            if currentMin>lst[j]:
                currentMin=lst[j]
                currentMinIndex=j
        if currentMinIndex!=i:
            lst[currentMinIndex]=lst[i]
            lst[i]=currentMin
    return lst
def main():
    a=str(input('Enter numbers:'))
    a1=a.split()
    s=[eval(x) for x in a1]
    print(selectionSort(s))
main()
