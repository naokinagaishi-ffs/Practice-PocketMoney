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
//
bool DataAccesser::CreatWorkerDataArray(vector<FFGWorker*> workerArray)
{
    //�Ԃ�l�p�̕ϐ�
    bool resultJudge = true;
    
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
    vector<CSVDataInfo*> CSVDataInfos(NULL);
    if (filePaths.empty())
    {
        resultJudge = false;
        
    }
    else
    {
        for (int i = 0; i < filePaths.size(); ++i)
        {
            CSVDataInfo* tmp = CSVDataInfo::ReadCSV(&filePaths[i]);
            CSVDataInfos.push_back(tmp);
        }
    }
    

    //TODO::�t�@�C���C���X�^���X�̃����o�����킩�`�F�b�N�B
    //TODO::�ُ�ȃt�@�C���C���X�^���X�͍폜���Avector�̃C���f�b�N�X��������


    //����ȃt�@�C���C���X�^���X����̂�Worker�f�[�^���쐬
    for (int i = 0; i < CSVDataInfos.size(); ++i)
    {
        //FFGWorker tmp = CreatFFGWorker()
        //workerArray.push_back()

        int lineNum = CSVDataInfos[i]->lines.size();
        for (int j = 0; j < lineNum; ++j)
        {
            //vector<string> tmp = CSVDataInfos[i]->lines;
            ////tmp[j]
            //workerArray.push_back(CreatFFGWorker(tmp[j]));

            workerArray.push_back((CreatFFGWorker(CSVDataInfos[i]->lines)));

        }
       
    }


    return resultJudge;
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
FFGWorker* DataAccesser:: CreatFFGWorker(vector<string> strWorkerInfo)
{
    workerArray_ = new FFGWorker[strWorkerInfo.size()];
    vector<string> data(NULL);
    for (int i = 0; i < strWorkerInfo.size(); i++)
    {
        int p = 0;
        while ((p = strWorkerInfo[i].find(",")) != strWorkerInfo[i].npos)
        {
            data.push_back(strWorkerInfo[i].substr(0, p));//�J���}�Ԃ�data�Ɋi�[

            strWorkerInfo[i] = strWorkerInfo[i].substr(p + 1);//�J���}�����
        }

        data.push_back(strWorkerInfo[i]);

    }

    workerArray_->iD          = data[0];
    workerArray_->name        = data[1];
    workerArray_->pocketMoney = atoi(data[2].c_str());

    return workerArray_;

}
