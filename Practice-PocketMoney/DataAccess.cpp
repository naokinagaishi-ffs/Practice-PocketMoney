//DataAccess�N���X�̎�����

#include "stdafx.h"
#include "DataAccess.h"
#include "FFGWorker.h"
#include <iostream>
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
void DataAccess::CreatWorkerData()
{
	string filePath = "C:\\Users\\naoki\\Desktop\\FFS\\�V�l���C��u\\IO\\ioSampleData.txt";

	try
	{
		//�t�@�C��IO����
	
		ReadCSV(&filePath);
		
	}
	catch (exception ex)
	{
		//�t�@�C���ǂ߂Ȃ��������̏���(�z��ł��Ȃ���O)
		//cout << "�t�@�C���ǂݍ��ݎ��ɁA��O�������܂���" << endl;
	}
	
}

//CSV�t�@�C����ǂރ��\�b�h
void DataAccess::ReadCSV(string* filePath)
{
	//������
	workerArray = new FFGWorker[2];//[1]�ŗ�O�ƂԂ̂͂Ȃ��H�H
	workerArray[0].name = "aaa";
	workerArray[0].iD = "id01";
	workerArray[0].pocketMoney = 1000;
	workerArray[1].name = "bbb";
	workerArray[1].iD = "id02";
	workerArray[1].pocketMoney = 4000;

	//dataCount = sizeof(workerArray)/sizeof(workerArray[0]);//��肭�s���Ȃ�
	dataCount = 2;

	//string a = *filePath;

}

