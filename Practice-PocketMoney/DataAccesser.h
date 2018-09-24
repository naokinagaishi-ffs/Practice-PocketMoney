//
//DataAccess�N���X�̐錾
//�f�[�^�A�N�Z�X�Ɋւ��鏈���͂��̃N���X�̐Ӗ�
//
#pragma once
#ifndef DATAACCESSER
#define DATAACCESSER

#include "Worker.h"
#include "FFGWorker.h"
#include <vector>



class DataAccesser
{
public:
     //
	//�R���X�g���N�^
     //
	DataAccesser() ;


     //
	//�f�X�g���N�^
     //
	~DataAccesser();

#pragma region public���\�b�h
     //
     //Worker�^�̃f�[�^�z�����郁�\�b�h
     //
     vector<FFGWorker> CreatWorkerDataArray();

#pragma endregion

#pragma region private ���\�b�h
private:
    //�t�@�C������f�[�^���擾���郁�\�b�h
    vector<string> ReadCSV(string* filPpath);

    //�w��t�H���_����.txt�t�@�C������������N���X
    vector<string> SearchFiles(string& dirPath);

    //vector<string> => vector<FFGWorker>
    bool CreatFFGWorker(vector<string> strWorkerInfo, FFGWorker* worker);
#pragma endregion


#pragma region �����o�ϐ�
private:

    //
    //�z��̐擪�|�C���^�BFFGWorker�̃C���X�^���X��ێ�
    //Getter�̂�
    FFGWorker* workerArray_;

#pragma endregion

#pragma region Getter
public:
    //
    //FFGworker�z��̐擪�|�C���^��Ԃ�
    //
    FFGWorker* WorekrArray() { return workerArray_; }

#pragma endregion



};
#endif // !DATAACCESS
