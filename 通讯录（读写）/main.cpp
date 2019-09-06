#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAX 100

using namespace std;


struct Person
{
    char m_Name [MAX];     //����
    int m_Sex;         //�Ա�(1--��   2--Ů)
    int m_Age;         //����
    char m_Number [MAX];   //����
};

//��ʾ���˵�
void show_menu()
{
    cout<<"************************"<<endl;
    cout<<"***** 1.�����ϵ�� *****"<<endl;
    cout<<"***** 2.��ʾ��ϵ�� *****"<<endl;
    cout<<"***** 3.ɾ����ϵ�� *****"<<endl;
    cout<<"***** 4.������ϵ�� *****"<<endl;
    cout<<"***** 5.�޸���ϵ�� *****"<<endl;
    cout<<"***** 6.�����ϵ�� *****"<<endl;
    cout<<"***** 0.�˳�ͨѶ¼ *****"<<endl;
    cout<<"************************"<<endl;
    cout<<"������������в�������Ӧ�ı�ţ�"<<endl;
}

struct AddressList
{
    Person personArray[MAX];    //��ϵ������
    int m_Size;                 //��ϵ������

};

//1.�����ϵ��
void add_Person(AddressList * abs)
{
        //�ж�ͨѶ¼�Ƿ���
    if(abs->m_Size >= MAX)
    {
        cout<<"���ʧ�ܣ���ϵ��������"<<endl;
        return;
    }
    else
    {
        //�����ϵ��
        //�������
        char name[MAX];
        cout<<"������������"<<endl;
        cin>>name;
        strcpy(abs->personArray[abs->m_Size].m_Name,name);

        //����Ա�
        int sex = 0;
        cout<<"�������Ա�1--��   2--Ů����"<<endl;
            //�ж������Ա�
        while(true) {
            cin>>sex;
            if(sex==1 || sex==2) {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
                cout<<"������������������"<<endl;
        }

        //�������
        int age = 0;
        cout<<"���������䣺"<<endl;
            //�ж���������
        while(true) {
            cin>>age;
            if(age>=0)  {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            else
                cout<<"�����������������룺"<<endl;
        }

        //��Ӻ���
        char number[MAX];
        cout<<"������绰���룺"<<endl;
        cin>>number;
        strcpy(abs->personArray[abs->m_Size].m_Number,number);

        abs->m_Size++;
        cout<<"��ӳɹ���"<<endl;
        system("pause");
        system("cls");
    }
}

//2.��ʾ������ϵ��
void show_Person(AddressList * abs)
{
    //�ж���ϵ�������Ƿ�Ϊ0
    if(abs->m_Size == 0)
        cout<<"��ϵ��Ϊ�ա�"<<endl;
    else
    {
        for(int i=0; i<abs->m_Size; i++)    {
            cout<<"������"<<abs->personArray[i].m_Name<<"\t"
                <<"�Ա�"<<(abs->personArray[i].m_Sex == 1 ?"��":"Ů")<<"\t"
                <<"���䣺"<<abs->personArray[i].m_Age<<"\t\t"
                <<"���룺"<<abs->personArray[i].m_Number<<endl;
        }
    }
    system("pause");
    system("cls");
}

//���ͨѶ¼����ϵ�˴���
int isExist(AddressList * abs, char name[MAX])
{
    for(int i=0; i<abs->m_Size; i++)    {
        if(strcmp(abs->personArray[i].m_Name,name)==0)  {
            return i;
        }
    }
    return -1;
}

//3.ɾ����ϵ��
void delete_Person(AddressList * abs)
{
    cout<<"����������Ҫɾ������ϵ�˵�������"<<endl;
    char name[MAX];
    cin>>name;
    //���ͨѶ¼����ϵ�˴���
    int temp = isExist(abs, name);

    if(temp == -1)
        cout<<"���޴��ˣ�"<<endl;
    else        //����temp��ʾҪɾ����ϵ�˵��±�
    {
        for(int i=temp; i<abs->m_Size; i++) {
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;     //����ͨѶ¼��ϵ����
        cout<<"ɾ���ɹ���"<<endl;
    }
    system("pause");
    system("cls");
}

//4.������ϵ��
void find_Person(AddressList * abs)
{
    cout<<"������������ҵ���ϵ��������"<<endl;
    char name[MAX];
    cin>>name;

    int temp = isExist(abs, name);

    if(temp == -1)
        cout<<"���޴��ˣ�"<<endl;
    else
    {
        cout<<"������"<<abs->personArray[temp].m_Name<<"\t"
            <<"�Ա�"<<(abs->personArray[temp].m_Sex == 1 ?"��":"Ů")<<"\t"
            <<"���䣺"<<abs->personArray[temp].m_Age<<"\t\t"
            <<"���룺"<<abs->personArray[temp].m_Number<<endl;
    }
    system("pause");
    system("cls");
}

//5.�޸���ϵ��
void modify_Person(AddressList * abs)
{
    cout<<"�����������޸ĵ���ϵ��������"<<endl;
    char name[MAX];
    cin>>name;

    int temp = isExist(abs, name);

    if(temp == -1)
        cout<<"���޴��ˣ�"<<endl;
    else
    {
        //����
        cout<<"������������"<<endl;
        char name[MAX];
        cin>>name;
        strcpy(abs->personArray[temp].m_Name,name);
        //�Ա�
        cout<<"�������Ա�1--��   2--Ů����"<<endl;
        int sex = 0;
        while(true) {
            cin>>sex;
            if(sex==1 || sex==2) {
                abs->personArray[temp].m_Sex = sex;
                break;
            }
            else
                cout<<"������������������"<<endl;
        }
        //����
        cout<<"���������䣺"<<endl;
        int age = 0;
        while(true) {
            cin>>age;
            if(age>=0)  {
                abs->personArray[temp].m_Age = age;
                break;
            }
            else
                cout<<"�����������������룺"<<endl;
        }
        //����
        cout<<"������绰���룺"<<endl;
        char number[MAX];
        cin>>number;
        strcpy(abs->personArray[temp].m_Number,number);

        cout<<"�޸ĳɹ���"<<endl;
    }

    system("pause");
    system("cls");
}

//6.�����ϵ��
void clean_Person(AddressList * abs)
{
    cout<<"�ò����������������ϵ�ˣ�����"<<endl;
    cout<<"�Ƿ������1--��  2--�񣩣�"<<endl;
    int chance = 0;
    cin>>chance;
    if(chance == 1) {
        abs->m_Size = 0;        //��ͨѶ¼��ϵ���������㣬�߼����
        cout<<"ͨѶ¼�ѱ���գ�"<<endl;
    }

    system("pause");
    system("cls");


}

void writeFile(AddressList alist)
{
    FILE * fp;
    if((fp=fopen("person.dat","wb"))==NULL){
        printf("\n�ļ���ʧ��");
        return;
    }

    for(int i=0;i<alist.m_Size;i++){
        fwrite(&alist.personArray[i],sizeof(Person),1,fp);
    }

    fclose(fp);
}

void readFile(AddressList & alist)
{
    FILE * fp;

	if((fp=fopen("person.dat","a+b"))==NULL){
		printf("\n�ļ���ʧ��");
		exit(0);
	}

	Person check;
	alist.m_Size=0;

	//�鿴�ļ����ж��ٸ�����
	while(fread(&check,sizeof(Person),1,fp)){
        alist.m_Size++;
	}

    //���ļ�ָ�����¶�λ���ļ���ͷ
	fseek(fp,0l,SEEK_SET);

	if(alist.m_Size!=0){
        for(int i=0;i<alist.m_Size;i++){
            fread(&alist.personArray[i],sizeof(Person),1,fp);
        }
	}

	fclose(fp);
}

int main()
{

    AddressList abs;    //����ͨѶ¼����
    abs.m_Size = 0;     //��ʼ����ϵ������Ϊ0

    int select = 0;     //�����û�ѡ��ı���

    while(true) {
        readFile(abs);

        show_menu();    //��ʾ�˵�

        cin>>select;

        switch(select)
        {
        case 1:         //1.�����ϵ��
            add_Person(&abs);
            break;
        case 2:         //2.��ʾ��ϵ��
            show_Person(&abs);
            break;
        case 3:         //3.ɾ����ϵ��
            delete_Person(&abs);
            break;
        case 4:         //4.������ϵ��
            find_Person(&abs);
            break;
        case 5:         //5.�޸���ϵ��
            modify_Person(&abs);
            break;
        case 6:         //6.�����ϵ��
            clean_Person(&abs);
            break;
        case 0:         //0.�˳�ͨѶ¼
            {
                cout<<"��ȷ��Ҫ�˳���ǰͨѶ¼����1--��  2--�񣩣�"<<endl;
                int chanc = 0;
                cin>>chanc;
                if(chanc == 1)  {
                    cout<<"��ӭ�´�ʹ�ã�"<<endl;
                    exit(0);
                }
                else
                    system("pause");
                    system("cls");
            }
        }

        writeFile(abs);
    }

    return 0;
}




