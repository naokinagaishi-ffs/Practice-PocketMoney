//DataAccess�N���X�̎�����

#include "stdafx.h"
#include "DataAccess.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//�R���X�g���N�^
DataAccess::DataAccess()
{
	//������
	workerArray = NULL;
}

////�f�X�g���N�^
DataAccess::~DataAccess(){}


//�I�u�W�F�N�g�̔z�����郁�\�b�h
Worker* DataAccess::CreatWorkerData()
{
	string filePath = "C:\\Users\\naoki\\Desktop\\FFS\\�V�l���C��u\\IO\\ioSampleData.txt";
	
	vector<string> filedata = {""};//������
	try
	{
		//�t�@�C��IO�����B��s���z��ɕۑ�
		 filedata = ReadCSV(&filePath);
	}
	catch (exception ex)
	{
		//�t�@�C���ǂ߂Ȃ��������̏���(�z��ł��Ȃ���O)
		//cout << "�t�@�C���ǂݍ��ݎ��ɁA��O�������܂���" << endl;
	}

	vector<Worker> workerArray(filedata.size());
	vector<string> dataElement(2);
	
	//split�֐������
	//for (int i = 0; i < filedata.size(); ++i)
	//{
	//	string tmp = NULL;
	//	string tmp2 = filedata[i];
	//	while (getline(tmp2,tmp,','))
	//	{

	//	}
	//}


	Worker* rmp = NULL;
	return rmp;
	
}

//CSV�t�@�C����ǂރ��\�b�h
vector<string> DataAccess::ReadCSV(string* filePath)
{
	//������
	//workerArray = new FFGWorker[2];//[1]�ŗ�O�ƂԂ̂͂Ȃ��H�H
	//workerArray[0].name = "aaa";
	//workerArray[0].iD = "id01";
	//workerArray[0].pocketMoney = 1000;
	//workerArray[1].name = "bbb";
	//workerArray[1].iD = "id02";
	//workerArray[1].pocketMoney = 4000;

	//dataCount = sizeof(workerArray)/sizeof(workerArray[0]);//��肭�s���Ȃ�
	dataCount = 2;

	//string a = *filePath;
	std::ifstream ifs;  // �t�@�C���ǂݎ��p�X�g���[��
	ifs.open(*filePath);	// �t�@�C���I�[�v��

	if (ifs.fail()) {	// �t�@�C���I�[�v���Ɏ��s�����炻���ŏI��
		std::cerr << "�t�@�C�����J���܂���\n";
		exit(1);
	}

	string buf;	// �f�[�^�ꎞ�ۊǗp�z��

	int linenum = 0; // �f�[�^�̍s���𐔂���

	// �t�@�C������1�s���ǂݍ��݁A�s�������߂�
	while (getline(ifs,buf))
	{	
		linenum++;	// �s�����J�E���g���Ă���
		cout << buf.c_str() << endl;
		string a = buf;
		
	}

	std::cerr << "�ǂݍ��񂾍s�� = " << linenum << "\n";

	ifs.clear(); // �t�@�C�������ɓ��B�Ƃ����t���O���N���A
	ifs.seekg(0, std::ios::beg);	// �t�@�C���擪�ɖ߂�

	//string* lineArray;
	//lineArray = new string[linenum];	// �s�� linenum ���̔z��𓮓I�Ɋm��

	vector<string> lineArray(linenum);

	for (int i = 0; i<linenum; i++) 
	{
		string tmp;
		getline(ifs, tmp);
		lineArray[i] = tmp;
	}

	return lineArray;
}

