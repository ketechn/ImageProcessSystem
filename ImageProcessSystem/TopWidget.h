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
#include <QGridLayout>
#include <QTabWidget>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QPixmap>
#include <QVector>
#include <QSlider>
#include <QDial>
#include <QMatrix>
#include "../opencv2/opencv.hpp"


using namespace cv;

class TopWidget : public QWidget
{
    Q_OBJECT

    /*图片颜色类型*/
    typedef enum
    {
        RGB = 0,
        YUV,
        HSV,
        Lab,
        GRAY
    }ImageColorMode;

    /*保存图片的类*/
    Mat cvImage;
    QImage qImage;
    ImageColorMode imageColorMode;

    /*摄像头类*/
    VideoCapture cvVideoCap;

    /*顶层布局（左右两部分）左边为图像处理设置，右边显示图片/视频*/
    QHBoxLayout* topHBoxLayout;/*顶层布局管理组,横向布局,左边为图像处理，右边为图片/视频*/
    QWidget* leftProcessVBoxWidget;/*顶层布局管理组的左边，竖向布局，为各个模块的处理单元*/
    QTabWidget* rightImageVideoTabWidget;/*顶层布局管理组的右边，图片/视频*/

    /*左侧图像处理部分*/
    QVBoxLayout* leftProcessVBoxLayout;

    /*图像处理第一部分-颜色模型转换与分离*/
    QGroupBox* imageColorTransSplitGroupBox;
    QHBoxLayout* imageColorTransSplitHBoxLayout;
    QRadioButton* imageColorRGBRadioButton;
    QRadioButton* imageColorYUVRadioButton;
    QRadioButton* imageColorHSVRadioButton;
    QRadioButton* imageColorLabRadioButton;
    QRadioButton* imageColorGRAYRadioButton;
    QPushButton* imageColorSplitPushButton;

    /*图像处理第二部分-单图像的像素操作*/
    QGroupBox* imageSinglePixelProcessGroupBox;
    QHBoxLayout* imageSinglePixelProcessHBoxLayout;
    QRadioButton* imageSinglePixelProcessOriginalRadioButton;/*原始图像*/
    QRadioButton* imageSinglePixelProcessNotRadioButton;/*像素取反*/
    QRadioButton* imageSinglePixelProcessThresholdOTSURadioButton;/*大津法自动寻求全局阈值*/
    QRadioButton* imageSinglePixelProcessThresholdTRIANGLERadioButton;/*三角形法自动寻求全局阈值*/
    QRadioButton* imageSinglePixelProcessAdaptiveThresholdMEANRadioButton;/*均值法求局部自适应阈值*/
    QRadioButton* imageSinglePixelProcessAdaptiveThresholdGAUSSIANRadioButton;/*高斯法求局部自适应阈值*/

    /*图像处理第三部分-两图像间的像素操作*/
    Mat cvImagePairCal1, cvImagePairCal2;
    QImage cvImagePairCal;
    QGroupBox* imagePairPixelProcessGroupBox;
    QWidget* imagePairPixelProcessLoadImageWidget;
    QVBoxLayout* imagePairPixelProcessVBoxLayout;
    QGridLayout* imagePairPixelProcessLoadImageGridLayout;
    QPushButton* imagePairPixelProcessLoadImage1PushButton;
    QPushButton* imagePairPixelProcessLoadImage2PushButton;
    QLineEdit* imagePairPixelProcessLoadImage1PathLineEdit;
    QLineEdit* imagePairPixelProcessLoadImage2PathLineEdit;
    QGroupBox* imagePairPixelProcessCalGroupBox;
    QHBoxLayout* imagePairPixelProcessCalHBoxLayout;
    QRadioButton* imagePairPixelProcessCLRRadioButton;
    QRadioButton* imagePairPixelProcessMAXRadioButton;
    QRadioButton* imagePairPixelProcessMINRadioButton;
    QRadioButton* imagePairPixelProcessANDRadioButton;
    QRadioButton* imagePairPixelProcessORRadioButton;
    QRadioButton* imagePairPixelProcessXORRadioButton;
    bool isImagePairPixelProcessCal(const Mat& Mat1, const Mat& Mat2);

    /*图像处理第四部分-图像的缩放与旋转*/
    QGroupBox* imageZoomAndRotateGroupBox;
    QGridLayout* imageZoomAndRotateGridLayout;
    QSlider* imageZoomSlider;
    QSlider* imageRotateSlider;
    QLabel* imageZoomTextLabel;
    QLabel* imageRotateTextLabel;
    QLabel* imageZoomValueLabel;
    QLabel* imageRotateValueLabel;

