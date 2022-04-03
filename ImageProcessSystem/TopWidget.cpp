/***********************************************************************************
 * 文件名 : TopWidget.cpp
 * 负责人 : kete
 * 创建日期 : 2022/3/15
 * 文件描述 : 顶层Widget
 * 版权说明 :
 * 其它说明 :
 * 修改日志 :
***********************************************************************************/
#include "TopWidget.h"
#include <QDebug>

/*****************************************************************
** 函数名: TopWidget(QWidget* parent)
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 图像处理系统顶层组件，用于设置界面，初始化各组件
** 作　者: kete
** 日　期: 2022/3/15
** 说　明:
******************************************************************/
TopWidget::TopWidget(QWidget* parent) : QWidget(parent)
{
    /*顶层布局（左右两部分）左边为图像处理设置，右边显示图片/视频*/
    topHBoxLayout = new QHBoxLayout(this);
    leftProcessGridWidget = new QWidget();
    rightImageVideoTabWidget = new QTabWidget();
    topHBoxLayout->addWidget(leftProcessGridWidget, 1);
    topHBoxLayout->addWidget(rightImageVideoTabWidget, 3);

    /*右侧图片/视频显示组件*/
    imageShowWidget = new QWidget(rightImageVideoTabWidget);
    videoShowWidget = new QWidget(rightImageVideoTabWidget);
    rightImageVideoTabWidget->addTab(imageShowWidget, QString::fromLocal8Bit("图片"));
    rightImageVideoTabWidget->addTab(videoShowWidget, QString::fromLocal8Bit("视频"));

    /*图片部分（图片显示），从上到下以此为图片显示，图片导入，图片信息显示*/
    imageShowVBoxLayout = new QVBoxLayout(imageShowWidget);
    imageShowLabel = new QLabel(imageShowWidget);
    imageLoadWidget = new QWidget(imageShowWidget);
    imageInfoWidget = new QWidget(imageShowWidget);
    imageShowVBoxLayout->addWidget(imageShowLabel, 14);
    imageShowVBoxLayout->addWidget(imageLoadWidget, 1);
    imageShowVBoxLayout->addWidget(imageInfoWidget, 5);

    /*图片部分（图片导入）,从左到右依次为导入按钮，单行文本框用于显示图片路径，保存按钮*/
    imageLoadHBoxLayout = new QHBoxLayout(imageLoadWidget);
    imageLoadPushButton = new QPushButton(imageLoadWidget);
    imagePathLineEdit = new QLineEdit(imageLoadWidget);
    imageSavePushButton = new QPushButton(imageLoadWidget);
    imageLoadPadding = new QWidget(imageLoadWidget);/*右侧留一定的空白*/
    imageLoadHBoxLayout->addWidget(imageLoadPushButton, 1);
    imageLoadHBoxLayout->addWidget(imagePathLineEdit, 6);
    imageLoadHBoxLayout->addWidget(imageSavePushButton, 1);
    imageLoadHBoxLayout->addWidget(imageLoadPadding, 4);
    imageLoadPushButton->setText(QString::fromLocal8Bit("图片导入"));
    imageSavePushButton->setText(QString::fromLocal8Bit("图片保存"));
    imagePathLineEdit->setReadOnly(true);
    connect(imageLoadPushButton, SIGNAL(clicked()), this, SLOT(onImageLoadPushButtonClick()));

    /*图片部分（图片信息），顶层为横向布局，从左到右依次是图片像素信息（表单布局）...*/
    imageInfoHBoxLayout = new QHBoxLayout(imageInfoWidget);
    imageMatInfoWidget = new QWidget(imageInfoWidget);
    imageInfoHBoxLayout->addWidget(imageMatInfoWidget);
    imageMatInfoFormLayout = new QFormLayout(imageMatInfoWidget);
    imageMatInfoColsLineEdit = new QLineEdit(imageMatInfoWidget);
    imageMatInfoRowsLineEdit = new QLineEdit(imageMatInfoWidget);
    imageMatInfoElemSizeLineEdit = new QLineEdit(imageMatInfoWidget);
    imageMatInfoTotalLineEdit = new QLineEdit(imageMatInfoWidget);
    imageMatInfoChannelsLineEdit = new QLineEdit(imageMatInfoWidget);
    imageMatInfoFormLayout->addRow(QString::fromLocal8Bit("矩阵的列数"), imageMatInfoColsLineEdit);
    imageMatInfoFormLayout->addRow(QString::fromLocal8Bit("矩阵的行数"), imageMatInfoRowsLineEdit);
    imageMatInfoFormLayout->addRow(QString::fromLocal8Bit("每个元素的字节数"), imageMatInfoElemSizeLineEdit);
    imageMatInfoFormLayout->addRow(QString::fromLocal8Bit("矩阵中元素的个数"), imageMatInfoTotalLineEdit);
    imageMatInfoFormLayout->addRow(QString::fromLocal8Bit("矩阵的通道数"), imageMatInfoChannelsLineEdit);
    imageMatInfoColsLineEdit->setReadOnly(true);
    imageMatInfoRowsLineEdit->setReadOnly(true);
    imageMatInfoElemSizeLineEdit->setReadOnly(true);
    imageMatInfoTotalLineEdit->setReadOnly(true);
    imageMatInfoChannelsLineEdit->setReadOnly(true);

    /*视频部分（视频显示），从上到下以此为视频显示，视频导入，视频信息显示*/
    videoShowVBoxLayout = new QVBoxLayout(videoShowWidget);
    videoShowLabel = new QLabel(videoShowWidget);
    videoLoadWidget = new QWidget(imageShowWidget);
    videoInfoWidget = new QWidget(imageShowWidget);
    videoShowVBoxLayout->addWidget(videoShowLabel, 14);
    videoShowVBoxLayout->addWidget(videoLoadWidget, 1);
    videoShowVBoxLayout->addWidget(videoInfoWidget, 5);

    /*视频部分（视频导入）,从左到右依次为打开摄像头，关闭摄像头（暂时）*/
    videoLoadHBoxLayout = new QHBoxLayout(videoLoadWidget);
    videoLoadOpenCameraPushButton = new QPushButton(imageLoadWidget);
    videoLoadCloseCameraPushButton = new QPushButton(imageLoadWidget);
    videoLoadPadding = new QWidget(imageLoadWidget);/*右侧留一定的空白*/
    videoLoadHBoxLayout->addWidget(videoLoadOpenCameraPushButton, 1);
    videoLoadHBoxLayout->addWidget(videoLoadCloseCameraPushButton, 1);
    videoLoadHBoxLayout->addWidget(imageLoadPadding, 8);
    videoLoadOpenCameraPushButton->setText(QString::fromLocal8Bit("打开摄像头"));
    videoLoadCloseCameraPushButton->setText(QString::fromLocal8Bit("关闭摄像头"));
    connect(videoLoadOpenCameraPushButton, SIGNAL(clicked()), this, SLOT(onVideoLoadOpenCameraPushButtonClick()));
    connect(videoLoadCloseCameraPushButton, SIGNAL(clicked()), this, SLOT(onVideoLoadCloseCameraPushButtonClick()));
}

