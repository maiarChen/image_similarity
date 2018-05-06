#pragma once
#include<iostream>
using namespace std;
class imageInfo
{
public:
	imageInfo();
	~imageInfo();
	void setClassify_gray_hist(float);
	void setClassify_hist_with_split(float);
	void setClassify_aHash(int);
	void setClassify_pHash(int);
	void setPath(string);

	float getClassify_gray_hist();
	float getClassify_hist_with_split();
	int getClassify_aHash();
	int getClassify_pHash();
	string getPath();

private:
	string path;
	float gray_hist;
	float hist_with_split;
	int aHash;
	int pHash;
};

