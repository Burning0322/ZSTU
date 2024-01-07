from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
import time
import math

class CogArch(object):
    Td, Ti, Tm, Tg, Tv, Ts, Ta = 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
    Wd, Wi, Wm, Wg, Wv, Ws, Wa = 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
    totalModel = 0  # 可以同时加载模型的数目
    cogCycle = 50  # 认知周期，缺省为 50 毫秒

    def __init__(self, browser):  # *args, **kwargs):
        self.__Td, self.__Ti, self.__Tm, self.__Tg, self.__Tv, self.__Ts, self.__Ta = 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
        self.__Wd, self.__Wi, self.__Wm, self.__Wg, self.__Wv, self.__Ws, self.__Wa = 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
        self.__totalActiveTime, self.__totalModelTime, self.__totalWorkload = 0.0, 0.0, 0.0
        self.__Weight = {'Declarative': 1.0, 'Imaginal': 5.0, 'Manual': 1.0, 'Goal': 1.2, 'Vision': 1.8,
                         'Speech': 2.0, 'Auditory': 2.0, 'Procedural': 1.0}

        app = QApplication.instance()
        for widget in app.topLevelWidgets():
            if isinstance(widget, QMainWindow):
                self.mainwidget = widget
            self.widget = self.mainwidget.findChild(QTextBrowser, browser)

        self.showInfo(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(Now() / 1000)), '开始\t 初始化完成')

    def startModel(self):
        self.__startTime = Now()
        tmr = Now() - self.__startTime  # 模型已运行时间：毫秒
        self.showInfo(tmr, '模型运行')

    def endModel(self):
        tmr = Now() - self.__startTime  # 模型已运行时间：毫秒
        self.__totalModelTime = tmr
        self.showInfo(tmr, '模型结束.')
        self.showInfo(' 运行：' + str(tmr) + '毫秒', '')

    def modelSetGoal(self, tac=cogCycle):
        time.sleep(tac / 1000)  # 转换秒 所有公式以秒为单位，认知过程以毫秒为单位
        QApplication.processEvents()
        tmr = Now() - self.__startTime
        self.showInfo(tmr, '目标\t 设置目标')
        self.__Tg = self.__Tg + tac
        self.__totalActiveTime = self.__totalActiveTime + tac
        W = self.__Weight['Goal'] * (math.exp(tac / 1000.0) - 1 + math.log(self.__Tg / 1000 + 1))
        self.__Wg = self.__Wg + W
        self.__totalWorkload = self.__totalWorkload + W
