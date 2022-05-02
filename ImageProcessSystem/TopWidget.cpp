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
    leftProcessVBoxWidget = new QWidget();
    rightImageVideoTabWidget = new QTabWidget();
    topHBoxLayout->addWidget(leftProcessVBoxWidget, 1);
    topHBoxLayout->addWidget(rightImageVideoTabWidget, 3);

    /*左侧图像处理部分*/
    leftProcessVBoxLayout = new QVBoxLayout(leftProcessVBoxWidget);

    /*图像处理第一部分-颜色模型转换与分离*/
    imageColorTransSplitGroupBox = new QGroupBox(leftProcessVBoxWidget);
    imageColorTransSplitGroupBox->setTitle(QString::fromLocal8Bit("颜色模型转换与分离"));
    leftProcessVBoxLayout->addWidget(imageColorTransSplitGroupBox);
    imageColorTransSplitHBoxLayout = new QHBoxLayout(imageColorTransSplitGroupBox);
    imageColorRGBRadioButton = new QRadioButton("RGB", imageColorTransSplitGroupBox);
    imageColorYUVRadioButton = new QRadioButton("YUV", imageColorTransSplitGroupBox);
    imageColorHSVRadioButton = new QRadioButton("HSV", imageColorTransSplitGroupBox);
    imageColorLabRadioButton = new QRadioButton("Lab", imageColorTransSplitGroupBox);
    imageColorGRAYRadioButton = new QRadioButton("GRAY", imageColorTransSplitGroupBox);
    imageColorSplitPushButton = new QPushButton(imageColorTransSplitGroupBox);
    imageColorSplitPushButton->setText(QString::fromLocal8Bit("图像颜色分离"));
    imageColorTransSplitHBoxLayout->addWidget(imageColorRGBRadioButton);
    imageColorTransSplitHBoxLayout->addWidget(imageColorYUVRadioButton);
    imageColorTransSplitHBoxLayout->addWidget(imageColorHSVRadioButton);
    imageColorTransSplitHBoxLayout->addWidget(imageColorLabRadioButton);
    imageColorTransSplitHBoxLayout->addWidget(imageColorGRAYRadioButton);
    imageColorTransSplitHBoxLayout->addWidget(imageColorSplitPushButton);
    connect(imageColorRGBRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageColorRGBRadioButtonToggle(bool)));
    connect(imageColorYUVRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageColorYUVRadioButtonToggle(bool)));
    connect(imageColorHSVRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageColorHSVRadioButtonToggle(bool)));
    connect(imageColorLabRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageColorLabRadioButtonToggle(bool)));
    connect(imageColorGRAYRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageColorGRAYRadioButtonToggle(bool)));
    connect(imageColorSplitPushButton, SIGNAL(clicked()), this, SLOT(onImageColorSplitPushButtonClick()));

    /*图像处理第二部分-单图像的像素操作*/
    imageSinglePixelProcessGroupBox = new QGroupBox(leftProcessVBoxWidget);
    imageSinglePixelProcessGroupBox->setTitle(QString::fromLocal8Bit("单图像的像素操作"));
    leftProcessVBoxLayout->addWidget(imageSinglePixelProcessGroupBox);
    imageSinglePixelProcessHBoxLayout = new QHBoxLayout(imageSinglePixelProcessGroupBox);
    imageSinglePixelProcessOriginalRadioButton = new QRadioButton(QString::fromLocal8Bit("恢复原始图像"), imageSinglePixelProcessGroupBox);
    imageSinglePixelProcessNotRadioButton = new QRadioButton(QString::fromLocal8Bit("像素取反"), imageSinglePixelProcessGroupBox);
    imageSinglePixelProcessThresholdOTSURadioButton = new QRadioButton(QString::fromLocal8Bit("二值化(全局大津法)"), imageSinglePixelProcessGroupBox);
    imageSinglePixelProcessThresholdTRIANGLERadioButton = new QRadioButton(QString::fromLocal8Bit("二值化(全局三角形法)"), imageSinglePixelProcessGroupBox);
    imageSinglePixelProcessAdaptiveThresholdMEANRadioButton = new QRadioButton(QString::fromLocal8Bit("二值化(自适应均值法)"), imageSinglePixelProcessGroupBox);
    imageSinglePixelProcessAdaptiveThresholdGAUSSIANRadioButton = new QRadioButton(QString::fromLocal8Bit("二值化(自适应高斯法)"), imageSinglePixelProcessGroupBox);
    imageSinglePixelProcessHBoxLayout->addWidget(imageSinglePixelProcessOriginalRadioButton);
    imageSinglePixelProcessHBoxLayout->addWidget(imageSinglePixelProcessNotRadioButton);
    imageSinglePixelProcessHBoxLayout->addWidget(imageSinglePixelProcessThresholdOTSURadioButton);
    imageSinglePixelProcessHBoxLayout->addWidget(imageSinglePixelProcessThresholdTRIANGLERadioButton);
    imageSinglePixelProcessHBoxLayout->addWidget(imageSinglePixelProcessAdaptiveThresholdMEANRadioButton);
    imageSinglePixelProcessHBoxLayout->addWidget(imageSinglePixelProcessAdaptiveThresholdGAUSSIANRadioButton);
    connect(imageSinglePixelProcessOriginalRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageSinglePixelProcessOriginalRadioButtonToggle(bool)));
    connect(imageSinglePixelProcessNotRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageSinglePixelProcessNotRadioButtonToggle(bool)));
    connect(imageSinglePixelProcessThresholdOTSURadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageSinglePixelProcessThresholdOTSURadioButtonToggle(bool)));
    connect(imageSinglePixelProcessThresholdTRIANGLERadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageSinglePixelProcessThresholdTRIANGLERadioButtonToggle(bool)));
    connect(imageSinglePixelProcessAdaptiveThresholdMEANRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageSinglePixelProcessAdaptiveThresholdMEANRadioButtonToggle(bool)));
    connect(imageSinglePixelProcessAdaptiveThresholdGAUSSIANRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageSinglePixelProcessAdaptiveThresholdGAUSSIANRadioButtonToggle(bool)));

    /*图像处理第三部分-两图像间的像素操作*/
    imagePairPixelProcessGroupBox = new QGroupBox(leftProcessVBoxWidget);
    imagePairPixelProcessGroupBox->setTitle(QString::fromLocal8Bit("两图像间的像素操作"));
    imagePairPixelProcessVBoxLayout = new QVBoxLayout(imagePairPixelProcessGroupBox);
    leftProcessVBoxLayout->addWidget(imagePairPixelProcessGroupBox);
    imagePairPixelProcessLoadImageWidget = new QWidget(imagePairPixelProcessGroupBox);
    imagePairPixelProcessLoadImageGridLayout = new QGridLayout(imagePairPixelProcessLoadImageWidget);
    imagePairPixelProcessLoadImage1PushButton = new QPushButton(QString::fromLocal8Bit("加载第一张图片"), imagePairPixelProcessLoadImageWidget);
    imagePairPixelProcessLoadImage2PushButton = new QPushButton(QString::fromLocal8Bit("加载第二张图片"), imagePairPixelProcessLoadImageWidget);
    imagePairPixelProcessLoadImage1PathLineEdit = new QLineEdit(imagePairPixelProcessLoadImageWidget);
    imagePairPixelProcessLoadImage2PathLineEdit = new QLineEdit(imagePairPixelProcessLoadImageWidget);
    imagePairPixelProcessLoadImage1PathLineEdit->setReadOnly(true);
    imagePairPixelProcessLoadImage2PathLineEdit->setReadOnly(true);
    imagePairPixelProcessLoadImageGridLayout->addWidget(imagePairPixelProcessLoadImage1PushButton, 0, 0);
    imagePairPixelProcessLoadImageGridLayout->addWidget(imagePairPixelProcessLoadImage1PathLineEdit, 0, 1);
    imagePairPixelProcessLoadImageGridLayout->addWidget(imagePairPixelProcessLoadImage2PushButton, 1, 0);
    imagePairPixelProcessLoadImageGridLayout->addWidget(imagePairPixelProcessLoadImage2PathLineEdit, 1, 1);
    imagePairPixelProcessVBoxLayout->addWidget(imagePairPixelProcessLoadImageWidget);
    imagePairPixelProcessCalGroupBox = new QGroupBox(imagePairPixelProcessGroupBox);
    imagePairPixelProcessCalHBoxLayout = new QHBoxLayout(imagePairPixelProcessCalGroupBox);
    imagePairPixelProcessCLRRadioButton = new QRadioButton(QString::fromLocal8Bit("清除"), imagePairPixelProcessCalGroupBox);
    imagePairPixelProcessMAXRadioButton = new QRadioButton(QString::fromLocal8Bit("max"), imagePairPixelProcessCalGroupBox);
    imagePairPixelProcessMINRadioButton = new QRadioButton(QString::fromLocal8Bit("min"), imagePairPixelProcessCalGroupBox);
    imagePairPixelProcessANDRadioButton = new QRadioButton(QString::fromLocal8Bit("and"), imagePairPixelProcessCalGroupBox);
    imagePairPixelProcessORRadioButton = new QRadioButton(QString::fromLocal8Bit("or"), imagePairPixelProcessCalGroupBox);
    imagePairPixelProcessXORRadioButton = new QRadioButton(QString::fromLocal8Bit("xor"), imagePairPixelProcessCalGroupBox);
    imagePairPixelProcessCalHBoxLayout->addWidget(imagePairPixelProcessCLRRadioButton);
    imagePairPixelProcessCalHBoxLayout->addWidget(imagePairPixelProcessMAXRadioButton);
    imagePairPixelProcessCalHBoxLayout->addWidget(imagePairPixelProcessMINRadioButton);
    imagePairPixelProcessCalHBoxLayout->addWidget(imagePairPixelProcessANDRadioButton);
    imagePairPixelProcessCalHBoxLayout->addWidget(imagePairPixelProcessORRadioButton);
    imagePairPixelProcessCalHBoxLayout->addWidget(imagePairPixelProcessXORRadioButton);
    imagePairPixelProcessVBoxLayout->addWidget(imagePairPixelProcessCalGroupBox);
    connect(imagePairPixelProcessLoadImage1PushButton, SIGNAL(clicked()), this, SLOT(onImagePairPixelProcessLoadImage1PushButtonClick()));
    connect(imagePairPixelProcessLoadImage2PushButton, SIGNAL(clicked()), this, SLOT(onImagePairPixelProcessLoadImage2PushButtonClick()));
    connect(imagePairPixelProcessCLRRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImagePairPixelProcessCLRRadioButtonToggle(bool)));
    connect(imagePairPixelProcessMAXRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImagePairPixelProcessMAXRadioButtonToggle(bool)));
    connect(imagePairPixelProcessMINRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImagePairPixelProcessMINRadioButtonToggle(bool)));
    connect(imagePairPixelProcessANDRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImagePairPixelProcessANDRadioButtonToggle(bool)));
    connect(imagePairPixelProcessORRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImagePairPixelProcessORRadioButtonToggle(bool)));
    connect(imagePairPixelProcessXORRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImagePairPixelProcessXORRadioButtonToggle(bool)));

    /*图像处理第四部分-图像的缩放和旋转*/
    imageZoomAndRotateGroupBox = new QGroupBox(leftProcessVBoxWidget);
    imageZoomAndRotateGroupBox->setTitle(QString::fromLocal8Bit("图像的缩放和翻转"));
    leftProcessVBoxLayout->addWidget(imageZoomAndRotateGroupBox);
    imageZoomAndRotateGridLayout = new QGridLayout(imageZoomAndRotateGroupBox);
    imageZoomSlider = new QSlider(Qt::Horizontal, imageZoomAndRotateGroupBox);
    imageRotateSlider = new QSlider(Qt::Horizontal, imageZoomAndRotateGroupBox);
    imageZoomTextLabel = new QLabel(imageZoomAndRotateGroupBox);
    imageRotateTextLabel = new QLabel(imageZoomAndRotateGroupBox);
    imageZoomValueLabel = new QLabel(imageZoomAndRotateGroupBox);
    imageRotateValueLabel = new QLabel(imageZoomAndRotateGroupBox);
    imageZoomTextLabel->setText(QString::fromLocal8Bit("缩放"));
    imageRotateTextLabel->setText(QString::fromLocal8Bit("旋转"));
    imageZoomValueLabel->setNum(1);
    imageRotateValueLabel->setNum(0);
    imageZoomSlider->setFixedWidth(300);
    imageRotateSlider->setFixedWidth(300);
    imageZoomSlider->setRange(0, 100);
    imageZoomSlider->setValue(50);
    imageRotateSlider->setRange(0, 360);
    imageZoomAndRotateGridLayout->addWidget(imageZoomTextLabel, 0, 0, Qt::AlignCenter);
    imageZoomAndRotateGridLayout->addWidget(imageZoomSlider, 0, 1, Qt::AlignCenter);
    imageZoomAndRotateGridLayout->addWidget(imageZoomValueLabel, 0, 2, Qt::AlignCenter);
    imageZoomAndRotateGridLayout->addWidget(imageRotateTextLabel, 1, 0, Qt::AlignCenter);
    imageZoomAndRotateGridLayout->addWidget(imageRotateSlider, 1, 1, Qt::AlignCenter);
    imageZoomAndRotateGridLayout->addWidget(imageRotateValueLabel, 1, 2, Qt::AlignCenter);
    imageZoomAndRotateGridLayout->setColumnMinimumWidth(1, 300);
    connect(imageZoomSlider, SIGNAL(valueChanged(int)), this, SLOT(onImageZoomValueChanged(int)));
    connect(imageRotateSlider, SIGNAL(valueChanged(int)), this, SLOT(onImageRotateValueChanged(int)));

    /*图像处理第五部分-直方图应用*/
    imageHistApplyGroupBox = new QGroupBox(leftProcessVBoxWidget);
    imageHistApplyVBoxLayout = new QVBoxLayout(imageHistApplyGroupBox);
    imageHistApplyGroupBox->setTitle(QString::fromLocal8Bit("直方图应用"));
    imageHistApplyEqualizeGroupBox = new QGroupBox(imageHistApplyGroupBox);
    imageHistApplyEqualizeHBoxLayout = new QHBoxLayout(imageHistApplyEqualizeGroupBox);
    imageHistApplyEqualizeGroupBox->setTitle(QString::fromLocal8Bit("直方图均衡化"));
    imageHistApplyEqualizeRestoreRadioButton = new QRadioButton(QString::fromLocal8Bit("恢复原始图像"), imageHistApplyEqualizeGroupBox);
    imageHistApplyEqualizeGrayRadioButton = new QRadioButton(QString::fromLocal8Bit("灰度图"), imageHistApplyEqualizeGroupBox);
    imageHistApplyEqualizeEqualizeRadioButton = new QRadioButton(QString::fromLocal8Bit("均衡化"), imageHistApplyEqualizeGroupBox);
    imageHistApplyEqualizeRestoreRadioButton->setChecked(true);
    imageHistApplyEqualizeHBoxLayout->addWidget(imageHistApplyEqualizeRestoreRadioButton);
    imageHistApplyEqualizeHBoxLayout->addWidget(imageHistApplyEqualizeGrayRadioButton);
    imageHistApplyEqualizeHBoxLayout->addWidget(imageHistApplyEqualizeEqualizeRadioButton);
    imageHistApplyTemplateMatchGroupBox = new QGroupBox(imageHistApplyGroupBox);
    imageHistApplyTemplateMatchHBoxLayout = new QHBoxLayout(imageHistApplyTemplateMatchGroupBox);
    imageHistApplyTemplateMatchGroupBox->setTitle(QString::fromLocal8Bit("图像的模板匹配"));
    imageHistApplyTemplateMatchLoadPushButton = new QPushButton(imageHistApplyGroupBox);
    imageHistApplyTemplateMatchLoadPushButton->setText(QString::fromLocal8Bit("载入模板"));
    imageHistApplyTemplateMatchPathLineEdit = new QLineEdit(imageHistApplyTemplateMatchGroupBox);
    imageHistApplyTemplateMatchPathLineEdit->setReadOnly(true);
    imageHistApplyTemplateMatchMatchPushButton = new QPushButton(imageHistApplyTemplateMatchGroupBox);
    imageHistApplyTemplateMatchMatchPushButton->setText(QString::fromLocal8Bit("匹配模板"));
    imageHistApplyTemplateMatchHBoxLayout->addWidget(imageHistApplyTemplateMatchLoadPushButton);
    imageHistApplyTemplateMatchHBoxLayout->addWidget(imageHistApplyTemplateMatchPathLineEdit);
    imageHistApplyTemplateMatchHBoxLayout->addWidget(imageHistApplyTemplateMatchMatchPushButton);
    imageHistApplyVBoxLayout->addWidget(imageHistApplyEqualizeGroupBox);
    imageHistApplyVBoxLayout->addWidget(imageHistApplyTemplateMatchGroupBox);
    leftProcessVBoxLayout->addWidget(imageHistApplyGroupBox);
    connect(imageHistApplyEqualizeRestoreRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageHistApplyRestoreRadioButtonToggle(bool)));
    connect(imageHistApplyEqualizeGrayRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageHistApplyGrayRadioButtonToggle(bool)));
    connect(imageHistApplyEqualizeEqualizeRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageHistApplyEqualizeRadioButtonToggle(bool)));
    connect(imageHistApplyTemplateMatchLoadPushButton, SIGNAL(clicked()), this, SLOT(onImageHistApplyTemplateLoadPushButtonClick()));
    connect(imageHistApplyTemplateMatchMatchPushButton, SIGNAL(clicked()), this, SLOT(onImageHistApplyTemplateMatchPushButtonClick()));

    /*图像处理第六部分-图像滤波*/
    imageFilterGroupBox = new QGroupBox(leftProcessVBoxWidget);
    imageFilterGroupBox->setTitle(QString::fromLocal8Bit("图像滤波"));
    imageFileterVBoxLayout = new QVBoxLayout(imageFilterGroupBox);
    leftProcessVBoxLayout->addWidget(imageFilterGroupBox);
    imageFilterAddNoiseGroupBox = new QGroupBox(imageFilterGroupBox);
    imageFilterAddNoiseGroupBox->setTitle(QString::fromLocal8Bit("图像加噪"));
    imageFilterAddNoiseGridLayout = new QGridLayout(imageFilterAddNoiseGroupBox);
    imageFileterVBoxLayout->addWidget(imageFilterAddNoiseGroupBox);
    imageFilterAddNoiseSaltTextLabel = new QLabel(QString::fromLocal8Bit("椒盐噪声"), imageFilterAddNoiseGroupBox);
    imageFilterAddNoiseSaltSlider = new QSlider(Qt::Horizontal, imageFilterAddNoiseGroupBox);
    imageFilterAddNoiseSaltSlider->setFixedWidth(300);
    imageFilterAddNoiseSaltSlider->setRange(0, 10000);
    imageFilterAddNoiseSaltSlider->setValue(0);
    imageFilterAddNoiseSaltValueLabel = new QLabel(imageFilterAddNoiseGroupBox);
    imageFilterAddNoiseSaltValueLabel->setNum(0);
    imageFilterAddNoiseGaussAvgTextLabel = new QLabel(QString::fromLocal8Bit("高斯噪音(均值)"), imageFilterAddNoiseGroupBox);
    imageFilterAddNoiseGaussAvgSlider = new QSlider(Qt::Horizontal, imageFilterAddNoiseGroupBox);
    imageFilterAddNoiseGaussAvgSlider->setFixedWidth(300);
    imageFilterAddNoiseGaussAvgSlider->setRange(0, 50);
    imageFilterAddNoiseGaussAvgSlider->setValue(0);
    imageFilterAddNoiseGaussAvgValueLabel = new QLabel(imageFilterAddNoiseGroupBox);
    imageFilterAddNoiseGaussAvgValueLabel->setNum(0);
    imageFilterAddNoiseGaussStdTextLabel = new QLabel(QString::fromLocal8Bit("高斯噪音(标准差)"), imageFilterAddNoiseGroupBox);
    imageFilterAddNoiseGaussStdSlider = new QSlider(Qt::Horizontal, imageFilterAddNoiseGroupBox);
    imageFilterAddNoiseGaussStdSlider->setFixedWidth(300);
    imageFilterAddNoiseGaussStdSlider->setRange(0, 50);
    imageFilterAddNoiseGaussStdSlider->setValue(0);
    imageFilterAddNoiseGaussStdValueLabel = new QLabel(imageFilterAddNoiseGroupBox);
    imageFilterAddNoiseGaussStdValueLabel->setNum(0);
    imageFilterAddNoiseGridLayout->addWidget(imageFilterAddNoiseSaltTextLabel, 0, 0);
    imageFilterAddNoiseGridLayout->addWidget(imageFilterAddNoiseSaltSlider, 0, 1);
    imageFilterAddNoiseGridLayout->addWidget(imageFilterAddNoiseSaltValueLabel, 0, 2);
    imageFilterAddNoiseGridLayout->addWidget(imageFilterAddNoiseGaussAvgTextLabel, 1, 0);
    imageFilterAddNoiseGridLayout->addWidget(imageFilterAddNoiseGaussAvgSlider, 1, 1);
    imageFilterAddNoiseGridLayout->addWidget(imageFilterAddNoiseGaussAvgValueLabel, 1, 2);
    imageFilterAddNoiseGridLayout->addWidget(imageFilterAddNoiseGaussStdTextLabel, 2, 0);
    imageFilterAddNoiseGridLayout->addWidget(imageFilterAddNoiseGaussStdSlider, 2, 1);
    imageFilterAddNoiseGridLayout->addWidget(imageFilterAddNoiseGaussStdValueLabel, 2, 2);
    imageFilterLowPassFilterGroupBox = new QGroupBox(imageFilterGroupBox);
    imageFilterLowPassFilterGroupBox->setTitle(QString::fromLocal8Bit("图像低通滤波"));
    imageFilterLowPassFilterHBoxLayout = new QHBoxLayout(imageFilterLowPassFilterGroupBox);
    imageFileterVBoxLayout->addWidget(imageFilterLowPassFilterGroupBox);
    imageFilterLowPassFilterOriginalRadioButton = new QRadioButton(QString::fromLocal8Bit("原图"), imageFilterLowPassFilterGroupBox);
    imageFilterLowPassFilterOriginalRadioButton->setChecked(true);
    imageFilterLowPassFilterBlurRadioButton = new QRadioButton(QString::fromLocal8Bit("均值滤波(线性)"), imageFilterLowPassFilterGroupBox);
    imageFilterLowPassFilterGaussBlurRadioButton = new QRadioButton(QString::fromLocal8Bit("高斯滤波(线性)"), imageFilterLowPassFilterGroupBox);
    imageFilterLowPassFilterMedianBlurRadioButton = new QRadioButton(QString::fromLocal8Bit("中值滤波(非线性)"), imageFilterLowPassFilterGroupBox);
    imageFilterLowPassFilterHBoxLayout->addWidget(imageFilterLowPassFilterOriginalRadioButton);
    imageFilterLowPassFilterHBoxLayout->addWidget(imageFilterLowPassFilterBlurRadioButton);
    imageFilterLowPassFilterHBoxLayout->addWidget(imageFilterLowPassFilterGaussBlurRadioButton);
    imageFilterLowPassFilterHBoxLayout->addWidget(imageFilterLowPassFilterMedianBlurRadioButton);
    imageFilterHighPassFilterGroupBox = new QGroupBox(imageFilterGroupBox);
    imageFilterHighPassFilterGroupBox->setTitle(QString::fromLocal8Bit("图像高通滤波(边缘检测)"));
    imageFilterHighPassFilterHBoxLayout = new QHBoxLayout(imageFilterHighPassFilterGroupBox);
    imageFileterVBoxLayout->addWidget(imageFilterHighPassFilterGroupBox);
    imageFilterHighPassFilterOriginalRadioButton = new QRadioButton(QString::fromLocal8Bit("原图"), imageFilterHighPassFilterGroupBox);
    imageFilterHighPassFilterOriginalRadioButton->setChecked(true);
    imageFilterHighPassFilterSobelRadioButton = new QRadioButton(QString::fromLocal8Bit("Sobel算子"), imageFilterHighPassFilterGroupBox);
    imageFilterHighPassFilterScharrRadioButton = new QRadioButton(QString::fromLocal8Bit("Schaar算子"), imageFilterHighPassFilterGroupBox);
    imageFilterHighPassFilterLaplacianRadioButton = new QRadioButton(QString::fromLocal8Bit("Laplacian算子"), imageFilterHighPassFilterGroupBox);
    imageFilterHighPassFilterCannyRadioButton = new QRadioButton(QString::fromLocal8Bit("Canny算法"), imageFilterHighPassFilterGroupBox);
    imageFilterHighPassFilterHBoxLayout->addWidget(imageFilterHighPassFilterOriginalRadioButton);
    imageFilterHighPassFilterHBoxLayout->addWidget(imageFilterHighPassFilterSobelRadioButton);
    imageFilterHighPassFilterHBoxLayout->addWidget(imageFilterHighPassFilterScharrRadioButton);
    imageFilterHighPassFilterHBoxLayout->addWidget(imageFilterHighPassFilterLaplacianRadioButton);
    imageFilterHighPassFilterHBoxLayout->addWidget(imageFilterHighPassFilterCannyRadioButton);
    connect(imageFilterAddNoiseSaltSlider, SIGNAL(valueChanged(int)), this, SLOT(onImageAddNoiseSaltChanged(int)));
    connect(imageFilterAddNoiseGaussAvgSlider, SIGNAL(valueChanged(int)), this, SLOT(onImageAddNoiseGaussAvgChanged(int)));
    connect(imageFilterAddNoiseGaussStdSlider, SIGNAL(valueChanged(int)), this, SLOT(onImageAddNoiseGaussStdChanged(int)));
    connect(imageFilterLowPassFilterOriginalRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageFilterLowPassRestoreRadioButtonToggle(bool)));
    connect(imageFilterLowPassFilterBlurRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageFilterLowPassBlurRadioButtonToggle(bool)));
    connect(imageFilterLowPassFilterGaussBlurRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageFilterLowPassGaussBlurRadioButtonToggle(bool)));
    connect(imageFilterLowPassFilterMedianBlurRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageFilterLowPassMedianBlurRadioButtonToggle(bool)));
    connect(imageFilterHighPassFilterOriginalRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageFilterHighPassRestoreRadioButtonToggle(bool)));
    connect(imageFilterHighPassFilterSobelRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageFilterHighPassSobelRadioButtonToggle(bool)));
    connect(imageFilterHighPassFilterScharrRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageFilterHighPassScharrRadioButtonToggle(bool)));
    connect(imageFilterHighPassFilterLaplacianRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageFilterHighPassLaplacianRadioButtonToggle(bool)));
    connect(imageFilterHighPassFilterCannyRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageFilterHighPassCannyRadioButtonToggle(bool)));


    /*图像处理第七部分-形态学操作*/
    imageMorphologyGroupBox = new QGroupBox(leftProcessVBoxWidget);
    imageMorphologyGroupBox->setTitle(QString::fromLocal8Bit("图像形态学操作"));
    imageMorphologyHBoxLayout = new QHBoxLayout(imageMorphologyGroupBox);
    leftProcessVBoxLayout->addWidget(imageMorphologyGroupBox);
    imageMorphologyOriginalRadioButton = new QRadioButton(QString::fromLocal8Bit("原图"), imageMorphologyGroupBox);
    imageMorphologyOriginalRadioButton->setChecked(true);
    imageMorphologyAdaptiveMEANRadioButton = new QRadioButton(QString::fromLocal8Bit("二值化"), imageMorphologyGroupBox);
    imageMorphologyOpenRadioButton = new QRadioButton(QString::fromLocal8Bit("开运算"), imageMorphologyGroupBox);
    imageMorphologyCloseRadioButton = new QRadioButton(QString::fromLocal8Bit("闭运算"), imageMorphologyGroupBox);
    imageMorphologyGradientRadioButton = new QRadioButton(QString::fromLocal8Bit("梯度运算"), imageMorphologyGroupBox);
    imageMorphologyTophatRadioButton = new QRadioButton(QString::fromLocal8Bit("顶帽运算"), imageMorphologyGroupBox);
    imageMorphologyBlackhatRadioButton = new QRadioButton(QString::fromLocal8Bit("黑帽运算"), imageMorphologyGroupBox);
    imageMorphologyHitmissRadioButton = new QRadioButton(QString::fromLocal8Bit("击中击不中变换"), imageMorphologyGroupBox);
    imageMorphologyHBoxLayout->addWidget(imageMorphologyOriginalRadioButton);
    imageMorphologyHBoxLayout->addWidget(imageMorphologyAdaptiveMEANRadioButton);
    imageMorphologyHBoxLayout->addWidget(imageMorphologyOpenRadioButton);
    imageMorphologyHBoxLayout->addWidget(imageMorphologyCloseRadioButton);
    imageMorphologyHBoxLayout->addWidget(imageMorphologyGradientRadioButton);
    imageMorphologyHBoxLayout->addWidget(imageMorphologyTophatRadioButton);
    imageMorphologyHBoxLayout->addWidget(imageMorphologyBlackhatRadioButton);
    imageMorphologyHBoxLayout->addWidget(imageMorphologyHitmissRadioButton);
    connect(imageMorphologyOriginalRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageMorphologyOriginalRadioButtonToggle(bool)));
    connect(imageMorphologyAdaptiveMEANRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageMorphologyAdaptiveMEANRadioButtonToggle(bool)));
    connect(imageMorphologyOpenRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageMorphologyOpenRadioButtonToggle(bool)));
    connect(imageMorphologyCloseRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageMorphologyCloseRadioButtonToggle(bool)));
    connect(imageMorphologyGradientRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageMorphologyGradientRadioButtonToggle(bool)));
    connect(imageMorphologyTophatRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageMorphologyTophatRadioButtonToggle(bool)));
    connect(imageMorphologyBlackhatRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageMorphologyBlackhatRadioButtonToggle(bool)));
    connect(imageMorphologyHitmissRadioButton, SIGNAL(toggled(bool)), this, SLOT(onImageMorphologyHitmissRadioButtonToggle(bool)));


    /*右侧图片/视频显示组件*/
    imageShowWidget = new QWidget(rightImageVideoTabWidget);
    videoShowWidget = new QWidget(rightImageVideoTabWidget);
    rightImageVideoTabWidget->addTab(imageShowWidget, QString::fromLocal8Bit("图片"));
    rightImageVideoTabWidget->addTab(videoShowWidget, QString::fromLocal8Bit("视频"));

    /*图片部分（图片显示），从上到下以此为图片显示，图片导入，图片信息显示*/
    imageShowVBoxLayout = new QVBoxLayout(imageShowWidget);
    imageShowLabel = new QLabel(imageShowWidget);
    imageShowLabel->setAlignment(Qt::AlignCenter);
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
    connect(imageSavePushButton, SIGNAL(clicked()), this, SLOT(onImageSavePushButtonClick()));

    /*图片部分（图片信息），顶层为横向布局，从左到右依次是图片像素信息（表单布局）,直方图...*/
    imageInfoHBoxLayout = new QHBoxLayout(imageInfoWidget);
    imageMatInfoWidget = new QWidget(imageInfoWidget);
    imageHistShowLabel = new QLabel(imageInfoWidget);
    imageInfoHBoxLayout->addWidget(imageMatInfoWidget);
    imageInfoHBoxLayout->addWidget(imageHistShowLabel);
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
    videoShowLabel->setAlignment(Qt::AlignCenter);
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

    /*视频部分（视频信息）*/
    videoInfoFormLayout = new QFormLayout(videoInfoWidget);
    videoInfoPosMsecLineEdit = new QLineEdit(videoInfoWidget);
    videoInfoFrameWidthLineEdit = new QLineEdit(videoInfoWidget);
    videoInfoFrameHeightLineEdit = new QLineEdit(videoInfoWidget);
    videoInfoFpsLineEdit = new QLineEdit(videoInfoWidget);
    videoInfoFourccLineEdit = new QLineEdit(videoInfoWidget);
    videoInfoFrameCountLineEdit = new QLineEdit(videoInfoWidget);
    videoInfoFormatLineEdit = new QLineEdit(videoInfoWidget);
    videoInfoBrightnessLineEdit = new QLineEdit(videoInfoWidget);
    videoInfoContrastLineEdit = new QLineEdit(videoInfoWidget);
    videoInfoSaturationLineEdit = new QLineEdit(videoInfoWidget);
    videoInfoHueLineEdit = new QLineEdit(videoInfoWidget);
    videoInfoGainEdit = new QLineEdit(videoInfoWidget);
    videoInfoFormLayout->addRow(QString::fromLocal8Bit("视频文件的当前位置(以毫秒为单位)"), videoInfoPosMsecLineEdit);
    videoInfoFormLayout->addRow(QString::fromLocal8Bit("视频流中图像的宽度"), videoInfoFrameWidthLineEdit);
    videoInfoFormLayout->addRow(QString::fromLocal8Bit("视频流中图像的高度"), videoInfoFrameHeightLineEdit);
    videoInfoFormLayout->addRow(QString::fromLocal8Bit("视频流中图像的帧率(每秒帧数)"), videoInfoFpsLineEdit);
    videoInfoFormLayout->addRow(QString::fromLocal8Bit("编解码器的4字符代码"), videoInfoFourccLineEdit);
    videoInfoFormLayout->addRow(QString::fromLocal8Bit("视频流中图像的帧数"), videoInfoFrameCountLineEdit);
    videoInfoFormLayout->addRow(QString::fromLocal8Bit("返回的Mat对象的格式"), videoInfoFormatLineEdit);
    videoInfoFormLayout->addRow(QString::fromLocal8Bit("图像的亮度(仅适用于支持的相机)"), videoInfoBrightnessLineEdit);
    videoInfoFormLayout->addRow(QString::fromLocal8Bit("图像对比度(仅适用于支持的相机)"), videoInfoContrastLineEdit);
    videoInfoFormLayout->addRow(QString::fromLocal8Bit("图像饱和度(仅适用于相机)"), videoInfoSaturationLineEdit);
    videoInfoFormLayout->addRow(QString::fromLocal8Bit("图像的色调(仅适用于相机)"), videoInfoHueLineEdit);
    videoInfoFormLayout->addRow(QString::fromLocal8Bit("图像的增益(仅适用于支持的相机)"), videoInfoGainEdit);
    videoInfoPosMsecLineEdit->setReadOnly(true);
    videoInfoFrameWidthLineEdit->setReadOnly(true);
    videoInfoFrameHeightLineEdit->setReadOnly(true);
    videoInfoFpsLineEdit->setReadOnly(true);
    videoInfoFourccLineEdit->setReadOnly(true);
    videoInfoFrameCountLineEdit->setReadOnly(true);
    videoInfoFormatLineEdit->setReadOnly(true);
    videoInfoBrightnessLineEdit->setReadOnly(true);
    videoInfoContrastLineEdit->setReadOnly(true);
    videoInfoSaturationLineEdit->setReadOnly(true);
    videoInfoHueLineEdit->setReadOnly(true);
    videoInfoGainEdit->setReadOnly(true);
}

