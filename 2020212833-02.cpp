#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

#define MAXSIZE 66
#define MAX_NAME 66
#define MAX_ID 66

using namespace std;
typedef struct 
{
	char id[MAX_ID];
	char name[MAX_NAME];
}RES;
//���� 
void Insert1(RES l[], int* len) //���
{
	int num;
	cout << "��ӿ��˵�����Ϊ:";
	cin>>num;
	for (int i = *len; i < *len + num; i++) 
	{
		cout<< "----------���ǵ�"<<i+1<<"λ����----------\n";
		cout << "������˿���:\n";
		cin>>l[i].id;
		for (int j = 0; j < i; j++) 
		{
			while(strcmp(l[i].id, l[j].id) == 0 && i != 0) 
			{
				cout << "�����ظ������������룡\n";
				strcpy_s(l[i].id, "");
				cin>>l[i].id;	
			}
		}//id���� 
		cout << "��������:\n";
		cin>>l[i].name;
		cout << "---------------------------------\n";
	}
	*len = *len + num;
}
void Insert2(RES l[], int* len) //�м����
{
	int k,i;
	cout << "������Ҫ���뵽�ĸ�λ�ã���ţ�֮ǰ��";
	cin >> i;
	if (i > *len) 
	{
		i = *len;
	}
	else if (i < 1)
	{
		i = 1;
	}
	for (k = *len; k >= i; k--)
	{
		strcpy_s(l[k].id, l[k - 1].id);
		strcpy_s(l[k].name, l[k - 1].name);
	}
	cout << "������˿���:\n";
	cin >> l[i-1].id;
	for (int j = 0; j<i-1; j++)
	{
		while(strcmp(l[i-1].id, l[j].id) == 0 && i != 0)
		{
			cout << "�����ظ������������룡\n";
			strcpy_s(l[i - 1].id, "");
			cin >> l[i-1].id;
		}
	}
	for (int j = i; j <=*len; j++)
	{
		while (strcmp(l[i - 1].id, l[j].id) == 0 && i != 0)
		{
			cout << "�����ظ������������룡\n";
			strcpy_s(l[i - 1].id, "");
			cin >> l[i - 1].id;
		}
	}//id����
	cout << "��������:\n";
	cin >> l[i-1].name;
	cout << "---------------------------------\n";
	*len += 1;
}

//���������� 
void Search(RES l[], int* len) 
{
	char n[MAX_ID];
	int flag = 0;//flag=0û�ҵ���=1�ҵ� 
	cout << "Ҫ�ҵĿ�������Ϊ:\n";
	cin>>n;
	for (int i = 0; i < *len; i++) 
	{
		if (strcmp(l[i].name, n) == 0) 
		{
			flag = 1;
			cout << "----------�ÿ������ҵ�,������Ϣ����-----------\n";
			cout << "���ǵ�" << i + 1 << "������\n";
			cout << "���Ŀ�����:"<<l[i].id<<"\n";
			cout << "����������:"<<l[i].name<<"\n";
			cout << "----------------------------------------------\n";
		}
	}
	if (!flag)
	{
		cout<<"--------------δ�ҵ��ÿ���!---------------\n";
	}
}

void Delete1(RES l[], int* len)//��λ��ɾ��
{
	int i,k;
	cout << "������Ҫɾ���Ŀ������ڵ�λ��:";
	cin >> i;
	if (i>*len) 
	{
		cout<<" û����ô����!\n ";
		return;
	}
	if (i < 1) 
	{
		i = 1;
	}
	for (k = i; k < *len; k++)
	{
		strcpy_s(l[k-1].id, l[k].id);
		strcpy_s(l[k-1].name, l[k].name);
	}
	*len = *len - 1;
	return;
}

void Delete2(RES l[], int* len)//���žͲ�
{
	int k;
	for (k = 1; k < *len; k++)
	{
		strcpy_s(l[k - 1].id, l[k].id);
		strcpy_s(l[k - 1].name, l[k].name);
	}
	*len = *len - 1;
	return;
}
void BubleSort(RES l[], int* len)//����
{
	char temp1[66] = "";
	char temp2[66] = "";
	for (int i = 1; i < *len; i++) 
	{
		for (int j = 0; j < *len - i; j++) 
		{
			if (strcmp(l[j].id, l[j + 1].id) > 0)
			{
				strcpy_s(temp1,l[j].id);
				strcpy_s(temp2, l[j].name);
				strcpy_s(l[j].id,l[j + 1].id);
				strcpy_s(l[j].name, l[j + 1].name);
				strcpy_s(l[j + 1].id ,temp1);
				strcpy_s(l[j + 1].name, temp2);
			}
		}
	}
}
//��˳�������ʾ 
void Display(RES l[], int* len) 
{
	cout << "**************************************\n";
	for (int i = 0; i < *len; i++) 
	{
		cout << "----------��"<<i+1<<"�����˵���Ϣ----------\n";
		cout << "���˵Ŀ���:"<<l[i].id<<"\n";
		cout << "���˵�����:"<<l[i].name<<"\n" ;
		cout << "------------------------------------\n";
	}
	cout << "**************************************\n";
}
//�˵����� 
void menu() 
{
	cout <<"---------ʳ���Ŷӹ���ϵͳ----------\n";
	cout <<"����1���          ����2����       \n";
	cout <<"����3ɾ��          ����4��ʾ       \n";
	cout <<"����5���žͲ�      ����6�м����   \n";
	cout <<"����7����������    ����0�˳�       \n";
	cout <<"-----------------------------------\n";
}
int main() 
{
	RES l[MAXSIZE];
	int len = 0;//��ǰ���� 
	int choice;
	while (1) 
	{
		cout << "\n        ##��ǰ��" << len << "���Ŷӣ�##\n";
		menu();
		cin >> choice;
		switch (choice) //ѡ��ģʽ
        {                       
		case 1:
			Insert1(l, &len); //1�����
			Display(l, &len);
			break;     
		case 2:
			Search(l, &len); //2������������
			break;     
		case 3:
			Delete1(l, &len); //3��ɾ��
			Display(l, &len);
			break;     
		case 4:
			Display(l, &len); //4����ʾ
			break;
		case 5:
			Delete2(l, &len); //5�����žͲ�
			cout << "\n�Ѱ��Ŷ���ĵ�һ�����˾Ͳͣ�\n";
			Display(l, &len);
			break;
		case 6:
			Insert2(l, &len);//6���м����
			Display(l, &len);
			break;
		case 7:
			BubleSort(l, &len);//����������
			Display(l, &len);
			break;
		case 0:
			exit(0);          //0���˳�
		default:
			cout << "�������";
		}
	}
	return 0;
}