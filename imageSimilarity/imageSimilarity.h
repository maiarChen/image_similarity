#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_imageSimilarity.h"
#include<opencv2/opencv.hpp>  
#include<QFileDialog>
#pragma execution_character_set("utf-8")

using namespace cv;
//namespace Ui {
//	class imageSimilarity;
//}

class imageSimilarity : public QMainWindow
{
	Q_OBJECT

public:
	imageSimilarity(QWidget *parent = Q_NULLPTR);
	~imageSimilarity();
private slots:
	void open();
	void similar();
signals:

private:
	Ui::imageSimilarityClass *ui;
};