/*****************************************************************
** 函数名: clearGlobalImage()
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 清除当前程序所加载的图片
** 作　者: kete
** 日　期: 2022/4/15
** 说　明: 2022/4/30增加清除直方图
******************************************************************/
void TopWidget::clearGlobalImage()
{
    /*清除显示的图像*/
    imageShowLabel->clear();

    /*清除显示的原始图像路径*/
    imagePathLineEdit->clear();

    /*清除图像信息*/
    imageMatInfoColsLineEdit->clear();
    imageMatInfoRowsLineEdit->clear();
    imageMatInfoElemSizeLineEdit->clear();
    imageMatInfoTotalLineEdit->clear();
    imageMatInfoChannelsLineEdit->clear();

    /*清除直方图*/
    imageHistShowLabel->clear();
}

/*****************************************************************
** 函数名: showCriticalDialog(QString message)
** 输　入: QString message
** 输　出: 无
** 返回值: 无
** 功能描述: 错误信息对话框
** 作　者: kete
** 日　期: 2022/3/15
** 说　明:
******************************************************************/
void TopWidget::showCriticalDialog(QString message)
{
    QMessageBox msg(this);

    msg.setWindowTitle(QString::fromLocal8Bit("错误"));
    msg.setText(message);
    msg.setIcon(QMessageBox::Critical);
    msg.setStandardButtons(QMessageBox::Cancel);

    if(msg.exec() == QMessageBox::Cancel)
    {

    }
}

