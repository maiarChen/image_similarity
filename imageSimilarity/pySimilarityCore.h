#pragma once
#include<iostream>
#include<python.h>
#include<QDebug>
#pragma execution_character_set("utf-8")
using namespace std;

class pySimilarityCore {
	
public:
	pySimilarityCore(string, string);
	~pySimilarityCore();

	float doSimilarity_classify_gray_hist();
	float doSimilarity_classify_hist_with_split();
	int doSimilarity_classify_aHash();
	int doSimilarity_classify_pHash();
private:
	string image1Path;
	string image2Path;
	PyObject* pModule;
};