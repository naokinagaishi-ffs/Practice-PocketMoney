//DataAccess�N���X�̎�����

#include "stdafx.h"
#include "DataAccess.h"
#include "FFGWorker.h"
#include <iostream>
#include <fstream>
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

	char buf[256];	// �f�[�^�ꎞ�ۊǗp�z��

	int linenum = 0; // �f�[�^�̍s���𐔂���

	while (ifs.getline(buf, sizeof(buf))) {	// �t�@�C������1�s���ǂݍ���
		linenum++;	// �s�����J�E���g���Ă���
	}

	std::cerr << "�ǂݍ��񂾍s�� = " << linenum << "\n";

	ifs.clear(); // �t�@�C�������ɓ��B�Ƃ����t���O���N���A
	ifs.seekg(0, std::ios::beg);	// �t�@�C���擪�ɖ߂�

	char* lineArray;
	lineArray = new char[linenum];	// �s�� linenum ���̔z��𓮓I�Ɋm��

	for (int i = 0; i<linenum; i++) {
		ifs.getline(buf, sizeof(buf));	// ��s�ǂݍ���Łc
		char* a = buf;
		lineArray[i] = *buf;// �����z��Ɋi�[
	}

	// ����ŁAarr[0]�`arr[linenum-1] �Ɍv linenum �̃f�[�^���i�[���ꂽ

}