/*****************************************************************
** 函数名: onImageLoadPushButtonClick()
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 图像载入槽函数，相应图像载入按钮点击
** 作　者: kete
** 日　期: 2022/3/15
** 说　明: 2022/4/5 - 默认导入的图片颜色模式为RGB
******************************************************************/
void TopWidget::onImageLoadPushButtonClick()
{
    QString fileName = QFileDialog::getOpenFileName(imageLoadWidget, tr("Open Image"),".",tr("Image Files (*.png *.jpg *.bmp)"));

    imagePathLineEdit->setText(fileName);

    cvImage = imread(fileName.toLatin1().data());

    qImage = QImage(cvImage.data, cvImage.cols, cvImage.rows, QImage::Format_RGB888);

    imageShowLabel->setPixmap(QPixmap::fromImage(qImage));

    /*add 2022/4/5*/
    imageColorRGBRadioButton->setChecked(true);
    imageSinglePixelProcessOriginalRadioButton->setChecked(true);
    imageColorMode = RGB;

    updateMatInfo(cvImage);
}

/*****************************************************************
** 函数名: onImageSavePushButtonClick()
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 保存图像
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageSavePushButtonClick()
{
    const QPixmap* qPixmapToSave = imageShowLabel->pixmap();

    QImage qImageToSave = qPixmapToSave->toImage();

    QString fileName = QFileDialog::getSaveFileName(imageLoadWidget, tr("Save Image"),".",tr("Image Files (*.png *.jpg *.bmp)"));

    qImageToSave.save(fileName);
}

/*****************************************************************
** 函数名: updateMatInfo()
** 输　入: const Mat& mat
** 输　出: 无
** 返回值: bool
** 功能描述: 更新图片的Mat类属性信息
** 作　者: kete
** 日　期: 2022/3/17
** 说　明: 更新图像基本信息,更新图像直方图
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

        /*显示直方图*/
        Mat cvHist;
        Mat cvHistResize;
        QImage qHist;

        updateMatHist(mat, cvHist);
        cv::resize(cvHist, cvHistResize, Size(round(0.5 * cvImage.cols), round(0.4 * cvImage.rows)));
        qHist = QImage(cvHistResize.data, cvHistResize.cols, cvHistResize.rows, QImage::Format_RGB888);
        imageHistShowLabel->setPixmap(QPixmap::fromImage(qHist));
    }

    return ret;
}

