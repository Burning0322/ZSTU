import turtle

# 创建一个Turtle对象
t = turtle.Turtle()

# 设置画笔颜色为红色
t.color("red")

# 开始填充颜色
t.begin_fill()

# 绘制正三角形
for _ in range(3):
    t.forward(100)  # 边长为100
    t.left(120)  # 120度角

# 结束填充颜色
t.end_fill()

# 隐藏画笔
t.hideturtle()

# 显示窗口
turtle.mainloop()
