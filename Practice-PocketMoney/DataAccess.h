//
//DataAccess�N���X�̐錾
//�f�[�^�A�N�Z�X�Ɋւ��鏈���͂��̃N���X�̐Ӗ�
//
#pragma once
#ifndef DATAACCESS
#define DATAACCESS

#include "Worker.h"
#include "FFGWorker.h"
#include <vector>



class DataAccess
{
public:
	//�R���X�g���N�^
	DataAccess() ;

	//�f�X�g���N�^
	~DataAccess();

	//Worker�^�̃f�[�^�z�����郁�\�b�h
    vector<FFGWorker> CreatWorkerData();

private:
	//�t�@�C������f�[�^���擾���郁�\�b�h
	vector<string> ReadCSV(string* filPpath);

	//�w��t�H���_����.txt�t�@�C������������N���X
	vector<string> SearchFiles(string& dirPath);


public:
	//int dataCount;			//�z��̐��@=�@�l��
	FFGWorker* workerArray; //worker�^�̃|�C���^�B���I�z��Ɏg���B	

};
#endif // !DATAACCESS