/*****************************************************************
** 函数名: updateMatHist()
** 输　入: const Mat& mat
** 输　出: 无
** 返回值: bool
** 功能描述: 更新直方图
** 作　者: kete
** 日　期: 2022/4/30
** 说　明: 更新图像基本信息,更新图像直方图
******************************************************************/
bool TopWidget::updateMatHist(const Mat& mat, Mat& MatHist)
{
    bool ret = true;

    if( mat.empty() )
    {
        ret = false;
    }
    else
    {
        Mat gray;

        if(mat.channels() != 1)
        {
            cvtColor(mat, gray, COLOR_BGR2GRAY);
        }
        else
        {
            gray = mat;
        }


        /*设置提取直方图的相关变量*/
        Mat hist; //用于存放直方图计算结果
        const int channels[1] = {0};//通道索引
        float inRanges[2] = {0, 255};
        const int bins[1] = {256}; //直方图的维度，其实就是像素灰度值的最大值
        const float* ranges[1] = {inRanges};

        calcHist(&gray, 1, channels, Mat(), hist, 1, bins, ranges); //计算图像直方图;

        /*准备绘制直方图*/
        int hist_w = 512;
        int hist_h = 400;
        int width = 2;
        MatHist = Mat::zeros(hist_h, hist_w, CV_8UC3);

        for(int i = 1; i <= hist.rows; i++)
        {
            rectangle(MatHist, Point(width * (i - 1), hist_h - 1), Point(width * i - 1, hist_h - cvRound(hist.at<float>(i - 1) / 30)), Scalar(255, 255, 255), -1);
        }

        //imshow("histImage", MatHist);
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
            videoInfoPosMsecLineEdit->setText(QString::number(cvVideoCap.get(CAP_PROP_POS_MSEC)));
            videoInfoFrameWidthLineEdit->setText(QString::number(cvVideoCap.get(CAP_PROP_FRAME_WIDTH)));
            videoInfoFrameHeightLineEdit->setText(QString::number(cvVideoCap.get(CAP_PROP_FRAME_HEIGHT)));
            videoInfoFpsLineEdit->setText(QString::number(cvVideoCap.get(CAP_PROP_FPS)));
            videoInfoFourccLineEdit->setText(QString::number(cvVideoCap.get(CAP_PROP_FOURCC)));
            videoInfoFrameCountLineEdit->setText(QString::number(cvVideoCap.get(CAP_PROP_FRAME_COUNT)));
            videoInfoFormatLineEdit->setText(QString::number(cvVideoCap.get(CAP_PROP_FORMAT)));
            videoInfoBrightnessLineEdit->setText(QString::number(cvVideoCap.get(CAP_PROP_BRIGHTNESS)));
            videoInfoContrastLineEdit->setText(QString::number(cvVideoCap.get(CAP_PROP_CONTRAST)));
            videoInfoSaturationLineEdit->setText(QString::number(cvVideoCap.get(CAP_PROP_SATURATION)));
            videoInfoHueLineEdit->setText(QString::number(cvVideoCap.get(CAP_PROP_HUE)));
            videoInfoGainEdit->setText(QString::number(cvVideoCap.get(CAP_PROP_GAIN)));

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
    videoInfoPosMsecLineEdit->clear();
    videoInfoFrameWidthLineEdit->clear();
    videoInfoFrameHeightLineEdit->clear();
    videoInfoFpsLineEdit->clear();
    videoInfoFourccLineEdit->clear();
    videoInfoFrameCountLineEdit->clear();
    videoInfoFormatLineEdit->clear();
    videoInfoBrightnessLineEdit->clear();
    videoInfoContrastLineEdit->clear();
    videoInfoSaturationLineEdit->clear();
    videoInfoHueLineEdit->clear();
    videoInfoGainEdit->clear();
}

/*****************************************************************
** 函数名: onImageColorRGBRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: RGB所对应的RadioButton状态发生改变时槽函数（转变图像颜色模式）
** 作　者: kete
** 日　期: 2022/4/3
** 说　明: QRadioButton中,Toggled()信号是在RadioButton状态（开\关）切换时
**        发出的，而clicked()信号是每次点击RadioButton都会发出该信号，实际使
**        用时，一般状态改变时才有必要去响应，因此Toggled()信号更适合状态监控。
******************************************************************/
void TopWidget::onImageColorRGBRadioButtonToggle(bool status)
{
    if(status == true && imageColorMode != RGB && !cvImage.empty())
    {
        imageShowLabel->setPixmap(QPixmap::fromImage(qImage));
        imageColorMode = RGB;
        updateMatInfo(cvImage);
    }
}

/*****************************************************************
** 函数名: onImageColorYUVRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: YUV所对应的RadioButton状态发生改变时槽函数（转变图像颜色模式）
** 作　者: kete
** 日　期: 2022/4/3
** 说　明: QRadioButton中,Toggled()信号是在RadioButton状态（开\关）切换时
**        发出的，而clicked()信号是每次点击RadioButton都会发出该信号，实际使
**        用时，一般状态改变时才有必要去响应，因此Toggled()信号更适合状态监控。
**
**        由于在QT中是没法直接显示yuv数据,因此咱们必须把yuv数据转换成RGB32
**        经过QImage来显示到控件中
******************************************************************/
void TopWidget::onImageColorYUVRadioButtonToggle(bool status)
{
    if(status == true && imageColorMode != YUV && !cvImage.empty())
    {
        Mat cvImageYUV;
        QImage qImageYUV;

        cvtColor(cvImage, cvImageYUV, COLOR_BGR2YUV);
        qImageYUV = QImage(cvImageYUV.data, cvImageYUV.cols, cvImageYUV.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageYUV));
        imageShowLabel->setAlignment(Qt::AlignCenter);
        imageColorMode = YUV;
        updateMatInfo(cvImageYUV);

        //imshow("YUV", cvImageYUV);
    }
}