    /*图像处理第五部分-直方图应用*/
    QGroupBox* imageHistApplyGroupBox;
    QVBoxLayout* imageHistApplyVBoxLayout;
    QGroupBox* imageHistApplyEqualizeGroupBox;
    QHBoxLayout* imageHistApplyEqualizeHBoxLayout;
    QRadioButton* imageHistApplyEqualizeRestoreRadioButton;
    QRadioButton* imageHistApplyEqualizeGrayRadioButton;
    QRadioButton* imageHistApplyEqualizeEqualizeRadioButton;
    QGroupBox* imageHistApplyTemplateMatchGroupBox;
    QHBoxLayout* imageHistApplyTemplateMatchHBoxLayout;
    QPushButton* imageHistApplyTemplateMatchLoadPushButton;
    QLineEdit* imageHistApplyTemplateMatchPathLineEdit;
    QPushButton* imageHistApplyTemplateMatchMatchPushButton;
    Mat cvImageTemplate;

    /*图像处理第六部分-图像滤波*/
    QGroupBox* imageFilterGroupBox;
    QVBoxLayout* imageFileterVBoxLayout;
    QGroupBox* imageFilterAddNoiseGroupBox;
    QGridLayout* imageFilterAddNoiseGridLayout;
    QLabel* imageFilterAddNoiseSaltTextLabel;
    QSlider* imageFilterAddNoiseSaltSlider;
    QLabel* imageFilterAddNoiseSaltValueLabel;
    QLabel* imageFilterAddNoiseGaussAvgTextLabel;
    QSlider* imageFilterAddNoiseGaussAvgSlider;
    QLabel* imageFilterAddNoiseGaussAvgValueLabel;
    QLabel* imageFilterAddNoiseGaussStdTextLabel;
    QSlider* imageFilterAddNoiseGaussStdSlider;
    QLabel* imageFilterAddNoiseGaussStdValueLabel;
    QGroupBox* imageFilterLowPassFilterGroupBox;
    QHBoxLayout* imageFilterLowPassFilterHBoxLayout;
    QRadioButton* imageFilterLowPassFilterOriginalRadioButton;
    QRadioButton* imageFilterLowPassFilterBlurRadioButton;
    QRadioButton* imageFilterLowPassFilterGaussBlurRadioButton;
    QRadioButton* imageFilterLowPassFilterMedianBlurRadioButton;
    QGroupBox* imageFilterHighPassFilterGroupBox;
    QHBoxLayout* imageFilterHighPassFilterHBoxLayout;
    QRadioButton* imageFilterHighPassFilterOriginalRadioButton;
    QRadioButton* imageFilterHighPassFilterSobelRadioButton;
    QRadioButton* imageFilterHighPassFilterScharrRadioButton;
    QRadioButton* imageFilterHighPassFilterLaplacianRadioButton;
    QRadioButton* imageFilterHighPassFilterCannyRadioButton;

    /*图像处理第七部分-形态学操作*/
    QGroupBox* imageMorphologyGroupBox;
    QHBoxLayout* imageMorphologyHBoxLayout;
    QRadioButton* imageMorphologyOriginalRadioButton;
    QRadioButton* imageMorphologyAdaptiveMEANRadioButton;
    QRadioButton* imageMorphologyOpenRadioButton;
    QRadioButton* imageMorphologyCloseRadioButton;
    QRadioButton* imageMorphologyGradientRadioButton;
    QRadioButton* imageMorphologyTophatRadioButton;
    QRadioButton* imageMorphologyBlackhatRadioButton;
    QRadioButton* imageMorphologyHitmissRadioButton;

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

    /*图片部分（图片信息），顶层为横向布局，从左到右依次是图片像素信息（表单布局）,图像直方图...*/
    QHBoxLayout* imageInfoHBoxLayout;
    QWidget* imageMatInfoWidget;
    QLabel* imageHistShowLabel;
    QFormLayout* imageMatInfoFormLayout;
    QLineEdit* imageMatInfoColsLineEdit;
    QLineEdit* imageMatInfoRowsLineEdit;
    QLineEdit* imageMatInfoElemSizeLineEdit;
    QLineEdit* imageMatInfoTotalLineEdit;
    QLineEdit* imageMatInfoChannelsLineEdit;
    bool updateMatInfo(const Mat& mat);
    bool updateMatHist(const Mat& mat, Mat& MatHist);

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

