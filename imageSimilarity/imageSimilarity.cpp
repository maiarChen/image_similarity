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
}
imageSimilarity::~imageSimilarity()
{
	delete ui;
}
void imageSimilarity::open() {
	//QString path = QFileDialog::getExistingDirectory(NULL, tr("选择文件夹"), "E:\\", QFileDialog::ShowDirsOnly);
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


	//调用窗口打开文件
	filename = QFileDialog::getOpenFileName(this,
		tr("打开图片"),
		".",
		tr("Image file(*.png *.jpg *.bmp)"));
	p1 = filename.toStdString();
	if (!filename.isEmpty()) {
		ui->SrcImgView->clear();
		//QImage加载成功则展示
		if (srcQimage.load(filename)) {
			int width = ui->SrcImgView->width();
			int height = ui->SrcImgView->height();
			QPixmap pixmap = QPixmap::fromImage(srcQimage);
			QPixmap fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
			//Qt::IgnoreAspectRatio, Qt::SmoothTransformation 填充 Qt::KeepAspectRatio, Qt::SmoothTransformation 按比例
			ui->SrcImgView->setPixmap(fitpixmap);
		}
		else {
			QMessageBox::information(this,
				tr("操作失败"),
				tr("图片打开失败!"));
			return;
		}
	}
}
void imageSimilarity::similar() {
	if (imagelibs.size() != 0) {
		imagelibs.clear();
	}

	a=new pySimilarityCore(p1);
	imageInfo info;
	for (int pic = 0; pic < 60;pic++) {
		p2 = "imageLib/"+to_string(pic)+".jpg";
		qDebug() << QString::fromStdString(p2);
		a->getPath2(p2);

		info.setClassify_gray_hist(a->doSimilarity_classify_gray_hist());
		info.setClassify_hist_with_split(a->doSimilarity_classify_hist_with_split());
		info.setClassify_aHash(a->doSimilarity_classify_aHash());
		info.setClassify_pHash(a->doSimilarity_classify_pHash());
		info.setPath(p2);

		//qDebug() << a->doSimilarity_classify_gray_hist();
		//qDebug() << a->doSimilarity_classify_hist_with_split();
		//qDebug() << a->doSimilarity_classify_aHash();
		//qDebug() << a->doSimilarity_classify_pHash();
		
		/*imagelibs.push_back(info);*/
		imagelibs.push_back(info);
	}

	std::sort(imagelibs.begin(), imagelibs.end(), &imageSimilarity::sortMethod_pHash);

	////for (int i = 0; i < 5; i++) {
	//	ui->label->clear();
	//	QString filep = QString::fromStdString((imagelibs.begin() )->getPath());
	//	int width = ui->label->width();
	//	int height = ui->label->height();
	//	QImage image1(filep);
	//	QPixmap pixmap = QPixmap::fromImage(image1);
	//	QPixmap fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	//	//Qt::IgnoreAspectRatio, Qt::SmoothTransformation 填充 Qt::KeepAspectRatio, Qt::SmoothTransformation 按比例
	//	ui->label->setPixmap(fitpixmap);


		//qDebug() << (*(imagelibs.begin() + i))->getClassify_gray_hist();
		//qDebug() << (*(imagelibs.begin() + i))->getClassify_hist_with_split();
		//qDebug() << (*(imagelibs.begin() + i))->getClassify_aHash();
		//qDebug() << (*(imagelibs.begin() + i))->getClassify_pHash();

		//qDebug() << (imagelibs.begin() + i)->getClassify_gray_hist();
		//qDebug() << (imagelibs.begin() + i)->getClassify_hist_with_split();
		//qDebug() << (imagelibs.begin() + i)->getClassify_aHash();
		//qDebug() << (imagelibs.begin() + i)->getClassify_pHash();
	//}

	//ui->label->clear();
	//ui->label_2->clear();
	//ui->label_3->clear();
	//ui->label_4->clear();
	//ui->label_5->clear();
	//int width = ui->label->width();
	//int height = ui->label->height();

	//	QPixmap pixmap = QPixmap::fromImage(srcQimage);
	//	QPixmap fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	//	//Qt::IgnoreAspectRatio, Qt::SmoothTransformation 填充 Qt::KeepAspectRatio, Qt::SmoothTransformation 按比例
	//	ui->label->setPixmap(fitpixmap);
	//}

}

bool imageSimilarity::sortMethod_pHash(imageInfo aaa, imageInfo bbb) {
	return ((aaa.getClassify_pHash())<(bbb.getClassify_pHash()));
}