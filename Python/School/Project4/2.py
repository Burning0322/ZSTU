TempStr = input("请输入带有符号的温度值：")

if TempStr[0] in ['F', 'f']:
    c = (eval(TempStr[1:]) - 32) / 1.8
    print("转换后的温度是{:.2f}C".format(c))
elif TempStr[0] in ['C', 'c']:
    f = 1.8 * eval(TempStr[1:]) + 32
    print("转换后的温度是{:.2f}F".format(f))
else:
    print("输入格式错误")
