#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_imageSimilarity.h"

class imageSimilarity : public QMainWindow
{
	Q_OBJECT

public:
	imageSimilarity(QWidget *parent = Q_NULLPTR);

private:
	Ui::imageSimilarityClass ui;
};
