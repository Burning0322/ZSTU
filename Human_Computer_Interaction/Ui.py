from PyQt5.QtCore import QDate, QTime, QDateTime, Qt
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QFileDialog, QGridLayout
from PyQt5.QtWidgets import QApplication, QDialog, QMessageBox
from PyQt5.QtGui import QPixmap
from PyQt5.uic import loadUi
import numpy as np
import sys
import os
curPath = os.path.dirname(os.path.dirname(__file__))
sys.path.append(curPath)
from Ui import MainWindow
from About import Ui_aboutDialog
from myfigure import MyFigure
from CogArch import *
class POSCogArch(CogArch):
    def __init__(self, browser = 'CogArch'):
        super(POSCogArch,self).__init__(browser)
    def crossApper(self,tac):
        pass
    def digitalApper(self, tac):
        pass
class MyWindow(MainWindow):
    def __init__(self, name='MyWindow'):
        super(MyWindow, self).__init__()
        self.statisInfo = dict()
        self.gradlayloaded = 0
        self.gradlaywloaded = 0
    def plotc(self, dataInfo, Title):
        self.F1.axes.plot(*zip(*sorted(dataInfo.items())))
        for item in dataInfo:
            self.F1.axes.scatter(item, dataInfo[item][0], marker='x')  # mean
    def plotcos(self, dataInfo, Title):
        self.F.axes.plot(*zip(*sorted(dataInfo.items())))
        for item in dataInfo:
            self.F.axes.scatter(item, dataInfo[item][0], marker='x')  # mean

    def about_menu_triggered(self):
        dlg = aboutDlgInit()
        dlg.exec()

    def on_model_open_clicked(self):
        my_file_path = QFileDialog.getOpenFileName(self.centralwidget, '选择文件','','Cognitive Model files(*.cogmo, *.txt)')
        if os.path.exists(my_file_path[0]):
            f = open(my_file_path[0], "r", encoding="utf-8")
        else:
            return
        self.infotextBrowser.clear()
        j = 1
        for line in f:
            self.infotextBrowser.append('{0} {1}'.format(j, line))
            j = j + 1
        f.close()

    def on_model_run_clicked(self):
        if self.gradlayloaded == 0:
            self.gridlayout = QGridLayout(self.groupBox)
            self.gradlayloaded = 1
        if self.gradlaywloaded == 0:
            self.gridlayoutwork = QGridLayout(self.workgroupBox)
            self.gradlaywloaded = 1
        alltext = self.infotextBrowser.toPlainText()
        self.modelrunBrowser.setWordWrapMode(0)
        self.modelrunBrowser.clear()
        ca = POSCogArch("modelrunBrowser")
        ca.startModel()

        for line in alltext.split('\n'):
            t=line.lstrip('[0123456789]')
            if '#' in t:
                t = t[0:t.rfind('#')]
            if len(t.split()) > 0:
                eval('ca.'+t.strip())
        ca.endModel()
        ca.showResult()
        self.statisInfo.setdefault('Declarative',[]).append(ca.Td)
        self.statisInfo.setdefault('Imaginal',[]).append(ca.Ti)
        self.statisInfo.setdefault('Manual',[]).append(ca.Tm)
        self.statisInfo.setdefault('Goal',[]).append(ca.Tg)
        self.statisInfo.setdefault('Vision',[]).append(ca.Tv)
        self.statisInfo.setdefault('Speech',[]).append(ca.Ts)
        self.statisInfo.setdefault('Auditory',[]).append(ca.Ta)
        self.F = MyFigure(width=3, height=2, dpi=100)
        self.plotcos(self.statisInfo, '响应时间随时间变化情况') #
        self.gridlayout.addWidget(self.F,0,1)
        #self.statisInfo.setdefault('Procedural',[]).append(self.)
        self.statisInfo.clear()
        self.statisInfo.setdefault('Declarative',[]).append(ca.Wd)
        self.statisInfo.setdefault('Imaginal',[]).append(ca.Wi)
        self.statisInfo.setdefault('Manual',[]).append(ca.Wm)
        self.statisInfo.setdefault('Goal',[]).append(ca.Wg)
        self.statisInfo.setdefault('Vision',[]).append(ca.Wv)
        self.statisInfo.setdefault('Speech',[]).append(ca.Ws)
        self.statisInfo.setdefault('Auditory',[]).append(ca.Wa)
        self.F1 = MyFigure(width=3, height=2, dpi=100)
        self.plotc(self.statisInfo, '响应时间随时间变化情况') #
        self.gridlayoutwork.addWidget(self.F1,0,1)
class aboutDlgInit(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        # Create an instance of the GUI
        #self.ui = Ui_aboutDialog()
        # Run the .setupUi() method to show the GUI
        #self.ui.setupUi(self)
        # Load the dialog's GUI
        loadUi("about.ui", self)

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = MyWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
