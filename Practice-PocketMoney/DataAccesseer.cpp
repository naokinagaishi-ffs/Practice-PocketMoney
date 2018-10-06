//DataAccess�N���X�̎�����

#include "stdafx.h"
#include "DataAccesser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <Windows.h>
#include <locale> 
#include <codecvt> 
#include <cstdio>
#include "CSVDataInfo.h"

using namespace std;

//
//�R���X�g���N�^
//
DataAccesser::DataAccesser()
{
	//������
    this->workerArray_=NULL;
}

//
//�f�X�g���N�^
//
DataAccesser::~DataAccesser()
{
    delete[] this->workerArray_;
    this->workerArray_ = NULL;

}

//
//�I�u�W�F�N�g�̔z�����郁�\�b�h
vector<FFGWorker*> DataAccesser::CreatWorkerDataArray(vector<FFGWorker*> workerArray)
{
    //�Ԃ�l�p�̕ϐ�
    bool result = true;
    
    //string dirPath = "C:\\�����������K_ShiftJis_";//�R�}���h���C��������͂���悤�ɂ��ƂŕύX
    //string dirPath = "C:\\�����������K_ShiftJis";
    string dirPath = "C:\\�����������K_ShiftJis_";


    vector<string> filePaths(NULL);

    //vector��filePaths�Ƀp�X������܂�while���𔲂��Ȃ�
    while (filePaths.empty())
    {
        //cout << "�t�H���_�p�X����͂��Ă�������" << endl; 
        //cin >> dirPath ;

        //�t�H���_���̑S�Ă�txt�t�@�C���̃p�X���擾
        filePaths = SearchFiles(dirPath);
        if (filePaths.empty())
        {
            cout << "�t�H���_���Ƀt�@�C�������݂��܂���." << endl;
            cout << "�t�H���_��������x���͂��Ă�������" << endl;
        }
    }

    vector<string> fileData(NULL);
    
    //�t�@�C���C���X�^���X���쐬���Avector�Ńn���h�����O�B
    vector<CSVDataInfo*> csvDataInfos(NULL);
    if (filePaths.empty())
    {
        result = false;
        
    }
    else
    {
        for (int i = 0; i < filePaths.size(); ++i)
        {
            CSVDataInfo* tmp = CSVDataInfo::ReadCSV(&filePaths[i]);
            csvDataInfos.push_back(tmp);
        }
    }
    

    //TODO::�t�@�C���C���X�^���X�̃����o�����킩�`�F�b�N�B
    //TODO::�ُ�ȃt�@�C���C���X�^���X�͍폜���Avector�̃C���f�b�N�X��������


    //����ȃt�@�C���C���X�^���X����̂�Worker�f�[�^���쐬
    for (int i = 0; i < csvDataInfos.size(); ++i)
    {
        vector<string> tmpData = csvDataInfos[i]->lines;

        int lineNum = tmpData.size();
        for (int j = 0; j < lineNum - 1; ++j)
        {
            
            workerArray.push_back((CreatFFGWorker(tmpData[j])));

        }
       
    }
    
    //csvDataInsos�Ɋi�[����Ă���f�[�^�����
    for (unsigned int i = 0; i < csvDataInfos.size(); ++i)
    {
        if (csvDataInfos[i] != NULL)
        {
            delete csvDataInfos[i];
            csvDataInfos[i] = NULL;
        }
    }

    return workerArray;
}


//
//�w��t�H���_������txt�t�@�C�����������郁�\�b�h�B�P�v�f�ɂP�t�@�C���̃p�X���܂�
//
vector<string>DataAccesser::SearchFiles(string& dirPath)
{

	HANDLE hFind;
	WIN32_FIND_DATA win32fd;

	vector<string> fileNames;   
	string extention = "txt";
     
	string searchName = dirPath + "\\*." + extention;


     hFind = FindFirstFile(searchName.c_str(), &win32fd);
     
     if (hFind == INVALID_HANDLE_VALUE)
     {
         //���O�����o�͂��āA��̔z���Ԃ�
         cout << "�t�H���_�܂��́A�t�@�C�������݂��܂���" << endl;
     }
     else
     {
         do
         {
             fileNames.push_back(dirPath + "\\" + win32fd.cFileName);

         } while (FindNextFile(hFind, &win32fd));
     }

     FindClose(hFind);

     return fileNames;
}

//
//data����FFGWorker1�l���̃C���X�^���X���쐬���郁�\�b�h
//
FFGWorker* DataAccesser:: CreatFFGWorker(string strWorkerInfo)
{
    workerArray_ = new FFGWorker[strWorkerInfo.size()];
    vector<string> data(NULL);
    data = Split(strWorkerInfo,',');

    workerArray_->iD          = data[0];
    workerArray_->name        = data[1];
    workerArray_->pocketMoney = atoi(data[2].c_str());

    return workerArray_;

}

vector<string> DataAccesser::Split(const string& input, char delimiter)
{
    istringstream stream(input);

    string field;
    vector<string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}
