/***********************************************************************************
 * 文件名 : main.cpp
 * 负责人 : kete
 * 创建日期 : 2022/3/15
 * 文件描述 : 主程序
 * 版权说明 :
 * 其它说明 :
        1. 项目要编译OpenCV，必须使用MSCV2015编译器
        2. 解决界面中文显示乱码的问题：https://www.cnblogs.com/zhangdewang/p/7756251.html
***********************************************************************************/
#include "TopWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TopWidget w;

    w.show();
    w.setWindowState(Qt::WindowMaximized);
    w.setWindowTitle(QString::fromLocal8Bit("基于OpenCV的图像处理系统的设计与实现  武汉邮电科学研究院软件工程课程项目 柯特 20210018"));

    return a.exec();
}
