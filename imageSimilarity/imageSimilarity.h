#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_imageSimilarity.h"

#include"imageInfo.h"
#include "pySimilarityCore.h"
#include<opencv2/opencv.hpp>  
#include<QFileDialog>
#include <algorithm>
#pragma execution_character_set("utf-8")

//using namespace cv;
//namespace Ui {
//	class imageSimilarity;
//}

class imageSimilarity : public QMainWindow
{
	Q_OBJECT

public:
	imageSimilarity(QWidget *parent = Q_NULLPTR);
	~imageSimilarity();
	static bool sortMethod_pHash(imageInfo, imageInfo);
private slots:
	void open();
	void similar();
signals:

private:
	Ui::imageSimilarityClass *ui;
	pySimilarityCore *a;
	QString filename;
	/*Mat srcImage;*/	
	QImage srcQimage;
	/*vector<imageInfo*> imagelibs;*/
	vector<imageInfo> imagelibs;

	string p1;
	string p2;
};
