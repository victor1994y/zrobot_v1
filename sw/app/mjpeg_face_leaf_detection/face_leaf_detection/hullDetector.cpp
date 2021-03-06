/*
 * hullDetector.cpp
 *
 *  Created on: Jul 23, 2012
 *      Author: shenyunjun
 */

#include "hullDetector.h"
#include "cxcore.h"
#include "highgui.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "math.h"
#include "opencv2/opencv.hpp"

using namespace cv;

HullDetector::HullDetector() {
	// TODO Auto-generated constructor stub

	this->hullPerimeter = 0;
	this->contourPerimeter = 0;
	this->perimeterRatio = 0;

	this->contourArea = 0;
	this->hullArea = 0;
	this->areaRatio = 0;

	this->defectCnt = 0;

	this->areaThreshRatio = 0.2;
	this->minmaxThreshRatio = 0.2;

}

HullDetector::~HullDetector() {
	// TODO Auto-generated destructor stub

} /* namespace cv */


bool HullDetector::HullProcess(std::vector<cv::Point> contour) {

	std::vector<Point> hull;
	std::vector<int> hullIndex;
	std::vector<Vec4i> convexityDefect;



	cv::convexHull(contour, hull, false);
	cv::convexHull(contour, hullIndex, false);
	//calculate the hull area
	
	this->hullArea = CalculateHullArea(hull);
	this->contourArea = cv::contourArea(Mat(contour));

	this->hullPerimeter = CalculateHullPerimeter(hull);
	this->contourPerimeter = arcLength(Mat(contour),true);
	
	
	ConvexityDefects(Mat(contour), hullIndex, convexityDefect);
	
	if(convexityDefect.empty()){
		defectCnt = 0;
		return 0;
	}
	//get the max depth
	int maxDepth = 0;
	for(size_t i = 0; i < convexityDefect.size(); ++i) {
		if(convexityDefect[i].val[3] > maxDepth){
			maxDepth = convexityDefect[i].val[3];
		}
	}
	maxDepth = maxDepth>>8;
	double depthThresh2 = minmaxThreshRatio*maxDepth;

	double depthThresh1 = areaThreshRatio*cv::sqrt(hullArea);

#ifdef DEBUG
	printf("the hull area is %f \n",hullArea);
	printf("the contour area is %f \n",contourArea);
	printf("the depthThresh1 is %f \n", depthThresh1);
	printf("the depthThresh2 is %f \n", depthThresh2);
#endif

	std::vector<Vec4i>::iterator itc;
	defectCnt = convexityDefect.size();
	for(itc = convexityDefect.begin();  itc != convexityDefect.end(); ++itc) {
		double depth = (*itc).val[3]>>8;
		if((depth < depthThresh1)||(depth < depthThresh2)) {;
			--defectCnt;

#ifdef DEBUG
	printf("the invalid defect is  %d\n",((*itc).val[3])>>8);
#endif
			continue;
		}else{

#ifdef DEBUG
	printf("the valid defect is %d\n",((*itc).val[3])>>8);
#endif
		}
	}
	
	return 0;
}


