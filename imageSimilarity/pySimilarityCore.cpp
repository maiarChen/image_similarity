#include "pySimilarityCore.h"
#include<QDebug>
pySimilarityCore::pySimilarityCore(string Path1) {
	image1Path = Path1;
	Py_Initialize();    // 初始化

	// 将Python工作路径切换到待调用模块所在目录，一定要保证路径名的正确性
	string path = "./seemImg.py";
	string chdir_cmd = string("sys.path.append(\"") + path + "\")";
	const char* cstr_cmd = chdir_cmd.c_str();
	PyRun_SimpleString(cstr_cmd);

	// 加载模块
	PyObject* moduleName = PyString_FromString("seemImg"); //模块名，不是文件名
	pModule = PyImport_Import(moduleName);
	if (!pModule) // 加载模块失败
	{
		qDebug() << "[ERROR] Python get module failed." ;
	}
	qDebug() << "[INFO] Python get module succeed." ;
}
pySimilarityCore::~pySimilarityCore() {
	//delete pModule;
	//Py_Finalize();
}

void pySimilarityCore::getPath2(string Path2) {
	image2Path = Path2;
}

float pySimilarityCore::doSimilarity_classify_gray_hist() {
	// 加载函数
	PyObject* pv = PyObject_GetAttrString(pModule, "doSimilarity_classify_gray_hist");
	if (!pv || !PyCallable_Check(pv))  // 验证是否加载成功
	{
		qDebug() << "[ERROR] Can't find funftion (doSimilarity_classify_gray_hist)" ;
	}
	qDebug() << "[INFO] Get function (doSimilarity_classify_gray_hist) succeed." ;

	// 设置参数
	PyObject* args = PyTuple_New(2);   // 2个参数
	PyObject* arg1 = Py_BuildValue("s", image1Path.c_str());    // 参数一
	PyObject* arg2 = Py_BuildValue("s", image2Path.c_str());    // 参数二

	PyTuple_SetItem(args, 0, arg1);
	PyTuple_SetItem(args, 1, arg2);

	// 调用函数
	PyObject* pRet = PyObject_CallObject(pv, args);

	// 获取参数
	float result;
	if (pRet) {
		PyArg_Parse(pRet, "f", &result);//转换成float型变量
		qDebug() << "基于灰度化直方图相似度:" << result ;
	}
	else {
		qDebug() << "获取失败" ;
	}
	return result;
}
float pySimilarityCore::doSimilarity_classify_hist_with_split(){
	PyObject* pv = PyObject_GetAttrString(pModule, "doSimilarity_classify_hist_with_split");
	if (!pv || !PyCallable_Check(pv))  // 验证是否加载成功
	{
		qDebug() << "[ERROR] Can't find funftion (doSimilarity_classify_hist_with_split)" ;
	}
	qDebug() << "[INFO] Get function (doSimilarity_classify_hist_with_split) succeed." ;

	// 设置参数
	PyObject* args = PyTuple_New(2);   // 2个参数
	PyObject* arg1 = Py_BuildValue("s", image1Path.c_str());    // 参数一设为4
	PyObject* arg2 = Py_BuildValue("s", image2Path.c_str());    // 参数二设为3
	PyTuple_SetItem(args, 0, arg1);
	PyTuple_SetItem(args, 1, arg2);

	// 调用函数
	PyObject* pRet = PyObject_CallObject(pv, args);

	float result;
	if (pRet) {
		PyArg_Parse(pRet, "f", &result);//float型变量
		qDebug() << "分离各通道直方图后的相似度:" << result ;
	}
	else {
		qDebug() << "获取失败" ;
	}
	return result;
}
int pySimilarityCore::doSimilarity_classify_aHash() {
	PyObject* pv = PyObject_GetAttrString(pModule, "doSimilarity_classify_aHash");
	if (!pv || !PyCallable_Check(pv))  // 验证是否加载成功
	{
		qDebug() << "[ERROR] Can't find funftion (doSimilarity_classify_aHash)" ;
	}
	qDebug() << "[INFO] Get function (doSimilarity_classify_aHash) succeed." ;

	// 设置参数
	PyObject* args = PyTuple_New(2);   // 2个参数
	PyObject* arg1 = Py_BuildValue("s", image1Path.c_str());    // 参数一
	PyObject* arg2 = Py_BuildValue("s", image2Path.c_str());    // 参数二
	PyTuple_SetItem(args, 0, arg1);
	PyTuple_SetItem(args, 1, arg2);

	// 调用函数
	PyObject* pRet = PyObject_CallObject(pv, args);

	int result;
	if (pRet) {
		PyArg_Parse(pRet, "i", &result);//int型变量
		qDebug() << "aHash:" << result ;
	}
	else {
		qDebug() << "获取失败" ;
	}
	return result;
}
int pySimilarityCore::doSimilarity_classify_pHash() {
	PyObject* pv = PyObject_GetAttrString(pModule, "doSimilarity_classify_pHash");
	if (!pv || !PyCallable_Check(pv))  // 验证是否加载成功
	{
		qDebug() << "[ERROR] Can't find funftion (doSimilarity_classify_pHash)" ;
	}
	qDebug() << "[INFO] Get function (doSimilarity_classify_pHash) succeed." ;

	// 设置参数
	PyObject* args = PyTuple_New(2);   // 2个参数
	PyObject* arg1 = Py_BuildValue("s", image1Path.c_str());    // 参数一
	PyObject* arg2 = Py_BuildValue("s", image2Path.c_str());    // 参数二
	PyTuple_SetItem(args, 0, arg1);
	PyTuple_SetItem(args, 1, arg2);

	// 调用函数
	PyObject* pRet = PyObject_CallObject(pv, args);

	int result;
	if (pRet) {
		PyArg_Parse(pRet, "i", &result);//int型变量
		qDebug() << "pHash:" << result ;
	}
	else {
		qDebug() << "获取失败" ;
	}
	return result;
}