/*****************************************************************
** 函数名: onImageColorHSVRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: HSV所对应的RadioButton状态发生改变时槽函数（转变图像颜色模式）
** 作　者: kete
** 日　期: 2022/4/3
** 说　明: QRadioButton中,Toggled()信号是在RadioButton状态（开\关）切换时
**        发出的，而clicked()信号是每次点击RadioButton都会发出该信号，实际使
**        用时，一般状态改变时才有必要去响应，因此Toggled()信号更适合状态监控。
******************************************************************/
void TopWidget::onImageColorHSVRadioButtonToggle(bool status)
{
    if(status == true && imageColorMode != HSV && !cvImage.empty())
    {
        Mat cvImageHSV;
        QImage qImageHSV;

        cvtColor(cvImage, cvImageHSV, COLOR_BGR2HSV);
        qImageHSV = QImage(cvImageHSV.data, cvImageHSV.cols, cvImageHSV.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageHSV));
        imageColorMode = HSV;
        updateMatInfo(cvImageHSV);

        //imshow("HSV", cvImageHSV);
    }
}

/*****************************************************************
** 函数名: onImageColorLabRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: Lab所对应的RadioButton状态发生改变时槽函数（转变图像颜色模式）
** 作　者: kete
** 日　期: 2022/4/3
** 说　明: QRadioButton中,Toggled()信号是在RadioButton状态（开\关）切换时
**        发出的，而clicked()信号是每次点击RadioButton都会发出该信号，实际使
**        用时，一般状态改变时才有必要去响应，因此Toggled()信号更适合状态监控。
******************************************************************/
void TopWidget::onImageColorLabRadioButtonToggle(bool status)
{
    if(status == true && imageColorMode != Lab && !cvImage.empty())
    {
        Mat cvImageLab;
        QImage qImageLab;

        cvtColor(cvImage, cvImageLab, COLOR_BGR2Lab);
        qImageLab = QImage(cvImageLab.data, cvImageLab.cols, cvImageLab.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageLab));
        imageColorMode = Lab;
        updateMatInfo(cvImageLab);

        //imshow("Lab", cvImageLab);
    }
}

/*****************************************************************
** 函数名: onImageColorGRAYRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: GRAY所对应的RadioButton状态发生改变时槽函数（转变图像颜色模式）
** 作　者: kete
** 日　期: 2022/4/3
** 说　明: QRadioButton中,Toggled()信号是在RadioButton状态（开\关）切换时
**        发出的，而clicked()信号是每次点击RadioButton都会发出该信号，实际使
**        用时，一般状态改变时才有必要去响应，因此Toggled()信号更适合状态监控。
******************************************************************/
void TopWidget::onImageColorGRAYRadioButtonToggle(bool status)
{
    if(status == true && imageColorMode != GRAY && !cvImage.empty())
    {
        Mat cvImageGRAY;
        QImage qImageGRAY;

        cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        qImageGRAY = QImage(cvImageGRAY.data, cvImageGRAY.cols, cvImageGRAY.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageGRAY));
        imageColorMode = GRAY;
        updateMatInfo(cvImageGRAY);

        //imshow("gray", cvImageGRAY);
    }
}

/*****************************************************************
** 函数名: onImageColorSplitPushButtonClick
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 颜色分离
** 作　者: kete
** 日　期: 2022/4/3
** 说　明: 基于原始RGB图像
******************************************************************/
void TopWidget::onImageColorSplitPushButtonClick()
{
    Mat img_split[3];
    Mat img_b, img_g, img_r;
    Mat img_b_merge[3], img_g_merge[3], img_r_merge[3];
    Mat zero = Mat::zeros(cvImage.rows, cvImage.cols, CV_8UC1);

    if( !cvImage.empty() )
    {
        /*分离*/
        split(cvImage, img_split);

        /*合并B通道*/
        img_b_merge[0] = img_split[0];
        img_b_merge[1] = zero;
        img_b_merge[2] = zero;
        merge(img_b_merge, 3, img_b);
        imshow("RGB-B通道", img_b);

        /*合并G通道*/
        img_g_merge[0] = zero;
        img_g_merge[1] = img_split[1];
        img_g_merge[2] = zero;
        merge(img_g_merge, 3, img_g);
        imshow("RGB-G通道", img_g);

        /*合并R通道*/
        img_r_merge[0] = zero;
        img_r_merge[1] = zero;
        img_r_merge[2] = img_split[2];
        merge(img_r_merge, 3, img_r);
        imshow("RGB-R通道", img_r);
    }
}

/*****************************************************************
** 函数名: onImageSinglePixelProcessOriginalRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 在单图像的像素操作中恢复原始图像
** 作　者: kete
** 日　期: 2022/4/14
** 说　明:
******************************************************************/
void TopWidget::onImageSinglePixelProcessOriginalRadioButtonToggle(bool status)
{
    if(status == true && !cvImage.empty())
    {
        imageShowLabel->setPixmap(QPixmap::fromImage(qImage));
        updateMatInfo(cvImage);
    }
}

/*****************************************************************
** 函数名: onImageSinglePixelProcessNotRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 单图像像素求非
** 作　者: kete
** 日　期: 2022/4/14
** 说　明:
******************************************************************/
void TopWidget::onImageSinglePixelProcessNotRadioButtonToggle(bool status)
{
    if(status == true && !cvImage.empty())
    {
        Mat cvImageNot;
        QImage qImageNot;

        bitwise_not(cvImage, cvImageNot);
        qImageNot = QImage(cvImageNot.data, cvImageNot.cols, cvImageNot.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageNot));
        updateMatInfo(cvImageNot);
    }
}

/*****************************************************************
** 函数名: onImageSinglePixelProcessNotRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 图像二值化（基于自动寻求全局阈值的大津法）
** 作　者: kete
** 日　期: 2022/4/14
** 说　明: 必须先将原始的RGB图像转换为灰度图才能二值化，否则运行会奔溃
******************************************************************/
void TopWidget::onImageSinglePixelProcessThresholdOTSURadioButtonToggle(bool status)
{
    if(status == true && !cvImage.empty())
    {
        Mat cvImageGRAY;
        Mat cvImageThresholdOTSU;
        QImage qImageThresholdOTSU;

        cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        threshold(cvImageGRAY, cvImageThresholdOTSU, 100, 255, THRESH_BINARY | THRESH_OTSU);
        qImageThresholdOTSU = QImage(cvImageThresholdOTSU.data, cvImageThresholdOTSU.cols, cvImageThresholdOTSU.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageThresholdOTSU));
        updateMatInfo(cvImageThresholdOTSU);
    }
}

/*****************************************************************
** 函数名: onImageSinglePixelProcessThresholdTRIANGLERadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 图像二值化（基于自动寻求全局阈值的三角形法）
** 作　者: kete
** 日　期: 2022/4/14
** 说　明: 必须先将原始的RGB图像转换为灰度图才能二值化，否则运行会奔溃
******************************************************************/
void TopWidget::onImageSinglePixelProcessThresholdTRIANGLERadioButtonToggle(bool status)
{
    if(status == true && !cvImage.empty())
    {
        Mat cvImageGRAY;
        Mat cvImageThresholdTRIANGLE;
        QImage qImageThresholdTRIANGLE;

        cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        threshold(cvImageGRAY, cvImageThresholdTRIANGLE, 100, 255, THRESH_BINARY | THRESH_TRIANGLE);
        qImageThresholdTRIANGLE = QImage(cvImageThresholdTRIANGLE.data, cvImageThresholdTRIANGLE.cols, cvImageThresholdTRIANGLE.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageThresholdTRIANGLE));
        updateMatInfo(cvImageThresholdTRIANGLE);
    }
}

