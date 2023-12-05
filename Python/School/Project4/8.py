import turtle

# 创建一个 turtle 对象
t = turtle.Turtle()

# 设置画笔颜色为红色
t.color("red")

# 开始填充颜色
t.begin_fill()

# 画五角星
for _ in range(5):
    t.forward(100)  # 边长为100
    t.right(144)    # 角度为 180 - 36 = 144 度

# 结束填充颜色
t.end_fill()

# 隐藏 turtle 笔触
turtle.hideturtle()

# 显示绘图窗口
turtle.done()
