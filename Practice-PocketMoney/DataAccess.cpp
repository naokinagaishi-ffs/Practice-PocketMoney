//DataAccess�N���X�̎�����

#include "stdafx.h"
#include "DataAccess.h"
#include "FFGWorker.h"
using namespace std;

//�R���X�g���N�^
DataAccess::DataAccess()
{
	//������
	workerArray = NULL;
}

//�f�X�g���N�^
DataAccess::~DataAccess(){}

void DataAccess::CreatWorkerData()
{
	try
	{
		//�t�@�C��IO����
		ReadCSV("�t�@�C���p�X�����");
		
	}
	catch (exception ex)
	{
		//�t�@�C���ǂ߂Ȃ��������̏���(�z��ł��Ȃ���O)
		//cout << "�t�@�C���ǂݍ��ݎ��ɁA��O�������܂���" << endl;
	}
	
}

void DataAccess::ReadCSV(string filepath)
{
	//������
	workerArray = new FFGWorker[1];
	workerArray[0].name = "aaa";
	workerArray[0].iD = "id01";
	workerArray[0].name = "1000";
	workerArray[1].name = "bbb";
	workerArray[1].iD = "id02";
	workerArray[1].name = "4000";

	dataCount = sizeof(workerArray)/sizeof(workerArray[0]);

}