    /*视频部分（视频信息）,显示视频信息*/
    QFormLayout* videoInfoFormLayout;
    QLineEdit* videoInfoPosMsecLineEdit;
    QLineEdit* videoInfoFrameWidthLineEdit;
    QLineEdit* videoInfoFrameHeightLineEdit;
    QLineEdit* videoInfoFpsLineEdit;
    QLineEdit* videoInfoFourccLineEdit;
    QLineEdit* videoInfoFrameCountLineEdit;
    QLineEdit* videoInfoFormatLineEdit;
    QLineEdit* videoInfoBrightnessLineEdit;
    QLineEdit* videoInfoContrastLineEdit;
    QLineEdit* videoInfoSaturationLineEdit;
    QLineEdit* videoInfoHueLineEdit;
    QLineEdit* videoInfoGainEdit;


    /*对话框,清除图像等*/
    void clearGlobalImage();
    void showCriticalDialog(QString message);


private slots:
    void onImageLoadPushButtonClick();
    void onImageSavePushButtonClick();
    void onVideoLoadOpenCameraPushButtonClick();
    void onVideoLoadCloseCameraPushButtonClick();
    void onImageColorRGBRadioButtonToggle(bool status);
    void onImageColorYUVRadioButtonToggle(bool status);
    void onImageColorHSVRadioButtonToggle(bool status);
    void onImageColorLabRadioButtonToggle(bool status);
    void onImageColorGRAYRadioButtonToggle(bool status);
    void onImageColorSplitPushButtonClick();
    void onImageSinglePixelProcessOriginalRadioButtonToggle(bool status);
    void onImageSinglePixelProcessNotRadioButtonToggle(bool status);
    void onImageSinglePixelProcessThresholdOTSURadioButtonToggle(bool status);
    void onImageSinglePixelProcessThresholdTRIANGLERadioButtonToggle(bool status);
    void onImageSinglePixelProcessAdaptiveThresholdMEANRadioButtonToggle(bool status);
    void onImageSinglePixelProcessAdaptiveThresholdGAUSSIANRadioButtonToggle(bool status);
    void onImagePairPixelProcessLoadImage1PushButtonClick();
    void onImagePairPixelProcessLoadImage2PushButtonClick();
    void onImagePairPixelProcessCLRRadioButtonToggle(bool status);
    void onImagePairPixelProcessMAXRadioButtonToggle(bool status);
    void onImagePairPixelProcessMINRadioButtonToggle(bool status);
    void onImagePairPixelProcessANDRadioButtonToggle(bool status);
    void onImagePairPixelProcessORRadioButtonToggle(bool status);
    void onImagePairPixelProcessXORRadioButtonToggle(bool status);
    void onImageZoomValueChanged(int value);
    void onImageRotateValueChanged(int value);
    void onImageHistApplyRestoreRadioButtonToggle(bool status);
    void onImageHistApplyGrayRadioButtonToggle(bool status);
    void onImageHistApplyEqualizeRadioButtonToggle(bool status);
    void onImageHistApplyTemplateLoadPushButtonClick();
    void onImageHistApplyTemplateMatchPushButtonClick();
    void onImageAddNoiseSaltChanged(int value);
    void onImageAddNoiseGaussAvgChanged(int value);
    void onImageAddNoiseGaussStdChanged(int value);
    void onImageFilterLowPassRestoreRadioButtonToggle(bool status);
    void onImageFilterLowPassBlurRadioButtonToggle(bool status);
    void onImageFilterLowPassGaussBlurRadioButtonToggle(bool status);
    void onImageFilterLowPassMedianBlurRadioButtonToggle(bool status);
    void onImageFilterHighPassRestoreRadioButtonToggle(bool status);
    void onImageFilterHighPassSobelRadioButtonToggle(bool status);
    void onImageFilterHighPassScharrRadioButtonToggle(bool status);
    void onImageFilterHighPassLaplacianRadioButtonToggle(bool status);
    void onImageFilterHighPassCannyRadioButtonToggle(bool status);
    void onImageMorphologyOriginalRadioButtonToggle(bool status);
    void onImageMorphologyAdaptiveMEANRadioButtonToggle(bool status);
    void onImageMorphologyOpenRadioButtonToggle(bool status);
    void onImageMorphologyCloseRadioButtonToggle(bool status);
    void onImageMorphologyGradientRadioButtonToggle(bool status);
    void onImageMorphologyTophatRadioButtonToggle(bool status);
    void onImageMorphologyBlackhatRadioButtonToggle(bool status);
    void onImageMorphologyHitmissRadioButtonToggle(bool status);


public:
    TopWidget(QWidget* parent = 0);
    ~TopWidget();
};

#endif //_TOPWIDGET_H_