/*****************************************************************
** 函数名: onImageSinglePixelProcessAdaptiveThresholdMEANRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 图像二值化（基于局部自适应的均值法）
** 作　者: kete
** 日　期: 2022/4/14
** 说　明: 必须先将原始的RGB图像转换为灰度图才能二值化，否则运行会奔溃
******************************************************************/
void TopWidget::onImageSinglePixelProcessAdaptiveThresholdMEANRadioButtonToggle(bool status)
{
    if(status == true && !cvImage.empty())
    {
        Mat cvImageGRAY;
        Mat cvImageAdaptiveThresholdMEAN;
        QImage qImageAdaptiveThresholdMEAN;

        cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        adaptiveThreshold(cvImageGRAY, cvImageAdaptiveThresholdMEAN, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);
        qImageAdaptiveThresholdMEAN = QImage(cvImageAdaptiveThresholdMEAN.data, cvImageAdaptiveThresholdMEAN.cols, cvImageAdaptiveThresholdMEAN.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageAdaptiveThresholdMEAN));
        updateMatInfo(cvImageAdaptiveThresholdMEAN);
    }
}

/*****************************************************************
** 函数名: onImageSinglePixelProcessAdaptiveThresholdGAUSSIANRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 图像二值化（基于局部自适应的高斯法）
** 作　者: kete
** 日　期: 2022/4/14
** 说　明: 必须先将原始的RGB图像转换为灰度图才能二值化，否则运行会奔溃
******************************************************************/
void TopWidget::onImageSinglePixelProcessAdaptiveThresholdGAUSSIANRadioButtonToggle(bool status)
{
    if(status == true && !cvImage.empty())
    {
        Mat cvImageGRAY;
        Mat cvImageAdaptiveThresholdGUASSIAN;
        QImage qImageAdaptiveThresholdGUASSIAN;

        cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        adaptiveThreshold(cvImageGRAY, cvImageAdaptiveThresholdGUASSIAN, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 55, 0);
        qImageAdaptiveThresholdGUASSIAN = QImage(cvImageAdaptiveThresholdGUASSIAN.data, cvImageAdaptiveThresholdGUASSIAN.cols, cvImageAdaptiveThresholdGUASSIAN.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageAdaptiveThresholdGUASSIAN));
        updateMatInfo(cvImageAdaptiveThresholdGUASSIAN);
    }
}

/*****************************************************************
** 函数名: onImagePairPixelProcessLoadImage1PushButtonClick
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 两图像间的像素操作加载第一张图像
** 作　者: kete
** 日　期: 2022/4/15
** 说　明:
******************************************************************/
void TopWidget::onImagePairPixelProcessLoadImage1PushButtonClick()
{
    QString fileName = QFileDialog::getOpenFileName(imagePairPixelProcessGroupBox, tr("Open Image"),".",tr("Image Files (*.png *.jpg *.bmp)"));

    imagePairPixelProcessLoadImage1PathLineEdit->setText(fileName);

    cvImagePairCal1 = imread(fileName.toLatin1().data());

    imshow("First Image", cvImagePairCal1);
}

/*****************************************************************
** 函数名: onImagePairPixelProcessLoadImage2PushButtonClick
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 两图像间的像素操作加载第二张图像
** 作　者: kete
** 日　期: 2022/4/15
** 说　明:
******************************************************************/
void TopWidget::onImagePairPixelProcessLoadImage2PushButtonClick()
{
    QString fileName = QFileDialog::getOpenFileName(imagePairPixelProcessGroupBox, tr("Open Image"),".",tr("Image Files (*.png *.jpg *.bmp)"));

    imagePairPixelProcessLoadImage2PathLineEdit->setText(fileName);

    cvImagePairCal2 = imread(fileName.toLatin1().data());

    imshow("Second Image", cvImagePairCal2);
}

/*****************************************************************
** 函数名: isImagePairPixelProcessCal
** 输　入: const Mat& Mat1：图像1
**        const Mat& Mat2：图像2
** 输　出: 无
** 返回值: bool
** 功能描述: 判断两幅图像间是否可以进行像素运算
** 作　者: kete
** 日　期: 2022/4/15
** 说　明:
******************************************************************/
bool TopWidget::isImagePairPixelProcessCal(const Mat& Mat1, const Mat& Mat2)
{
    bool ret = true;

    if( Mat1.empty() )
    {
        showCriticalDialog(QString::fromLocal8Bit("图像1未加载"));

        ret = false;
    }
    else if( Mat2.empty() )
    {
        showCriticalDialog(QString::fromLocal8Bit("图像2未加载"));

        ret = false;
    }
    else if( Mat1.cols != Mat2.cols )
    {
        showCriticalDialog(QString::fromLocal8Bit("图像1的像素列数与图像2的像素列数不相等，无法进行图像间像素运算"));

        ret = false;
    }
    else if( Mat1.rows != Mat2.rows )
    {
        showCriticalDialog(QString::fromLocal8Bit("图像1的像素行数与图像2的像素行数不相等，无法进行图像间像素运算"));

        ret = false;
    }
    else if( Mat1.channels() != Mat2.channels() )
    {
        showCriticalDialog(QString::fromLocal8Bit("图像1的通道数与图像2的通道数不相等，无法进行图像间像素运算"));

        ret = false;
    }

    return ret;
}

/*****************************************************************
** 函数名: onImagePairPixelProcessCLRRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 清楚显示的图像（用于两图像间的像素操作部分）
** 作　者: kete
** 日　期: 2022/4/15
** 说　明:
******************************************************************/
void TopWidget::onImagePairPixelProcessCLRRadioButtonToggle(bool status)
{
    clearGlobalImage();
}

/*****************************************************************
** 函数名: onImagePairPixelProcessMAXRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 比较两幅图像中每一个元素灰度值的大小，保留较大的灰度值
** 作　者: kete
** 日　期: 2022/4/15
** 说　明:
******************************************************************/
void TopWidget::onImagePairPixelProcessMAXRadioButtonToggle(bool status)
{
    if( status == true && isImagePairPixelProcessCal(cvImagePairCal1, cvImagePairCal2) )
    {
        clearGlobalImage();
        max(cvImagePairCal1, cvImagePairCal2, cvImage);
        qImage = QImage(cvImage.data, cvImage.cols, cvImage.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImage));
        updateMatInfo(cvImage);
    }
}

/*****************************************************************
** 函数名: onImagePairPixelProcessMINRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 比较两幅图像中每一个元素灰度值的大小，保留较小的灰度值
** 作　者: kete
** 日　期: 2022/4/15
** 说　明:
******************************************************************/
void TopWidget::onImagePairPixelProcessMINRadioButtonToggle(bool status)
{
    if( status == true && isImagePairPixelProcessCal(cvImagePairCal1, cvImagePairCal2) )
    {
        clearGlobalImage();
        min(cvImagePairCal1, cvImagePairCal2, cvImage);
        qImage = QImage(cvImage.data, cvImage.cols, cvImage.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImage));
        updateMatInfo(cvImage);
    }
}

/*****************************************************************
** 函数名: onImagePairPixelProcessANDRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 两幅图像的像素求“与”运算
** 作　者: kete
** 日　期: 2022/4/15
** 说　明:
******************************************************************/
void TopWidget::onImagePairPixelProcessANDRadioButtonToggle(bool status)
{
    if( status == true && isImagePairPixelProcessCal(cvImagePairCal1, cvImagePairCal2) )
    {
        clearGlobalImage();
        bitwise_and(cvImagePairCal1, cvImagePairCal2, cvImage);
        qImage = QImage(cvImage.data, cvImage.cols, cvImage.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImage));
        updateMatInfo(cvImage);
    }
}

/*****************************************************************
** 函数名: onImagePairPixelProcessANDRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 两幅图像的像素求“或”运算
** 作　者: kete
** 日　期: 2022/4/15
** 说　明:
******************************************************************/
void TopWidget::onImagePairPixelProcessORRadioButtonToggle(bool status)
{
    if( status == true && isImagePairPixelProcessCal(cvImagePairCal1, cvImagePairCal2) )
    {
        clearGlobalImage();
        bitwise_or(cvImagePairCal1, cvImagePairCal2, cvImage);
        qImage = QImage(cvImage.data, cvImage.cols, cvImage.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImage));
        updateMatInfo(cvImage);
    }
}

/*****************************************************************
** 函数名: onImagePairPixelProcessXORRadioButtonToggle
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 两幅图像的像素求“异或”运算
** 作　者: kete
** 日　期: 2022/4/15
** 说　明:
******************************************************************/
void TopWidget::onImagePairPixelProcessXORRadioButtonToggle(bool status)
{
    if( status == true && isImagePairPixelProcessCal(cvImagePairCal1, cvImagePairCal2) )
    {
        clearGlobalImage();
        bitwise_xor(cvImagePairCal1, cvImagePairCal2, cvImage);
        qImage = QImage(cvImage.data, cvImage.cols, cvImage.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImage));
        updateMatInfo(cvImage);
    }
}

/*****************************************************************
** 函数名: onImageZoomValueChanged
** 输　入: int value
** 输　出: 无
** 返回值: 无
** 功能描述: 图像缩放
** 作　者: kete
** 日　期: 2022/4/25
** 说　明: 最小缩短为原图像的1/2,最大放大为原图像的2倍
******************************************************************/
void TopWidget::onImageZoomValueChanged(int value)
{
    Mat cvImageZoom;
    QImage qImageZoom;
    double ratio = 0;
    double dvalue = static_cast<double>(value);

    if(qImage.isNull())
    {
        showCriticalDialog(QString::fromLocal8Bit("请先载入图片"));
    }
    else
    {
        if(value <= 50 )
        {
            ratio = 0.01 * dvalue + 0.5;
        }
        else
        {
            ratio = 0.02 * dvalue;
        }

        imageZoomValueLabel->setNum(ratio);
        cv::resize(cvImage, cvImageZoom, Size(round(ratio * cvImage.cols), round(ratio * cvImage.rows)));
        qImageZoom = QImage(cvImageZoom.data, cvImageZoom.cols, cvImageZoom.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageZoom));
        updateMatInfo(cvImageZoom);
    }
}

/*****************************************************************
** 函数名: onImageRotateValueChanged
** 输　入: int value
** 输　出: 无
** 返回值: 无
** 功能描述: 图像旋转
** 作　者: kete
** 日　期: 2022/4/25
** 说　明: 使用Qt自身的机制进行旋转，旋转完成后将新生成的QImage转为Mat
******************************************************************/
void TopWidget::onImageRotateValueChanged(int value)
{
    Mat cvImageRotate;
    QImage qImageRotate;
    QMatrix qmatrix;

    if(qImage.isNull())
    {
        showCriticalDialog(QString::fromLocal8Bit("请先载入图片"));
    }
    else
    {
        qmatrix.rotate(value);
        qImageRotate = qImage.transformed(qmatrix,Qt::FastTransformation);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageRotate));
        imageRotateValueLabel->setNum(value);
        cvImageRotate = Mat(qImageRotate.height(), qImageRotate.width(), CV_8UC3, (void*)qImageRotate.constBits(), qImageRotate.bytesPerLine());
        updateMatInfo(cvImageRotate);
    }
}

