//DataAccess�N���X�̎�����

#include "stdafx.h"
#include "DataAccess.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
vector<FFGWorker> DataAccess::CreatWorkerData()
{
    string filePath = "C:\\�����������K\\ioSampleData.txt";

    vector<string> filedata = { "" };//������
    try
    {
        //�t�@�C��IO�����B��s���z��ɕۑ�
        filedata = ReadCSV(&filePath);
    }
    catch (exception ex)
    {
        //�t�@�C���ǂ߂Ȃ��������̏���(�z��ł��Ȃ���O)
        cout << "�t�@�C���ǂݍ��ݎ��ɁA��O�������܂���" << endl;
        //�C�x���g���O�̏o��

    }

    vector<FFGWorker> workerArray;

    for (int i = 0; i < filedata.size(); ++i)
    {
        vector<string> data;
        int p = 0;
        while ((p = filedata[i].find(",")) != filedata[i].npos)
        {
            data.push_back(filedata[i].substr(0, p));//�J���}�Ԃ�data�Ɋi�[

            filedata[i] = filedata[i].substr(p + 1);//�J���}�����
        }

        data.push_back(filedata[i]);

        FFGWorker a;
        a.iD = data[0];//ID
        a.name = data[1];//���O
        a.pocketMoney = atoi(data[2].c_str());//����

        workerArray.push_back(a);
    }

    return workerArray;
}
//CSV�t�@�C����ǂރ��\�b�h
vector<string> DataAccess::ReadCSV(string* filePath)
{

    std::ifstream ifs;  // �t�@�C���ǂݎ��p�X�g���[��
    ifs.open(*filePath);	// �t�@�C���I�[�v��

    if (ifs.fail()) {	// �t�@�C���I�[�v���Ɏ��s�����炻���ŏI��
        std::cerr << "�t�@�C�����J���܂���\n";
        exit(1);
    }

    string buf;	// �f�[�^�ꎞ�ۊǗp�z��

    int linenum = 0; // �f�[�^�̍s���𐔂���

    // �t�@�C������1�s���ǂݍ��݁A�s�������߂�
    while (getline(ifs, buf))
    {
        linenum++;	// �s�����J�E���g���Ă���
    }

    std::cerr << "�ǂݍ��񂾍s�� = " << linenum << "\n";

    ifs.clear(); // �t�@�C�������ɓ��B�Ƃ����t���O���N���A
    ifs.seekg(0, std::ios::beg);	// �t�@�C���擪�ɖ߂�

    vector<string> lineArray(linenum);

    for (int i = 0; i < linenum; i++)
    {
        
        getline(ifs, lineArray[i]);
        
    }

    return lineArray;
}

