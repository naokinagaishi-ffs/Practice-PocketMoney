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
vector<FFGWorker> DataAccesser::CreatWorkerDataArray()
{
    
    //string dirPath = "C:\\�����������K_ShiftJis_";//�R�}���h���C��������͂���悤�ɂ��ƂŕύX
    string dirPath = "C:\\�����������K_ShiftJis";

    vector<string> filePaths(NULL);

    //vector��filePaths�Ƀp�X������܂�while���𔲂��Ȃ�
    while (filePaths.empty())
    {
        //cout << "�t�H���_�p�X����͂��Ă�������" << endl; 
        //cin >> dirPath ;

        //�t�H���_���̑S�Ă�txt�t�@�C���̃p�X���擾
        filePaths = SearchFiles(dirPath);

        cout << "�t�H���_���Ƀt�@�C�������݂��܂���." << endl;
    }

    vector<string> fileData(NULL);
    
    �t�@�C�����ƂɃC���X�^���X���쐬�i�����o�͍s���ƁA��s�����i�[����vector�j
    �t�@�C���C���X�^���X����AWorker�̃C���X�^���X���쐬






    try
    {
        //��s���z��ɕۑ�
        for (int i = 0; i < filePaths.size(); ++i)
        {
            fileData= ReadCSV(&filePaths[i]);

        }

    }
    catch (exception ex)
    {
        //CSV��ǂ߂Ȃ��������̏���(�z��ł��Ȃ���O)
        cout << "�t�@�C���ǂݍ��ݎ��ɁA��O�������܂���" << endl;
        //TODO::�C�x���g���O�e�L�X�g���O�̓�ɏo��
    }


    

    vector<FFGWorker> workerArray(NULL);


    return workerArray;
}

//
//CSV�t�@�C����ǂރ��\�b�h�B�P�v�f�ɂP�s���i�[����vector��Ԃ�
//
vector<string> DataAccesser::ReadCSV(string* filePath)
{
    vector<string> lineArray(NULL);

    std::ifstream ifs;  // �t�@�C���ǂݎ��p�X�g���[��
    ifs.open(*filePath);	// �t�@�C���I�[�v��

    if (ifs.fail()) 
    {
        // �t�@�C���I�[�v���Ɏ��s�����炻���ŏI��
        cout << "�t�@�C�����J���܂���" << endl;
        
        return lineArray; //�x�������o���āANULL�̔z���Ԃ�
    }

    while (!ifs.eof())
    {
        string tmpStr ;
        getline(ifs, tmpStr);
        lineArray.push_back(tmpStr.c_str());
    }
    return lineArray;
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
bool DataAccesser:: CreatFFGWorker(vector<string> strWorkerInfo, 
                                   FFGWorker* worker)
{
    
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

    worker->iD          = data[0];
    worker->name        = data[1];
    worker->pocketMoney = atoi(data[2].c_str());

    return worker;

}