/*****************************************************************
** 函数名: onImageHistApplyRestoreRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 恢复原始图像
** 作　者: kete
** 日　期: 2022/5/1
** 说　明:
******************************************************************/
void TopWidget::onImageHistApplyRestoreRadioButtonToggle(bool status)
{
    if(status == true && !cvImage.empty())
    {
        imageShowLabel->setPixmap(QPixmap::fromImage(qImage));
        updateMatInfo(cvImage);
    }
}

/*****************************************************************
** 函数名: onImageHistApplyGrayRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 将图像变为灰度图
** 作　者: kete
** 日　期: 2022/5/1
** 说　明:
******************************************************************/
void TopWidget::onImageHistApplyGrayRadioButtonToggle(bool status)
{
    if(status == true && !cvImage.empty())
    {
        Mat cvImageGRAY;
        QImage qImageGRAY;

        if(cvImage.channels() != 1)
        {
            cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        }
        else
        {
            cvImageGRAY = cvImage;
        }

        qImageGRAY = QImage(cvImageGRAY.data, cvImageGRAY.cols, cvImageGRAY.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageGRAY));
        imageColorMode = GRAY;
        updateMatInfo(cvImageGRAY);
    }
}

/*****************************************************************
** 函数名: onImageHistApplyGrayRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 灰度图均衡化后显示
** 作　者: kete
** 日　期: 2022/5/1
** 说　明:
******************************************************************/
void TopWidget::onImageHistApplyEqualizeRadioButtonToggle(bool status)
{
    if(status == true && !cvImage.empty())
    {
        Mat cvImageGRAY, cvImageEqualize;
        QImage qImageEqualize;

        if(cvImage.channels() != 1)
        {
            cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        }
        else
        {
            cvImageGRAY = cvImage;
        }

        equalizeHist(cvImageGRAY, cvImageEqualize);

        qImageEqualize = QImage(cvImageEqualize.data, cvImageEqualize.cols, cvImageEqualize.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageEqualize));
        updateMatInfo(cvImageEqualize);
    }
}

/*****************************************************************
** 函数名: onImageHistApplyTemplateLoadPushButtonClick
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 载入模板用于匹配
** 作　者: kete
** 日　期: 2022/5/1
** 说　明: 直方图应用
******************************************************************/
void TopWidget::onImageHistApplyTemplateLoadPushButtonClick()
{
    QString fileName = QFileDialog::getOpenFileName(imageLoadWidget, tr("Open Image"),".",tr("Image Files (*.png *.jpg *.bmp)"));

    cvImageTemplate = imread(fileName.toLatin1().data());

    imageHistApplyTemplateMatchPathLineEdit->setText(fileName);

    imshow("HistTemplate", cvImageTemplate);
}

/*****************************************************************
** 函数名: onImageHistApplyTemplateMatchPushButtonClick
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 匹配模板
** 作　者: kete
** 日　期: 2022/5/1
** 说　明: 直方图应用
******************************************************************/
void TopWidget::onImageHistApplyTemplateMatchPushButtonClick()
{
    if(!cvImage.empty())
    {
        if(cvImageTemplate.empty())
        {
            showCriticalDialog(QString::fromLocal8Bit("请先载入匹配模板"));
        }
        else
        {
            Mat cvImageTemplateMatchResult;
            QImage qImageTemplateMatchResult;

            matchTemplate(cvImage, cvImageTemplate, cvImageTemplateMatchResult, TM_CCOEFF_NORMED);

            double maxVal, minVal;
            Point minLoc, maxLoc;

            //寻找匹配结果中的最大值和最小值以及坐标位置
            minMaxLoc(cvImageTemplateMatchResult, &minVal, &maxVal, &minLoc, &maxLoc);

            //绘制最佳匹配区域
            rectangle(cvImage, cv::Rect(maxLoc.x, maxLoc.y, cvImageTemplate.cols, cvImageTemplate.rows), Scalar(0, 0, 255), 2);

            qImage = QImage(cvImage.data, cvImage.cols, cvImage.rows, QImage::Format_RGB888);
            imageShowLabel->setPixmap(QPixmap::fromImage(qImage));
            updateMatInfo(cvImage);
        }
    }
}

/*****************************************************************
** 函数名: onImageAddNoiseSaltChanged(int value)
** 输　入: int value : 椒盐噪点数量
** 输　出: 无
** 返回值: 无
** 功能描述: 给图像加椒盐噪声
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageAddNoiseSaltChanged(int value)
{
    if(!cvImage.empty())
    {
        Mat cvImageNoiseSalt = cvImage.clone();//深拷贝
        QImage qImageNoiseSalt;

        imageFilterAddNoiseSaltValueLabel->setNum(value);

        for(int k = 0; k < value; k++)
        {
            /*随机确定图像中位置*/
            int i = qrand() % cvImageNoiseSalt.cols;//取余数计算，保证在图像的列数内
            int j = qrand() % cvImageNoiseSalt.rows;//取余数计算，保证在图像的行数内
            int write_black = qrand() % 2; //判断是白色噪声还是黑色噪声的变量

            if(write_black == 0)//添加白色噪声
            {
                if( cvImageNoiseSalt.type() == CV_8UC1 )//处理灰度图像
                {
                    cvImageNoiseSalt.at<uchar>(j, i) = 255; //白色噪音
                }
                else if( cvImageNoiseSalt.type() == CV_8UC3 )//处理彩色图像
                {
                    cvImageNoiseSalt.at<Vec3b>(j, i)[0] = 255;
                    cvImageNoiseSalt.at<Vec3b>(j, i)[1] = 255;
                    cvImageNoiseSalt.at<Vec3b>(j, i)[2] = 255;
                }
            }
            else //添加黑色噪声
            {
                if( cvImageNoiseSalt.type() == CV_8UC1 )//处理灰度图像
                {
                    cvImageNoiseSalt.at<uchar>(j, i) = 0; //黑噪音
                }
                else if( cvImageNoiseSalt.type() == CV_8UC3 )//处理彩色图像
                {
                    cvImageNoiseSalt.at<Vec3b>(j, i)[0] = 0;
                    cvImageNoiseSalt.at<Vec3b>(j, i)[1] = 0;
                    cvImageNoiseSalt.at<Vec3b>(j, i)[2] = 0;
                }
            }
        }

        qImageNoiseSalt = QImage(cvImageNoiseSalt.data, cvImageNoiseSalt.cols, cvImageNoiseSalt.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageNoiseSalt));
        updateMatInfo(cvImageNoiseSalt);
    }
}

/*****************************************************************
** 函数名: onImageAddNoiseGaussAvgChanged(int value)
** 输　入: int value : 高斯噪音均值
** 输　出: 无
** 返回值: 无
** 功能描述: 图像加噪
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageAddNoiseGaussAvgChanged(int value)
{
    if(!cvImage.empty())
    {
        Mat cvImageNoiseGauss = cvImage.clone();//深拷贝
        Mat cvImageNoiseGauss_noise = Mat::zeros(cvImage.rows, cvImage.cols, cvImage.type());//单纯生成噪音，还要与原图像叠加
        QImage qImageNoiseGauss;

        imageFilterAddNoiseSaltSlider->setValue(0);
        imageFilterAddNoiseGaussAvgValueLabel->setNum(value);

        RNG rng; //创建一个RNG类
        rng.fill(cvImageNoiseGauss_noise, RNG::NORMAL, value, imageFilterAddNoiseGaussStdSlider->value());

        cvImageNoiseGauss = cvImageNoiseGauss + cvImageNoiseGauss_noise;//叠加高斯噪声

        qImageNoiseGauss = QImage(cvImageNoiseGauss.data, cvImageNoiseGauss.cols, cvImageNoiseGauss.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageNoiseGauss));
        updateMatInfo(cvImageNoiseGauss);
    }
}

/*****************************************************************
** 函数名: onImageAddNoiseGaussAvgChanged(int value)
** 输　入: int value : 高斯噪音均值
** 输　出: 无
** 返回值: 无
** 功能描述: 图像加噪
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageAddNoiseGaussStdChanged(int value)
{
    if(!cvImage.empty())
    {
        Mat cvImageNoiseGauss = cvImage.clone();//深拷贝
        Mat cvImageNoiseGauss_noise = Mat::zeros(cvImage.rows, cvImage.cols, cvImage.type());//单纯生成噪音，还要与原图像叠加
        QImage qImageNoiseGauss;

        imageFilterAddNoiseSaltSlider->setValue(0);
        imageFilterAddNoiseGaussStdValueLabel->setNum(value);

        RNG rng; //创建一个RNG类
        rng.fill(cvImageNoiseGauss_noise, RNG::NORMAL, imageFilterAddNoiseGaussAvgSlider->value(), value);

        cvImageNoiseGauss = cvImageNoiseGauss + cvImageNoiseGauss_noise;//叠加高斯噪声

        qImageNoiseGauss = QImage(cvImageNoiseGauss.data, cvImageNoiseGauss.cols, cvImageNoiseGauss.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageNoiseGauss));
        updateMatInfo(cvImageNoiseGauss);
    }
}

/*****************************************************************
** 函数名: onImageFilterLowPassRestoreRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 显示原始图像
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageFilterLowPassRestoreRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        imageShowLabel->setPixmap(QPixmap::fromImage(qImage));
        updateMatInfo(cvImage);
    }
}

/*****************************************************************
** 函数名: onImageFilterLowPassBlurRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 显示均值滤波后的图像
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageFilterLowPassBlurRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageBlur;
        QImage qImageBlur;

        blur(cvImage, cvImageBlur, Size(3, 3));

        qImageBlur = QImage(cvImageBlur.data, cvImageBlur.cols, cvImageBlur.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageBlur));
        updateMatInfo(cvImageBlur);
    }
}

/*****************************************************************
** 函数名: onImageFilterLowPassGaussBlurRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 显示高斯滤波后的图像
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageFilterLowPassGaussBlurRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageGaussBlur;
        QImage qImageGaussBlur;

        GaussianBlur(cvImage, cvImageGaussBlur, Size(5, 5), 10, 20);

        qImageGaussBlur = QImage(cvImageGaussBlur.data, cvImageGaussBlur.cols, cvImageGaussBlur.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageGaussBlur));
        updateMatInfo(cvImageGaussBlur);
    }
}

/*****************************************************************
** 函数名: onImageFilterLowPassGaussBlurRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 显示中值滤波后的图像
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageFilterLowPassMedianBlurRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageMedianBlur;
        QImage qImageMedianBlur;

        medianBlur(cvImage, cvImageMedianBlur, 9);

        qImageMedianBlur = QImage(cvImageMedianBlur.data, cvImageMedianBlur.cols, cvImageMedianBlur.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageMedianBlur));
        updateMatInfo(cvImageMedianBlur);
    }
}

/*****************************************************************
** 函数名: onImageFilterHighPassRestoreRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 显示原始图像
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageFilterHighPassRestoreRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        imageShowLabel->setPixmap(QPixmap::fromImage(qImage));
        updateMatInfo(cvImage);
    }
}

/*****************************************************************
** 函数名: onImageFilterHighPassSobelRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 显示用Sobel算子后的边缘检测图像
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageFilterHighPassSobelRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageResultX, cvImageResultY, cvImageResultXY;
        QImage qImageResultXY;

        /*X方向一阶边缘*/
        Sobel(cvImage, cvImageResultX, CV_16S, 1, 0, 1);
        convertScaleAbs(cvImageResultX, cvImageResultX);

        /*Y方向一阶边缘*/
        Sobel(cvImage, cvImageResultY, CV_16S, 0, 1, 1);
        convertScaleAbs(cvImageResultY, cvImageResultY);

        /*整幅图像的一阶边缘*/
        cvImageResultXY = cvImageResultX + cvImageResultY;

        /*显示图像*/
        qImageResultXY = QImage(cvImageResultXY.data, cvImageResultXY.cols, cvImageResultXY.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageResultXY));
        updateMatInfo(cvImageResultXY);
    }
}

