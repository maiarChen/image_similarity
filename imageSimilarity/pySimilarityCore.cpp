#include "pySimilarityCore.h"

pySimilarityCore::pySimilarityCore(string Path1) {
	image1Path = Path1;
	Py_Initialize();    // ��ʼ��

	// ��Python����·���л���������ģ������Ŀ¼��һ��Ҫ��֤·��������ȷ��
	//string path = "E:\Item\C++\imageSimilarity\imageSimilarity\seemImg.py";
	//string chdir_cmd = string("sys.path.append(\"") + path + "\")";
	//const char* cstr_cmd = chdir_cmd.c_str();
	//PyRun_SimpleString(cstr_cmd);

	// ����ģ��
	PyObject* moduleName = PyString_FromString("seemImg"); //ģ�����������ļ���
	pModule = PyImport_Import(moduleName);
	if (!pModule) // ����ģ��ʧ��
	{
		qDebug() << "[ERROR] Python get module failed." << endl;
	}
	qDebug() << "[INFO] Python get module succeed." << endl;
}
pySimilarityCore::~pySimilarityCore() {
	Py_Finalize();
	delete this;
}

void pySimilarityCore::getPath2(string Path2) {
	image2Path = Path2;
}

float pySimilarityCore::doSimilarity_classify_gray_hist() {
	// ���غ���
	PyObject* pv = PyObject_GetAttrString(pModule, "doSimilarity_classify_gray_hist");
	if (!pv || !PyCallable_Check(pv))  // ��֤�Ƿ���سɹ�
	{
		qDebug() << "[ERROR] Can't find funftion (doSimilarity_classify_gray_hist)" << endl;
	}
	qDebug() << "[INFO] Get function (doSimilarity_classify_gray_hist) succeed." << endl;

	// ���ò���
	PyObject* args = PyTuple_New(2);   // 2������
	PyObject* arg1 = Py_BuildValue("s", image1Path.c_str());    // ����һ
	PyObject* arg2 = Py_BuildValue("s", image2Path.c_str());    // ������

	PyTuple_SetItem(args, 0, arg1);
	PyTuple_SetItem(args, 1, arg2);

	// ���ú���
	PyObject* pRet = PyObject_CallObject(pv, args);

	// ��ȡ����
	float result;
	if (pRet) {
		PyArg_Parse(pRet, "f", &result);//ת����float�ͱ���
		qDebug() << "���ڻҶȻ�ֱ��ͼ���ƶ�:" << result << endl;
	}
	else {
		qDebug() << "��ȡʧ��" <<endl;
	}
	return result;
}
float pySimilarityCore::doSimilarity_classify_hist_with_split(){
	PyObject* pv = PyObject_GetAttrString(pModule, "doSimilarity_classify_hist_with_split");
	if (!pv || !PyCallable_Check(pv))  // ��֤�Ƿ���سɹ�
	{
		qDebug() << "[ERROR] Can't find funftion (doSimilarity_classify_hist_with_split)" << endl;
	}
	qDebug() << "[INFO] Get function (doSimilarity_classify_hist_with_split) succeed." << endl;

	// ���ò���
	PyObject* args = PyTuple_New(2);   // 2������
	PyObject* arg1 = Py_BuildValue("s", image1Path.c_str());    // ����һ��Ϊ4
	PyObject* arg2 = Py_BuildValue("s", image2Path.c_str());    // ��������Ϊ3
	PyTuple_SetItem(args, 0, arg1);
	PyTuple_SetItem(args, 1, arg2);

	// ���ú���
	PyObject* pRet = PyObject_CallObject(pv, args);

	float result;
	if (pRet) {
		PyArg_Parse(pRet, "f", &result);//float�ͱ���
		qDebug() << "�����ͨ��ֱ��ͼ������ƶ�:" << result << endl;
	}
	else {
		qDebug() << "��ȡʧ��" << endl;
	}
	return result;
}
int pySimilarityCore::doSimilarity_classify_aHash() {
	PyObject* pv = PyObject_GetAttrString(pModule, "doSimilarity_classify_aHash");
	if (!pv || !PyCallable_Check(pv))  // ��֤�Ƿ���سɹ�
	{
		qDebug() << "[ERROR] Can't find funftion (doSimilarity_classify_aHash)" << endl;
	}
	qDebug() << "[INFO] Get function (doSimilarity_classify_aHash) succeed." << endl;

	// ���ò���
	PyObject* args = PyTuple_New(2);   // 2������
	PyObject* arg1 = Py_BuildValue("s", image1Path.c_str());    // ����һ
	PyObject* arg2 = Py_BuildValue("s", image2Path.c_str());    // ������
	PyTuple_SetItem(args, 0, arg1);
	PyTuple_SetItem(args, 1, arg2);

	// ���ú���
	PyObject* pRet = PyObject_CallObject(pv, args);

	int result;
	if (pRet) {
		PyArg_Parse(pRet, "i", &result);//int�ͱ���
		qDebug() << "aHash:" << result << endl;
	}
	else {
		qDebug() << "��ȡʧ��" << endl;
	}
	return result;
}
int pySimilarityCore::doSimilarity_classify_pHash() {
	PyObject* pv = PyObject_GetAttrString(pModule, "doSimilarity_classify_pHash");
	if (!pv || !PyCallable_Check(pv))  // ��֤�Ƿ���سɹ�
	{
		qDebug() << "[ERROR] Can't find funftion (doSimilarity_classify_pHash)" << endl;
	}
	qDebug() << "[INFO] Get function (doSimilarity_classify_pHash) succeed." << endl;

	// ���ò���
	PyObject* args = PyTuple_New(2);   // 2������
	PyObject* arg1 = Py_BuildValue("s", image1Path.c_str());    // ����һ
	PyObject* arg2 = Py_BuildValue("s", image2Path.c_str());    // ������
	PyTuple_SetItem(args, 0, arg1);
	PyTuple_SetItem(args, 1, arg2);

	// ���ú���
	PyObject* pRet = PyObject_CallObject(pv, args);

	int result;
	if (pRet) {
		PyArg_Parse(pRet, "i", &result);//int�ͱ���
		qDebug() << "pHash:" << result << endl;
	}
	else {
		qDebug() << "��ȡʧ��" << endl;
	}
	return result;
}