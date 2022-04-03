/***********************************************************************************
 * 文件名 : TopWidget.h
 * 负责人 : kete
 * 创建日期 : 2022/3/15
 * 文件描述 : 顶层Widget
 * 版权说明 :
 * 其它说明 :
 * 修改日志 :
***********************************************************************************/
#ifndef _TOPWIDGET_H_
#define _TOPWIDGET_H_

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QTabWidget>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include "../opencv2/opencv.hpp"

using namespace cv;

class TopWidget : public QWidget
{
    Q_OBJECT

    /*保存图片的类*/
    Mat cvImage;
    QImage qImage;

    /*摄像头类*/
    VideoCapture cvVideoCap;

    /*顶层布局（左右两部分）左边为图像处理设置，右边显示图片/视频*/
    QHBoxLayout* topHBoxLayout;/*顶层布局管理组,横向布局,左边为图像处理，右边为图片/视频*/
    QWidget* leftProcessGridWidget;/*顶层布局管理组的左边，网格布局，为各个模块的处理单元*/
    QTabWidget* rightImageVideoTabWidget;/*顶层布局管理组的右边，图片/视频*/

    /*右侧图片/视频显示组件*/
    QWidget* imageShowWidget;
    QWidget* videoShowWidget;

    /*图片部分（图片显示），从上到下以此为图片显示，图片导入，图片信息显示*/
    QVBoxLayout* imageShowVBoxLayout;
    QLabel* imageShowLabel;
    QWidget* imageLoadWidget;
    QWidget* imageInfoWidget;

    /*图片部分（图片导入）,从左到右依次为导入按钮，单行文本框用于显示图片路径，保存按钮*/
    QHBoxLayout* imageLoadHBoxLayout;
    QPushButton* imageLoadPushButton;
    QPushButton* imageSavePushButton;
    QLineEdit* imagePathLineEdit;
    QWidget* imageLoadPadding;

    /*图片部分（图片信息），顶层为横向布局，从左到右依次是图片像素信息（表单布局）...*/
    QHBoxLayout* imageInfoHBoxLayout;
    QWidget* imageMatInfoWidget;
    QFormLayout* imageMatInfoFormLayout;
    QLineEdit* imageMatInfoColsLineEdit;
    QLineEdit* imageMatInfoRowsLineEdit;
    QLineEdit* imageMatInfoElemSizeLineEdit;
    QLineEdit* imageMatInfoTotalLineEdit;
    QLineEdit* imageMatInfoChannelsLineEdit;
    bool updateMatInfo(const Mat& mat);

    /*视频部分（视频显示），从上到下依次为视频显示，视频导入，视频信息*/
    QVBoxLayout* videoShowVBoxLayout;
    QLabel* videoShowLabel;
    QWidget* videoLoadWidget;
    QWidget* videoInfoWidget;

    /*视频部分（视频导入）,暂时只支持打开摄像头*/
    QHBoxLayout* videoLoadHBoxLayout;
    QPushButton* videoLoadOpenCameraPushButton;
    QPushButton* videoLoadCloseCameraPushButton;
    QWidget* videoLoadPadding;


private slots:
    void onImageLoadPushButtonClick();
    void onVideoLoadOpenCameraPushButtonClick();
    void onVideoLoadCloseCameraPushButtonClick();

public:
    TopWidget(QWidget* parent = 0);
    ~TopWidget();
};

#endif //_TOPWIDGET_H_
