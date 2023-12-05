TempStr = input("请输入带有符号的温度值：")  
  
# 检查输入的字符是否为 'F' 或 'f'，如果是，则将其转换为摄氏度  
if TempStr[-1].upper() in ['F', 'F']:  
    temp_value = float(TempStr[:-1])  
    c = (temp_value - 32) / 1.8  
    print("转换后的温度是{:.2f}C".format(c))  
# 如果输入的字符是 'C' 或 'c'，则将其转换为华氏度  
elif TempStr[-1].upper() in ['C', 'c']:  
    temp_value = float(TempStr[:-1])  
    f = 1.8 * temp_value + 32  
    print("转换后的温度是{:.2f}F".format(f))  
# 如果输入的字符既不是 'F' 或 'f'，也不是 'C' 或 'c'，则输出输入格式错误  
else:  
    print("输入格式错误")
