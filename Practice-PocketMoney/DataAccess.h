#pragma once
#ifndef DATAACCESS
#define DATAACCESS

#include "Worker.h"

//�f�[�^�ɃA�N�Z�X����N���X�̐錾

class DataAccess
{
public:
	//�R���X�g���N�^
	DataAccess(){}

	//�f�X�g���N�^
	~DataAccess(){}

	//�t�@�C������f�[�^���擾���郁�\�b�h
	void CreatWorkerData();
	void ReadCSV(string filepath);


public:
	int dataCount;			//�z��̐��@=�@�l��
	FFGWorker* workerArray; //worker�^�̃|�C���^�B���I�z��Ɏg���B	

};
#endif // !DATAACCESS
