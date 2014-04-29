#include "calculate.h"

////Ä£°åÆ¥Åä/////////
Mat temp0= (Mat_<uchar>(16,16) <<
255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,
255,255,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,255,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255);

Mat temp1= (Mat_<uchar>(16,16) <<
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,255,
0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,
0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,
0,0,0,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);


Mat temp2= (Mat_<uchar>(16,16) << 
255,255,255,0,0,0,0,0,0,0,0,0,255,255,255,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
0,0,0,0,255,255,255,255,0,0,0,0,0,0,0,255,
255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,255,
255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,255,
255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,255,
255,255,255,255,255,255,255,255,0,0,0,0,0,0,255,255,
255,255,255,255,255,255,0,0,0,0,0,0,0,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,0,255,255,255,255,
255,255,255,255,0,0,0,0,0,0,0,255,255,255,255,255,
255,255,0,0,0,0,0,0,0,255,255,255,255,255,255,255,
255,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

Mat temp3= (Mat_<uchar>(16,16) <<
255,255,255,0,0,0,0,0,0,0,0,0,255,255,255,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
0,0,0,255,255,255,255,255,255,0,0,0,0,0,0,255,
255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,255,
255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,255,
255,255,255,255,255,255,0,0,0,0,0,0,0,0,255,255,
255,255,0,0,0,0,0,0,0,0,0,0,255,255,255,255,
255,255,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,
255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,
255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,
0,0,255,255,255,255,255,255,255,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,255,0,0,0,0,0,0,0,0,0,0,255,255,255,255);

Mat temp4= (Mat_<uchar>(16,16) << 
255,255,255,255,255,255,255,0,0,0,0,0,0,0,255,255,
255,255,255,255,255,255,0,0,0,0,0,0,0,0,255,255,
255,255,255,255,255,0,0,0,0,0,0,0,0,0,255,255,
255,255,255,255,255,0,0,0,0,0,0,0,0,0,255,255,
255,255,255,255,0,0,0,0,0,0,0,0,0,0,255,255,
255,255,255,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,255,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,255,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
255,255,255,255,255,255,255,255,255,0,0,0,0,0,255,255,
255,255,255,255,255,255,255,255,255,0,0,0,0,0,255,255,
255,255,255,255,255,255,255,255,255,0,0,0,0,0,255,255);

Mat temp5= (Mat_<uchar>(16,16) << 
255,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,
255,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,
255,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,
255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,
255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,
0,0,255,255,255,255,255,255,255,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255);

Mat temp6= (Mat_<uchar>(16,16) <<
255,255,255,255,255,0,0,0,0,0,0,0,0,0,255,255,
255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,
255,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,
0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,255,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255);

Mat temp7= (Mat_<uchar>(16,16) <<   
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,
255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,255,
255,255,255,255,255,255,255,255,0,0,0,0,0,0,255,255,
255,255,255,255,255,255,255,255,0,0,0,0,0,0,255,255,
255,255,255,255,255,255,255,0,0,0,0,0,0,255,255,255,
255,255,255,255,255,255,255,0,0,0,0,0,255,255,255,255,
255,255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,255,
255,255,255,0,0,0,0,0,0,255,255,255,255,255,255,255,
255,255,255,0,0,0,0,0,0,255,255,255,255,255,255,255,
255,255,0,0,0,0,0,0,255,255,255,255,255,255,255,255);

Mat temp8= (Mat_<uchar>(16,16) << 
255,255,255,255,0,0,0,0,0,0,0,0,0,255,255,255,
255,255,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,255,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,255,255,0,0,0,0,0,0,0,0,0,255,255,255,255,
255,255,255,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
255,255,255,0,0,0,0,0,0,0,0,0,255,255,255,255);

Mat temp9= (Mat_<uchar>(16,16) << 
255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,
255,255,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,
255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,255,
255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,
255,255,0,0,0,0,0,0,0,0,0,255,255,255,255,255);
		
Mat temp_plus= (Mat_<uchar>(16,16) << 
255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,
255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,
255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,
255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,
255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,
255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,
255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,
255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,
255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,
255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,
255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255);


Mat temp_minus= (Mat_<uchar>(16,16) <<
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

Mat temp_mult= (Mat_<uchar>(16,16) <<
255,255,0,255,255,255,255,255,255,255,255,255,255,0,255,255,
255,0,0,0,255,255,255,255,255,255,255,255,0,0,0,255,
0,0,0,0,0,255,255,255,255,255,255,0,0,0,0,0,
255,0,0,0,0,0,255,255,255,255,0,0,0,0,0,255,
255,255,0,0,0,0,0,255,255,0,0,0,0,0,255,255,
255,255,255,0,0,0,0,0,0,0,0,0,0,255,255,255,
255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,
255,255,255,0,0,0,0,0,0,0,0,0,0,255,255,255,
255,255,0,0,0,0,0,255,255,0,0,0,0,0,255,255,
255,0,0,0,0,0,255,255,255,255,0,0,0,0,0,255,
0,0,0,0,0,255,255,255,255,255,255,0,0,0,0,0,
255,0,0,0,255,255,255,255,255,255,255,255,0,0,0,255,
255,255,0,255,255,255,255,255,255,255,255,255,255,0,255,255);

Mat temp_div= (Mat_<uchar>(16,16) <<	
255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,
255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,255,
255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,255,
255,255,255,255,255,255,255,255,0,0,0,0,0,0,255,255,
255,255,255,255,255,255,255,0,0,0,0,0,0,255,255,255,
255,255,255,255,255,255,0,0,0,0,0,0,0,255,255,255,
255,255,255,255,255,255,0,0,0,0,0,0,255,255,255,255,
255,255,255,255,255,0,0,0,0,0,0,0,255,255,255,255,
255,255,255,255,0,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,255,0,0,0,0,0,0,0,255,255,255,255,255,
255,255,255,0,0,0,0,0,0,0,255,255,255,255,255,255,
255,255,255,0,0,0,0,0,0,255,255,255,255,255,255,255,
255,255,0,0,0,0,0,0,0,255,255,255,255,255,255,255,
255,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,
255,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,
0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255);


int Result=0;

int Calculate::Match(Mat UniChar, Mat temp){
	int Match= 0;
	for(int j=0; j<16; j++){
		uchar* dataU= UniChar.ptr<uchar>(j);
		uchar* dataT= temp.ptr<uchar>(j);
		for(int i=0; i<16; i++){
			if(dataU[i] == dataT[i]) Match++;
		}
	}
	return Match;
}

int Calculate::NumClassifier(Mat charImage, Rect charArea){
	// ×Ö·û·Öžî¡¢Ëõ·Å
	Mat CROI(charImage,charArea);
	Mat numImg;
	resize(CROI, numImg, Size(16,16));
	threshold( numImg, numImg, 128, 255, THRESH_BINARY );

	int Num;	//	0-9,error:10
	int num[10];
	num[0]= Match(numImg, temp0);
	num[1]= Match(numImg, temp1);
	num[2]= Match(numImg, temp2);
	num[3]= Match(numImg, temp3);
	num[4]= Match(numImg, temp4);
	num[5]= Match(numImg, temp5);
	num[6]= Match(numImg, temp6);
	num[7]= Match(numImg, temp7);
	num[8]= Match(numImg, temp8);
	num[9]= Match(numImg, temp9);

	int maxNum = 0;
	for(int i=0; i<10; i++) {
		if(num[i] > maxNum){
			maxNum= num[i];
			Num= i;
		}
	}
	
	return Num;
}

int Calculate::OperateClassifier(Mat charImage, Rect charArea){
	// ×Ö·û·Öžî¡¢Ëõ·Å
	Mat CROI(charImage,charArea);
	Mat operateImg;
	resize(CROI, operateImg, Size(16,16));
	threshold( operateImg, operateImg, 128, 255, THRESH_BINARY );

	int Operate;	// 0:+  1:-  2:¡Á  4:/
	int operate[4];
	operate[0]= Match(operateImg, temp_plus);
	operate[1]= Match(operateImg, temp_minus);
	operate[2]= Match(operateImg, temp_mult);
	operate[3]= Match(operateImg, temp_div);
	int maxNum = 0;

	for(int i=0; i<4; i++) {
		if(operate[i] > maxNum){
			maxNum= operate[i];
			Operate= i;
		}
	}
	return Operate;
}

void Calculate::Recognition(Mat *image, Mat* scale8u, char* label, Size2f patchSize){
  // Structure Define ////////////////////////////////////////////////////////////////
  vector<vector<Point> > contours;
  vector<vector<Point> >:: iterator itc;

  //// Parameter Define //////////////////////////////////////////////////////////////
  int contourNum= 0;			// ×Ö·ûÇøÓòÊ¶±ð³öµÄ×Ö·ûÊý£¬µ±ÇÒœöµ±contourNum= 5Ê±£¬²Å»áœøÐÐ×Ö·ûÊ¶±ð
  Rect charRect[5];			// Ã¿žö×Ö·ûÔÚÍŒÏñÖÐµÄŸØÐÎÇøÓò
  // È«ŸÖ±äÁ¿
  int result= 100;
  int Num1, Num2, Operate;// ËãÊœ×Ö·ûÊ¶±ðœá¹û

  ////ÇÐžî³ö×Ö·ûÇøÓò///////////////////////////////////////////////////////////////////
	  Mat BW2;
	  Mat ROI(*scale8u,Rect(patchSize.width/16,patchSize.height/8, patchSize.width*7/8, patchSize.height*3/4));	
	  threshold( ROI, BW2, 0, 255, CV_THRESH_OTSU+THRESH_BINARY_INV );
	  findContours( BW2, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE );
	  itc = contours.begin();
	  while(itc!= contours.end()) {             //Eliminate smaller contours
					  if(itc->size() < patchSize.width/8)
						  itc= contours.erase(itc);
					  else{
						  ++itc;
						  ++contourNum;
					  }
		  }
	  itc = contours.begin();
  if(itc != contours.end()){
	  Mat CONTOUR(BW2.size(), CV_8U, Scalar(255));
	  drawContours(CONTOUR, contours, -1, Scalar(0), CV_FILLED);


    ////×Ö·ûÅÅÐò¡¢Ê¶±ð///////////////////////////////////////////////////////////////////////////
    if( contourNum == 5) {			//µ±ÇÒœöµ±contourNum= 5Ê±£¬²Å»áœøÐÐ×Ö·ûÅÅÐò¡¢Ê¶±ð

	    // ×Ö·ûÂÖÀªŒì²â
	    itc = contours.begin();
	    for(int i=0; i<5; i++) {  
		    charRect[i]=  boundingRect(*itc);
		    itc++;
	    }
	    // ÂÖÀªÅÅÐò
	    Rect rectTemp;
	    for(int i=0; i<4; i++){
		    for( int j=0; j<4-i; j++){
			    if(charRect[j].x>charRect[j+1].x){
				    rectTemp= charRect[j];
				    charRect[j]= charRect[j+1];
				    charRect[j+1]= rectTemp;
			    }
		    }
	    }
	    //·ÖÀàÊ¶±ð	
	    Num1 = NumClassifier(CONTOUR, charRect[0]);
	    Operate = OperateClassifier(CONTOUR, charRect[1]);
	    Num2 = NumClassifier(CONTOUR, charRect[2]);

	
	    //ËãÊœœá¹ûÔËËã
	    if(Operate==0)		result= Num1 + Num2;
	    else if(Operate==1)	result= Num1 - Num2;
	    else if(Operate==2)	result= Num1 * Num2;
	    else
		    if(Num2!=0) result= Num1 / Num2;
		    else result= 100;


	    if(result != 100) Result= result;

	    // œá¹ûŽòÓ¡
	    char display[20];
	    if(Operate==0)
		    sprintf(display, "%d+%d=%d",Num1,Num2,Result);
	    else if(Operate==1)
		    sprintf(display, "%d-%d=%d",Num1,Num2,Result);
	    else if(Operate==2)
		    sprintf(display, "%dx%d=%d",Num1,Num2,Result);
	    else
		    sprintf(display, "%d/%d=%d",Num1,Num2,Result);
	    putText(*image,display,Point(20,460), FONT_HERSHEY_SIMPLEX, 1.4,Scalar(0,255,0),3,8);

	    //œá¹û×Ö·ûŽ®Êä³ö
	    int res;
	    if(Operate==0)
		    res= sprintf(label, "./shownum %d+%d=%d",Num1,Num2,Result);
	    else if(Operate==1)
		    res= sprintf(label, "./shownum %d-%d=%d",Num1,Num2,Result);
	    else if(Operate==2)
		    res= sprintf(label, "./shownum %dx%d=%d",Num1,Num2,Result);
	    else
		    res= sprintf(label, "./shownum %d/%d=%d",Num1,Num2,Result);
	    label[res]='\0';
 //     printf("calculator%s\n",label);
    }  // END¡ª¡ªif( contourNum == 5) 
  }	// END¡ª¡ªitc != contours.end() µÚ¶þŽÎ
}
