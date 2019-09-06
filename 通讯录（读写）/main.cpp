#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAX 100

using namespace std;


struct Person
{
    char m_Name [MAX];     //姓名
    int m_Sex;         //性别(1--男   2--女)
    int m_Age;         //年龄
    char m_Number [MAX];   //号码
};

//显示主菜单
void show_menu()
{
    cout<<"************************"<<endl;
    cout<<"***** 1.添加联系人 *****"<<endl;
    cout<<"***** 2.显示联系人 *****"<<endl;
    cout<<"***** 3.删除联系人 *****"<<endl;
    cout<<"***** 4.查找联系人 *****"<<endl;
    cout<<"***** 5.修改联系人 *****"<<endl;
    cout<<"***** 6.清空联系人 *****"<<endl;
    cout<<"***** 0.退出通讯录 *****"<<endl;
    cout<<"************************"<<endl;
    cout<<"请输入您想进行操作所对应的编号："<<endl;
}

struct AddressList
{
    Person personArray[MAX];    //联系人数组
    int m_Size;                 //联系人数量

};

//1.添加联系人
void add_Person(AddressList * abs)
{
        //判断通讯录是否满
    if(abs->m_Size >= MAX)
    {
        cout<<"添加失败，联系人已满。"<<endl;
        return;
    }
    else
    {
        //添加联系人
        //添加姓名
        char name[MAX];
        cout<<"请输入姓名："<<endl;
        cin>>name;
        strcpy(abs->personArray[abs->m_Size].m_Name,name);

        //添加性别
        int sex = 0;
        cout<<"请输入性别（1--男   2--女）："<<endl;
            //判断输入性别
        while(true) {
            cin>>sex;
            if(sex==1 || sex==2) {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
                cout<<"输入有误，请重新输入"<<endl;
        }

        //添加年龄
        int age = 0;
        cout<<"请输入年龄："<<endl;
            //判断输入年龄
        while(true) {
            cin>>age;
            if(age>=0)  {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            else
                cout<<"输入有误，请重新输入："<<endl;
        }

        //添加号码
        char number[MAX];
        cout<<"请输入电话号码："<<endl;
        cin>>number;
        strcpy(abs->personArray[abs->m_Size].m_Number,number);

        abs->m_Size++;
        cout<<"添加成功！"<<endl;
        system("pause");
        system("cls");
    }
}

//2.显示所有联系人
void show_Person(AddressList * abs)
{
    //判断联系人数量是否为0
    if(abs->m_Size == 0)
        cout<<"联系人为空。"<<endl;
    else
    {
        for(int i=0; i<abs->m_Size; i++)    {
            cout<<"姓名："<<abs->personArray[i].m_Name<<"\t"
                <<"性别："<<(abs->personArray[i].m_Sex == 1 ?"男":"女")<<"\t"
                <<"年龄："<<abs->personArray[i].m_Age<<"\t\t"
                <<"号码："<<abs->personArray[i].m_Number<<endl;
        }
    }
    system("pause");
    system("cls");
}

//检查通讯录中联系人存在
int isExist(AddressList * abs, char name[MAX])
{
    for(int i=0; i<abs->m_Size; i++)    {
        if(strcmp(abs->personArray[i].m_Name,name)==0)  {
            return i;
        }
    }
    return -1;
}

//3.删除联系人
void delete_Person(AddressList * abs)
{
    cout<<"请输入您所要删除的联系人的姓名："<<endl;
    char name[MAX];
    cin>>name;
    //检查通讯录中联系人存在
    int temp = isExist(abs, name);

    if(temp == -1)
        cout<<"查无此人！"<<endl;
    else        //变量temp表示要删除联系人的下标
    {
        for(int i=temp; i<abs->m_Size; i++) {
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;     //更新通讯录联系人数
        cout<<"删除成功！"<<endl;
    }
    system("pause");
    system("cls");
}

//4.查找联系人
void find_Person(AddressList * abs)
{
    cout<<"请输入您想查找的联系人姓名："<<endl;
    char name[MAX];
    cin>>name;

    int temp = isExist(abs, name);

    if(temp == -1)
        cout<<"查无此人！"<<endl;
    else
    {
        cout<<"姓名："<<abs->personArray[temp].m_Name<<"\t"
            <<"性别："<<(abs->personArray[temp].m_Sex == 1 ?"男":"女")<<"\t"
            <<"年龄："<<abs->personArray[temp].m_Age<<"\t\t"
            <<"号码："<<abs->personArray[temp].m_Number<<endl;
    }
    system("pause");
    system("cls");
}

//5.修改联系人
void modify_Person(AddressList * abs)
{
    cout<<"请输入您想修改的联系人姓名："<<endl;
    char name[MAX];
    cin>>name;

    int temp = isExist(abs, name);

    if(temp == -1)
        cout<<"查无此人！"<<endl;
    else
    {
        //姓名
        cout<<"请输入姓名："<<endl;
        char name[MAX];
        cin>>name;
        strcpy(abs->personArray[temp].m_Name,name);
        //性别
        cout<<"请输入性别（1--男   2--女）："<<endl;
        int sex = 0;
        while(true) {
            cin>>sex;
            if(sex==1 || sex==2) {
                abs->personArray[temp].m_Sex = sex;
                break;
            }
            else
                cout<<"输入有误，请重新输入"<<endl;
        }
        //年龄
        cout<<"请输入年龄："<<endl;
        int age = 0;
        while(true) {
            cin>>age;
            if(age>=0)  {
                abs->personArray[temp].m_Age = age;
                break;
            }
            else
                cout<<"输入有误，请重新输入："<<endl;
        }
        //号码
        cout<<"请输入电话号码："<<endl;
        char number[MAX];
        cin>>number;
        strcpy(abs->personArray[temp].m_Number,number);

        cout<<"修改成功！"<<endl;
    }

    system("pause");
    system("cls");
}

//6.清空联系人
void clean_Person(AddressList * abs)
{
    cout<<"该操作将会清空所有联系人！！！"<<endl;
    cout<<"是否继续（1--是  2--否）："<<endl;
    int chance = 0;
    cin>>chance;
    if(chance == 1) {
        abs->m_Size = 0;        //讲通讯录联系人数量置零，逻辑清空
        cout<<"通讯录已被清空！"<<endl;
    }

    system("pause");
    system("cls");


}

void writeFile(AddressList alist)
{
    FILE * fp;
    if((fp=fopen("person.dat","wb"))==NULL){
        printf("\n文件打开失败");
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
		printf("\n文件打开失败");
		exit(0);
	}

	Person check;
	alist.m_Size=0;

	//查看文件中有多少个对象
	while(fread(&check,sizeof(Person),1,fp)){
        alist.m_Size++;
	}

    //把文件指针重新定位到文件开头
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

    AddressList abs;    //创建通讯录变量
    abs.m_Size = 0;     //初始化联系人数量为0

    int select = 0;     //创建用户选择的变量

    while(true) {
        readFile(abs);

        show_menu();    //显示菜单

        cin>>select;

        switch(select)
        {
        case 1:         //1.添加联系人
            add_Person(&abs);
            break;
        case 2:         //2.显示联系人
            show_Person(&abs);
            break;
        case 3:         //3.删除联系人
            delete_Person(&abs);
            break;
        case 4:         //4.查找联系人
            find_Person(&abs);
            break;
        case 5:         //5.修改联系人
            modify_Person(&abs);
            break;
        case 6:         //6.清空联系人
            clean_Person(&abs);
            break;
        case 0:         //0.退出通讯录
            {
                cout<<"您确定要退出当前通讯录？（1--是  2--否）："<<endl;
                int chanc = 0;
                cin>>chanc;
                if(chanc == 1)  {
                    cout<<"欢迎下次使用！"<<endl;
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




