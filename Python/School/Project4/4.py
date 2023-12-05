# 导入turtle模块
import turtle

# 设置窗口大小和起始位置（宽度，高度，起始x，起始y）
turtle.setup(650, 350, 200, 200)

# 抬起画笔（不绘制）
turtle.penup()

# 移动画笔到起始位置
turtle.fd(-250)

# 放下画笔（开始绘制）
turtle.pendown()

# 设置画笔大小为25像素
turtle.pensize(25)

# 设置画笔颜色为紫色
turtle.pencolor("purple")

# 设置画笔方向为-40度
turtle.seth(-40)

# 开始画蟒蛇的身体
for i in range(4):
    # 画圆弧，参数为（半径，角度）
    turtle.circle(40, 80)

    # 画反向的圆弧，参数为（半径，角度）
    turtle.circle(-40, 80)

# 画半径为40，角度为40度的圆弧
turtle.circle(40, 80/2)

# 向前移动40像素
turtle.fd(40)

# 画半径为16，角度为180度的圆弧
turtle.circle(16, 180)

# 向前移动40 * 2/3 像素
turtle.fd(40 * 2/3)

# 完成绘制
turtle.done()
