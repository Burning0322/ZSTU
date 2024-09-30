# This is a sample Python script.
# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.
import cv2
import matplotlib.pyplot as plt


def image():
    image_path = '/Users/renhonglow/PycharmProjects/First/image.jpg'
    img = cv2.imread(image_path)

    # 将图像从 BGR 转换为 HLS
    img_hls = cv2.cvtColor(img, cv2.COLOR_BGR2HLS)

    # 使用 matplotlib 显示图像
    plt.imshow(img_hls)
    plt.show()

    # 保存 HLS 图像（直接保存 HLS 数据）
    plt.imsave("hls_image.jpg", img_hls)


# 运行脚本
if __name__ == '__main__':
    image()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
