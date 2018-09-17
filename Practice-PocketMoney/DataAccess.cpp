//DataAccess�N���X�̎�����

#include "stdafx.h"
#include "DataAccess.h"
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


//�R���X�g���N�^
DataAccess::DataAccess()
{
	//������
	workerArray = NULL;
}

////�f�X�g���N�^
DataAccess::~DataAccess(){}

//
//�I�u�W�F�N�g�̔z�����郁�\�b�h
//
vector<FFGWorker> DataAccess::CreatWorkerData()
{
    //string dirPath = "C:\\�����������K_";
    string dirPath = "C:\\�����������K_ShiftJis";


    //string dirPath = "C:\\test11";



    vector<string> filePaths  ;//������
    vector<string> fileData ;
    try
    {
        //�t�H���_���̑S�Ă�txt�t�@�C���̃p�X���擾
        filePaths = SearchFiles(dirPath);

    }
    catch (exception ex)
    {
        //�t�@�C���ǂ߂Ȃ��������̏���(�z��ł��Ȃ���O)
        cout << "�t�@�C���ǂݍ��ݎ��ɁA��O�������܂���" << endl;
        //TODO::�C�x���g���O�e�L�X�g���O�̓�ɏo��
    }


    //��s���z��ɕۑ�
    for (int i = 0; i < filePaths.size(); ++i)
    {
        
        fileData = ReadCSV(&filePaths[i]);
    }


    vector<FFGWorker> workerArray;

    //for (int i = 0; i < filedata.size(); ++i)
    //{
    //    vector<string> data;
    //    int p = 0;
    //    while ((p = filedata[i].find(",")) != filedata[i].npos)
    //    {
    //        data.push_back(filedata[i].substr(0, p));//�J���}�Ԃ�data�Ɋi�[

    //        filedata[i] = filedata[i].substr(p + 1);//�J���}�����
    //    }

    //    data.push_back(filedata[i]);

    //    FFGWorker tmpWorker ;
    //    tmpWorker.iD = data[0];//ID
    //    tmpWorker.name = data[1];//���O
    //    tmpWorker.pocketMoney = atoi(data[2].c_str());//����

    //    workerArray.push_back(tmpWorker);
    //}

    return workerArray;
}

//
//CSV�t�@�C����ǂރ��\�b�h
//
vector<string> DataAccess::ReadCSV(string* filePath)
{

    std::ifstream ifs;  // �t�@�C���ǂݎ��p�X�g���[��
    ifs.open(*filePath);	// �t�@�C���I�[�v��

    if (ifs.fail()) {	// �t�@�C���I�[�v���Ɏ��s�����炻���ŏI��
        std::cerr << "�t�@�C�����J���܂���\n";
        
        vector<string> empty(0); 
        return empty; //�x�������o���āA��̔z���Ԃ�
    }

    string buf;	// �f�[�^�ꎞ�ۊǗp�z��

    int linenum = 0; // �f�[�^�̍s���𐔂���

    // �t�@�C������1�s���ǂݍ��݁A�s�������߂�
    while (getline(ifs, buf))
    {
        linenum++;	
    }

    ifs.clear(); // �t�@�C�������ɓ��B�Ƃ����t���O���N���A
    ifs.seekg(0, std::ios::beg);	// �t�@�C���擪�ɖ߂�

    vector<string> lineArray(linenum);

    for (int i = 0; i < linenum; i++)
    {
        getline(ifs, lineArray[i]);
    }

    return lineArray;
}

//
//�w��t�H���_������txt�t�@�C�����������郁�\�b�h
//
vector<string>DataAccess::SearchFiles(string& dirPath)
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