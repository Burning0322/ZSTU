def count(s):
    
    for i in range(0,len(s),1):
        s1=[0]*10
        s2=[]
        s1[i]=s2.count[i]
        if s2[i]<=1:
            print(s2[i],'occurs',s1[i],'time')
        else:
            print(s2[i],'occurs',s1[i],'times')
    return s2
def main():
    a=str(input('Enter a string:'))
    a1=a.split()
    s3=[eval(x) for x in a1]
    print(count(s3))
main()
    
    
