import turtle

# 创建一个 turtle 对象
t = turtle.Turtle()

# 设置画笔颜色为蓝色
t.color("blue")

# 开始填充颜色
t.begin_fill()

# 画正方形
for _ in range(4):
    t.forward(100)  # 边长为100
    t.left(90)  # 旋转90度

# 结束填充颜色
t.end_fill()

# 隐藏 turtle 笔触
turtle.hideturtle()

# 显示绘图窗口
turtle.done()
