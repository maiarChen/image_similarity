#include "imageSimilarity.h"
#include<QDebug>
#include "pySimilarityCore.h"
#include<iostream>
imageSimilarity::imageSimilarity(QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::imageSimilarityClass;
	ui->setupUi(this);

	connect(ui->actionOpen, &QAction::triggered, this, &imageSimilarity::open);
	connect(ui->actionSimilar, &QAction::triggered, this, &imageSimilarity::similar);
}
imageSimilarity::~imageSimilarity()
{
	delete ui;
}
void imageSimilarity::open() {
	QString path = QFileDialog::getExistingDirectory(NULL, tr("Ñ¡ÔñÎÄ¼þ¼Ð"), "E:\\", QFileDialog::ShowDirsOnly);
	QDir *dir = new QDir(path);
	QStringList filter;
	//filter<<"*.dat";
	//dir->setNameFilters(filter);
	QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
	qDebug() << fileInfo->count();

	for (int i = 0; i < fileInfo->count(); i++)
	{
		qDebug() << fileInfo->at(i).fileName();
	}
}
void imageSimilarity::similar() {
	string p1 = "38.jpg";
	string p2 = "lena.jpg";
	pySimilarityCore *a=new pySimilarityCore(p1,p2);
	qDebug() << a->doSimilarity_classify_gray_hist();
	qDebug() << a->doSimilarity_classify_hist_with_split();
	qDebug() << a->doSimilarity_classify_aHash();
	qDebug() << a->doSimilarity_classify_pHash();
}