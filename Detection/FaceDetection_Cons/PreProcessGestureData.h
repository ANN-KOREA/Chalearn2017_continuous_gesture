#pragma once
#include <afxwin.h>
#include "VIPLFaceDetector.h"
#include <cv.h>
#include <highgui.h>
#include <vector>
#include <math.h>
#include <iostream>
#include <direct.h>
#include <fstream>
#include <algorithm>   
using namespace cv;

class PreProcessGestureData
{
private:

	vector<IplImage*> vColor;//vColor �洢RGB video
	vector<IplImage*> vDepth;//vDepth �洢Depth vedio
	vector<IplImage*> vfDepth;
	int facenum;
	VIPLFaceInfo FDResult[1024];
	VIPLFaceDetector faceDetector;

	CString MyColorPath;

	int eps;//С��eps�ĻҶ�ֵ��������������Ϊ5
	char buffer[256];
private:
	void GetFacePosiFromHist(IplImage *image, int &x, int &y);//��������ⲻ��ʱ��ͳ��ֱ��ͼǰ���ָ���ͷ����ߵ� y - 30
	void CvtGray(cv::Mat &src, cv::Mat &src_gray);
	void CvtVIPLData(cv::Mat &src, VIPLImageData &srcdata);
	void backgroundRemove();
	void Rectify(IplImage* img1, IplImage* img2);
	void GetImageGrayMean(IplImage *image, int &grayMean);
	void GetMaxConnectedDomain(IplImage *src, IplImage *dst);

public:
	PreProcessGestureData(void);
	~PreProcessGestureData(void);
	void getFacePositionHist(CString filename);
	void ReleaseVector();
	bool OutheadDetectionVIPLSDK(IplImage* colorImage, CString filename, int countframe);
	bool readVideo(CString colorPath, CString depthPath);
	void GetHistAndPartition(IplImage *image, int &peak1, int &peak2, int &Mypartition, int &grayMean);
	bool headDetectionVIPLSDK(IplImage* colorImage);
public:
	CString faceDataPath;
	int faceX;//��ʾ��faceX, faceY����������ֵ�����δ��⵽��������ȫΪ��0��0��
	int faceY;
};