/*****************************************************************
** 函数名: onImageLoadPushButtonClick()
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 图像载入槽函数，相应图像载入按钮点击
** 作　者: kete
** 日　期: 2022/3/15
** 说　明:
******************************************************************/
void TopWidget::onImageLoadPushButtonClick()
{
    QString fileName = QFileDialog::getOpenFileName(imageLoadWidget, tr("Open Image"),".",tr("Image Files (*.png *.jpg *.bmp)"));

    imagePathLineEdit->setText(fileName);

    cvImage = imread(fileName.toLatin1().data());
    qImage = QImage(cvImage.data, cvImage.cols, cvImage.rows, QImage::Format_RGB888);

    imageShowLabel->setPixmap(QPixmap::fromImage(qImage));

    updateMatInfo(cvImage);
}

/*****************************************************************
** 函数名: updateMatInfo()
** 输　入: const Mat& mat
** 输　出: 无
** 返回值: bool
** 功能描述: 更新图片的Mat类属性信息
** 作　者: kete
** 日　期: 2022/3/17
** 说　明:
******************************************************************/
bool TopWidget::updateMatInfo(const Mat& mat)
{
    bool ret = !mat.empty();

    if(ret)
    {
        imageMatInfoColsLineEdit->setText(QString().sprintf("%d", mat.cols));
        imageMatInfoRowsLineEdit->setText(QString().sprintf("%d", mat.rows));
        imageMatInfoElemSizeLineEdit->setText(QString().sprintf("%d", mat.elemSize()));
        imageMatInfoTotalLineEdit->setText(QString().sprintf("%d", mat.total()));
        imageMatInfoChannelsLineEdit->setText(QString().sprintf("%d", mat.channels()));
    }

    return ret;
}

/*****************************************************************
** 函数名: onVideoLoadOpenCameraPushButtonClick
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 打开摄像头槽函数
** 作　者: kete
** 日　期: 2022/4/3
** 说　明:
******************************************************************/
void TopWidget::onVideoLoadOpenCameraPushButtonClick()
{
    cvVideoCap = VideoCapture(0);

    if( cvVideoCap.open(0) )
    {



        while(1)
        {
            Mat cvMatframe;

            cvVideoCap >> cvMatframe;

            if(cvMatframe.empty())
            {
                break;
            }

            videoShowLabel->setPixmap(QPixmap::fromImage(QImage(cvMatframe.data, cvMatframe.cols, cvMatframe.rows, QImage::Format_RGB888)));

            qDebug() << cvVideoCap.get(CAP_PROP_POS_MSEC);
            qDebug() << cvVideoCap.get(CAP_PROP_FRAME_WIDTH);
            qDebug() << cvVideoCap.get(CAP_PROP_FRAME_HEIGHT);
            qDebug() << cvVideoCap.get(CAP_PROP_FPS);
            qDebug() << cvVideoCap.get(CAP_PROP_FOURCC);

            qDebug() << cvVideoCap.get(CAP_PROP_FRAME_COUNT);
            qDebug() << cvVideoCap.get(CAP_PROP_FORMAT);
            qDebug() << cvVideoCap.get(CAP_PROP_BRIGHTNESS);
            qDebug() << cvVideoCap.get(CAP_PROP_CONTRAST);
            qDebug() << cvVideoCap.get(CAP_PROP_SATURATION);
            qDebug() << cvVideoCap.get(CAP_PROP_HUE);
            qDebug() << cvVideoCap.get(CAP_PROP_GAIN);

            waitKey(1000 / cvVideoCap.get(CAP_PROP_FPS));
        }

    }
}

/*****************************************************************
** 函数名: onVideoLoadCloseCameraPushButtonClick
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 关闭摄像头槽函数
** 作　者: kete
** 日　期: 2022/4/3
** 说　明:
******************************************************************/
void TopWidget::onVideoLoadCloseCameraPushButtonClick()
{
    cvVideoCap.release();

    videoShowLabel->clear();
}

TopWidget::~TopWidget()
{

}
