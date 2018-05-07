#include "imageSimilarity.h"
#include<QDebug>
#include<QMessageBox>

//bool sortMethod_pHash(imageInfo aaa, imageInfo bbb);

imageSimilarity::imageSimilarity(QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::imageSimilarityClass;
	ui->setupUi(this);

	connect(ui->actionOpen, &QAction::triggered, this, &imageSimilarity::open);
	connect(ui->actionSimilar, &QAction::triggered, this, &imageSimilarity::similar);
	QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(chooseSortMethod(int)));



	QString path = QFileDialog::getExistingDirectory(NULL, tr("ѡ���ļ���"), "E:\\", QFileDialog::ShowDirsOnly);
	qDebug() << path;
	QDir *dir = new QDir(path);
	QStringList filter;
	filter<<"*.jpg";
	dir->setNameFilters(filter);
	QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
	qDebug() << fileInfo->count();
}
imageSimilarity::~imageSimilarity()
{
	delete ui;
}
void imageSimilarity::open() {
	//QString path = QFileDialog::getExistingDirectory(NULL, tr("ѡ���ļ���"), "E:\\", QFileDialog::ShowDirsOnly);
	//QDir *dir = new QDir(path);
	//QStringList filter;
	////filter<<"*.dat";
	////dir->setNameFilters(filter);
	//QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
	//qDebug() << fileInfo->count();

	//for (int i = 0; i < fileInfo->count(); i++)
	//{
	//	qDebug() << fileInfo->at(i).fileName();
	//}


	//���ô��ڴ��ļ�
	filename = QFileDialog::getOpenFileName(this,
		tr("��ͼƬ"),
		".",
		tr("Image file(*.png *.jpg *.bmp)"));
	p1 = filename.toStdString();
	if (!filename.isEmpty()) {
		ui->SrcImgView->clear();
		//QImage���سɹ���չʾ
		if (srcQimage.load(filename)) {
			int width = ui->SrcImgView->width();
			int height = ui->SrcImgView->height();
			QPixmap pixmap = QPixmap::fromImage(srcQimage);
			QPixmap fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
			//Qt::IgnoreAspectRatio, Qt::SmoothTransformation ��� Qt::KeepAspectRatio, Qt::SmoothTransformation ������
			ui->SrcImgView->setPixmap(fitpixmap);
		}
		else {
			QMessageBox::information(this,
				tr("����ʧ��"),
				tr("ͼƬ��ʧ��!"));
			return;
		}
	}
}

void imageSimilarity::similar() {
	if (imagelibs.size() != 0) {
		imagelibs.clear();
	}

	imageInfo info;
	for (int pic = 0; pic < 155;pic++) {
		pySimilarityCore *a = new pySimilarityCore(p1);
		string pathTemp = "imageLib/"+to_string(pic)+".jpg";

		QFileInfo fileInfo(QString::fromStdString(pathTemp));
		if (fileInfo.exists()) {
			p2 = pathTemp;
			qDebug() << QString::fromStdString(p2);

			a->getPath2(p2);
			info.setClassify_gray_hist(a->doSimilarity_classify_gray_hist());
			info.setClassify_hist_with_split(a->doSimilarity_classify_hist_with_split());
			info.setClassify_aHash(a->doSimilarity_classify_aHash());
			info.setClassify_pHash(a->doSimilarity_classify_pHash());
			info.setPath(p2);

			imagelibs.push_back(info);
			free(a);
		}
		else {
			free(a);
			continue;
		}
	}
	int choose = ui->comboBox->currentIndex();
	chooseSortMethod(choose);
}

void imageSimilarity::chooseSortMethod(int choose) {
	if (choose == 0) {
		std::sort(imagelibs.begin(), imagelibs.end(), &imageSimilarity::sortMethod_gray_hist);
	}
	else if (choose == 1) {
		std::sort(imagelibs.begin(), imagelibs.end(), &imageSimilarity::sortMethod_hist_split);
	}
	else if (choose == 2) {
		std::sort(imagelibs.begin(), imagelibs.end(), &imageSimilarity::sortMethod_aHash);
	}
	else if (choose == 3) {
		std::sort(imagelibs.begin(), imagelibs.end(), &imageSimilarity::sortMethod_pHash);
	}

	showLabel();
}

void imageSimilarity::showLabel() {
	ui->label->clear();
	//qDebug() << QString::fromStdString((imagelibs.begin())->getPath());
	//qDebug() << imagelibs.size();
	QString filep = QString::fromStdString((imagelibs.begin())->getPath());
	int width = ui->label->width();
	int height = ui->label->height();
	QImage image1(filep);
	QPixmap pixmap = QPixmap::fromImage(image1);
	QPixmap fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	//Qt::IgnoreAspectRatio, Qt::SmoothTransformation ��� Qt::KeepAspectRatio, Qt::SmoothTransformation ������
	ui->label->setPixmap(fitpixmap);

	ui->label_2->clear();
	QString filep2 = QString::fromStdString((imagelibs.begin() + 1)->getPath());
	QImage image2(filep2);
	QPixmap pixmap2 = QPixmap::fromImage(image2);
	QPixmap fitpixmap2 = pixmap2.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	//Qt::IgnoreAspectRatio, Qt::SmoothTransformation ��� Qt::KeepAspectRatio, Qt::SmoothTransformation ������
	ui->label_2->setPixmap(fitpixmap2);

	ui->label_3->clear();
	//qDebug() << QString::fromStdString((imagelibs.begin() + 2)->getPath());
	QString filep3 = QString::fromStdString((imagelibs.begin() + 2)->getPath());
	QImage image3(filep3);
	QPixmap pixmap3 = QPixmap::fromImage(image3);
	QPixmap fitpixmap3 = pixmap3.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	//Qt::IgnoreAspectRatio, Qt::SmoothTransformation ��� Qt::KeepAspectRatio, Qt::SmoothTransformation ������
	ui->label_3->setPixmap(fitpixmap3);

	ui->label_4->clear();
	//qDebug() << QString::fromStdString((imagelibs.begin() + 3)->getPath());
	QString filep4 = QString::fromStdString((imagelibs.begin() + 3)->getPath());
	QImage image4(filep4);
	QPixmap pixmap4 = QPixmap::fromImage(image4);
	QPixmap fitpixmap4 = pixmap4.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	//Qt::IgnoreAspectRatio, Qt::SmoothTransformation ��� Qt::KeepAspectRatio, Qt::SmoothTransformation ������
	ui->label_4->setPixmap(fitpixmap4);
}

bool imageSimilarity::sortMethod_gray_hist(imageInfo aaa, imageInfo bbb) {
	return ((aaa.getClassify_gray_hist())>(bbb.getClassify_gray_hist()));
}
bool imageSimilarity::sortMethod_hist_split(imageInfo aaa, imageInfo bbb) {
	return ((aaa.getClassify_hist_with_split())>(bbb.getClassify_hist_with_split()));
}
bool imageSimilarity::sortMethod_aHash(imageInfo aaa, imageInfo bbb) {
	return ((aaa.getClassify_aHash())<(bbb.getClassify_aHash()));
}
bool imageSimilarity::sortMethod_pHash(imageInfo aaa, imageInfo bbb) {
	return ((aaa.getClassify_pHash())<(bbb.getClassify_pHash()));
}