double HullDetector::CalculateHullArea(std::vector<Point> hull) {

	double sumArea = 0;
	double halfPerimeter;
	double edge1;
	double edge2;
	double edgeBrink;

#ifdef DEBUG_CALCULATE_HULL_AREA
	printf("the size of the hull is%d\n",hull.size());
	for(size_t i = 0; i < hull.size(); ++i) {
		printf("the hull pint%d is at x=%d,y=%d\n",i,hull[i].x,hull[i].y);
	}
#endif


	//init
	edge1 = cv::sqrt((double)((hull[0].x - hull[1].x)*(hull[0].x - hull[1].x)+
						(hull[0].y - hull[1].y)*(hull[0].y - hull[1].y)));

	for(size_t i = 1; i < (hull.size()-1); ++i ) {
		edgeBrink = cv::sqrt((double)((hull[i].x - hull[i+1].x)*(hull[i].x - hull[i+1].x)+
							(hull[i].y - hull[i+1].y)*(hull[i].y - hull[i+1].y)));
		edge2 = cv::sqrt((double)((hull[0].x - hull[i+1].x)*(hull[0].x - hull[i+1].x)+
							(hull[0].y - hull[i+1].y)*(hull[0].y - hull[i+1].y)));
		halfPerimeter = 0.5*(edge1 + edge2 + edgeBrink);

		//using the hallen formula
		sumArea +=cv::sqrt(halfPerimeter*(halfPerimeter - edge1)*(halfPerimeter - edge2)*(halfPerimeter - edgeBrink));

#ifdef DEBUG_CALCULATE_HULL_AREA
	printf("the sum is %f\n",(float)sumArea);
	printf("the brinkedge is %f\n,the edge2 is %f\n the edge1 is %f\n",(float)edgeBrink,(float)edge2,(float)edge1);
#endif
		++i;
		if(i >= (hull.size()-1))
			break;

		edge1 = cv::sqrt((double)((hull[0].x - hull[i+1].x)*(hull[0].x - hull[i+1].x)+
				(hull[0].y - hull[i+1].y)*(hull[0].y - hull[i+1].y)));
		edgeBrink = cv::sqrt((double)((hull[i].x - hull[i+1].x)*(hull[i].x - hull[i+1].x)+
					(hull[i].y - hull[i+1].y)*(hull[i].y - hull[i+1].y)));
		halfPerimeter = 0.5*(edge1 + edge2 + edgeBrink);

		sumArea +=cv::sqrt(halfPerimeter*(halfPerimeter - edge1)*(halfPerimeter - edge2)*(halfPerimeter - edgeBrink));
#ifdef DEBUG_CALCULATE_HULL_AREA
	printf("the sum is %f\n",(float)sumArea);
	printf("the brinkedge is %f\n,the edge2 is %f\n the edge1 is %f\n",(float)edgeBrink,(float)edge2,(float)edge1);
#endif
	}

	return sumArea;
}


double HullDetector::CalculateHullPerimeter(std::vector<Point> hull) {
	double perimeter = 0;

	for(size_t i = 0; i < (hull.size()-1); ++i) {
		perimeter += cv::sqrt((double)((hull[i].x - hull[i+1].x)*(hull[i].x - hull[i+1].x)+
				(hull[i].y - hull[i+1].y)*(hull[i].y - hull[i+1].y)));
	}
	perimeter += cv::sqrt((double)((hull[0].x - hull[hull.size()-1].x)*(hull[0].x - hull[hull.size()-1].x)+
			(hull[0].y - hull[hull.size()-1].y)*(hull[0].y - hull[hull.size()-1].y)));

	return perimeter;
}


void HullDetector::ConvexityDefects( InputArray _points, InputArray _hull, OutputArray _defects )
{
    Mat points = _points.getMat();
    int ptnum = points.checkVector(2, CV_32S);
    CV_Assert( ptnum > 3 );
    Mat hull = _hull.getMat();
//  CV_Assert( hull.checkVector(1, CV_32S) > 2 );
    Ptr<CvMemStorage> storage = cvCreateMemStorage();

    CvMat c_points = points, c_hull = hull;
    CvSeq* seq = cvConvexityDefects(&c_points, &c_hull, storage);
    int i, n = seq->total;

    if( n == 0 )
    {
        _defects.release();
        return;
    }

    _defects.create(n, 1, CV_32SC4);
    Mat defects = _defects.getMat();

    SeqIterator<CvConvexityDefect> it = Seq<CvConvexityDefect>(seq).begin();
    CvPoint* ptorg = (CvPoint*)points.data;

    for( i = 0; i < n; i++, ++it )
    {
        CvConvexityDefect& d = *it;
        int idx0 = (int)(d.start - ptorg);
        int idx1 = (int)(d.end - ptorg);
        int idx2 = (int)(d.depth_point - ptorg);
        CV_Assert( 0 <= idx0 && idx0 < ptnum );
        CV_Assert( 0 <= idx1 && idx1 < ptnum );
        CV_Assert( 0 <= idx2 && idx2 < ptnum );
        CV_Assert( d.depth >= 0 );
        int idepth = cvRound(d.depth*256);
        defects.at<Vec4i>(i) = Vec4i(idx0, idx1, idx2, idepth);
    }

}

//setter and getter

size_t HullDetector::getHullArea() {
	return this->hullArea;
}

size_t HullDetector::getContourArea() {
	return this->contourArea;
}

double HullDetector::getAreaRatio() {
	return (this->contourArea)/(this->hullArea);
}

void HullDetector::setThresholdRatio(double _minmaxThreshRatio, double _areaThreshRatio) {
	minmaxThreshRatio = _minmaxThreshRatio;
	areaThreshRatio = _areaThreshRatio;
}

size_t HullDetector::getDefectCnt() {
	return (this->defectCnt);
}

double HullDetector::getPerimeterRatio() {
	return (this->hullPerimeter)/(this->contourPerimeter);
}