/*****************************************************************
** 函数名: onImageFilterHighPassScharrRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 显示用Scharr算子后的边缘检测图像
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageFilterHighPassScharrRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageResultX, cvImageResultY, cvImageResultXY;
        QImage qImageResultXY;

        /*X方向一阶边缘*/
        Scharr(cvImage, cvImageResultX, CV_16S, 1, 0);
        convertScaleAbs(cvImageResultX, cvImageResultX);

        /*Y方向一阶边缘*/
        Scharr(cvImage, cvImageResultY, CV_16S, 0, 1);
        convertScaleAbs(cvImageResultY, cvImageResultY);

        /*整幅图像的一阶边缘*/
        cvImageResultXY = cvImageResultX + cvImageResultY;

        /*显示图像*/
        qImageResultXY = QImage(cvImageResultXY.data, cvImageResultXY.cols, cvImageResultXY.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageResultXY));
        updateMatInfo(cvImageResultXY);
    }
}

/*****************************************************************
** 函数名: onImageFilterHighPassLaplacianRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 显示用Laplacian算子后的边缘检测图像
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageFilterHighPassLaplacianRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageResult;
        QImage qImageResult;

        Laplacian(cvImage, cvImageResult, -1);

        /*显示图像*/
        qImageResult = QImage(cvImageResult.data, cvImageResult.cols, cvImageResult.rows, QImage::Format_RGB888);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageResult));
        updateMatInfo(cvImageResult);
    }
}

/*****************************************************************
** 函数名: onImageFilterHighPassCannyRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 显示用Canny算法后的边缘检测图像
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageFilterHighPassCannyRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageResultHigh;
        QImage qImageResultHigh;

        if(cvImage.type() != CV_8U)
        {
            showCriticalDialog(QString::fromLocal8Bit("图像类型必须为CV_8U"));
        }
        else
        {
            /*高阈值检测图像边缘*/
            Canny(cvImage, cvImageResultHigh, 100, 200, 3);

            /*显示图像*/
            qImageResultHigh = QImage(cvImageResultHigh.data, cvImageResultHigh.cols, cvImageResultHigh.rows, QImage::Format_RGB888);
            imageShowLabel->setPixmap(QPixmap::fromImage(qImageResultHigh));
            updateMatInfo(cvImageResultHigh);
        }
    }
}

/*****************************************************************
** 函数名: onImageMorphologyOriginalRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 显示原图
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageMorphologyOriginalRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        imageShowLabel->setPixmap(QPixmap::fromImage(qImage));
        updateMatInfo(cvImage);
    }
}

/*****************************************************************
** 函数名: onImageMorphologyAdaptiveMEANRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 对原图进行二值化
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageMorphologyAdaptiveMEANRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageGRAY;
        Mat cvImageAdaptiveThresholdMEAN;
        QImage qImageAdaptiveThresholdMEAN;

        cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        adaptiveThreshold(cvImageGRAY, cvImageAdaptiveThresholdMEAN, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);
        qImageAdaptiveThresholdMEAN = QImage(cvImageAdaptiveThresholdMEAN.data, cvImageAdaptiveThresholdMEAN.cols, cvImageAdaptiveThresholdMEAN.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageAdaptiveThresholdMEAN));
        updateMatInfo(cvImageAdaptiveThresholdMEAN);
    }
}

/*****************************************************************
** 函数名: onImageMorphologyOpenRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 形态学开运算
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageMorphologyOpenRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageGRAY;
        Mat cvImageAdaptiveThresholdMEAN;
        Mat cvImageMorphologyOpen;
        Mat kernel = getStructuringElement(0, Size(3, 3));
        QImage qImageMorphologyOpen;

        cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        adaptiveThreshold(cvImageGRAY, cvImageAdaptiveThresholdMEAN, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);

        morphologyEx(cvImageAdaptiveThresholdMEAN, cvImageMorphologyOpen, MORPH_OPEN, kernel);

        qImageMorphologyOpen = QImage(cvImageMorphologyOpen.data, cvImageMorphologyOpen.cols, cvImageMorphologyOpen.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageMorphologyOpen));
        updateMatInfo(cvImageMorphologyOpen);
    }
}

/*****************************************************************
** 函数名: onImageMorphologyCloseRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 形态学闭运算
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageMorphologyCloseRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageGRAY;
        Mat cvImageAdaptiveThresholdMEAN;
        Mat cvImageMorphologyClose;
        Mat kernel = getStructuringElement(0, Size(3, 3));
        QImage qImageMorphologyClose;

        cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        adaptiveThreshold(cvImageGRAY, cvImageAdaptiveThresholdMEAN, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);

        morphologyEx(cvImageAdaptiveThresholdMEAN, cvImageMorphologyClose, MORPH_CLOSE, kernel);

        qImageMorphologyClose = QImage(cvImageMorphologyClose.data, cvImageMorphologyClose.cols, cvImageMorphologyClose.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageMorphologyClose));
        updateMatInfo(cvImageMorphologyClose);
    }
}

/*****************************************************************
** 函数名: onImageMorphologyGradientRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 形态学梯度运算
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageMorphologyGradientRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageGRAY;
        Mat cvImageAdaptiveThresholdMEAN;
        Mat cvImageMorphologyGradient;
        Mat kernel = getStructuringElement(0, Size(3, 3));
        QImage qImageMorphologyGradient;

        cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        adaptiveThreshold(cvImageGRAY, cvImageAdaptiveThresholdMEAN, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);

        morphologyEx(cvImageAdaptiveThresholdMEAN, cvImageMorphologyGradient, MORPH_GRADIENT, kernel);

        qImageMorphologyGradient = QImage(cvImageMorphologyGradient.data, cvImageMorphologyGradient.cols, cvImageMorphologyGradient.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageMorphologyGradient));
        updateMatInfo(cvImageMorphologyGradient);
    }
}

/*****************************************************************
** 函数名: onImageMorphologyTophatRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 形态学顶帽运算
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageMorphologyTophatRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageGRAY;
        Mat cvImageAdaptiveThresholdMEAN;
        Mat cvImageMorphologyTophat;
        Mat kernel = getStructuringElement(0, Size(3, 3));
        QImage qImageMorphologyTophat;

        cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        adaptiveThreshold(cvImageGRAY, cvImageAdaptiveThresholdMEAN, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);

        morphologyEx(cvImageAdaptiveThresholdMEAN, cvImageMorphologyTophat, MORPH_TOPHAT, kernel);

        qImageMorphologyTophat = QImage(cvImageMorphologyTophat.data, cvImageMorphologyTophat.cols, cvImageMorphologyTophat.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageMorphologyTophat));
        updateMatInfo(cvImageMorphologyTophat);
    }
}

/*****************************************************************
** 函数名: onImageMorphologyBlackhatRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 形态学黑帽运算
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageMorphologyBlackhatRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageGRAY;
        Mat cvImageAdaptiveThresholdMEAN;
        Mat cvImageMorphologyBlackhat;
        Mat kernel = getStructuringElement(0, Size(3, 3));
        QImage qImageMorphologyBlackhat;

        cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        adaptiveThreshold(cvImageGRAY, cvImageAdaptiveThresholdMEAN, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);

        morphologyEx(cvImageAdaptiveThresholdMEAN, cvImageMorphologyBlackhat, MORPH_BLACKHAT, kernel);

        qImageMorphologyBlackhat = QImage(cvImageMorphologyBlackhat.data, cvImageMorphologyBlackhat.cols, cvImageMorphologyBlackhat.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageMorphologyBlackhat));
        updateMatInfo(cvImageMorphologyBlackhat);
    }
}

/*****************************************************************
** 函数名: onImageMorphologyBlackhatRadioButtonToggle(bool status)
** 输　入: bool status
** 输　出: 无
** 返回值: 无
** 功能描述: 形态学击中击不中变换
** 作　者: kete
** 日　期: 2022/5/2
** 说　明:
******************************************************************/
void TopWidget::onImageMorphologyHitmissRadioButtonToggle(bool status)
{
    if(!cvImage.empty() && status == true)
    {
        Mat cvImageGRAY;
        Mat cvImageAdaptiveThresholdMEAN;
        Mat cvImageMorphologyHitmiss;
        Mat kernel = getStructuringElement(0, Size(3, 3));
        QImage qImageMorphologyHitmiss;

        cvtColor(cvImage, cvImageGRAY, COLOR_BGR2GRAY);
        adaptiveThreshold(cvImageGRAY, cvImageAdaptiveThresholdMEAN, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);

        morphologyEx(cvImageAdaptiveThresholdMEAN, cvImageMorphologyHitmiss, MORPH_HITMISS, kernel);

        qImageMorphologyHitmiss = QImage(cvImageMorphologyHitmiss.data, cvImageMorphologyHitmiss.cols, cvImageMorphologyHitmiss.rows, QImage::Format_Grayscale8);
        imageShowLabel->setPixmap(QPixmap::fromImage(qImageMorphologyHitmiss));
        updateMatInfo(cvImageMorphologyHitmiss);
    }
}

/*****************************************************************
** 函数名: ~TopWidget()
** 输　入: 无
** 输　出: 无
** 返回值: 无
** 功能描述: 匹配模板
** 作　者: kete
** 日　期: 2022/3/15
** 说　明: 析构函数
******************************************************************/
TopWidget::~TopWidget()
{

}
