#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;

int htmljiexi(string html)
{
	string user,pinglun,dianzan;const char *qq;
	int star=1,end;
	user=html;
	while(star>0)
	{
		qq=strstr(user.c_str(),"f-name q_namecard");
		if(qq==NULL)
			break;
		else
			user=qq;
		int i,t;
		i=user.find("���");
		t=user.find("f-info");
		if(i>t)
		{
			user=strstr(user.c_str(),"f-info");
			continue;
		}
		//�û���
		cout<<"�û�����";
		star=user.find("\>")+1;
		end=user.find("\<");
		while(star<end)
			cout<<user[star++];
		cout<<endl;
		//����ʱ��
		user=strstr(user.c_str(),"ui-mr8");
		star=user.find("\>")+1;
		end=user.find("\<");
		cout<<"  ����ʱ��:";
		while(star<end)
			cout<<user[star++];
		cout<<endl;
		//���
		star=user.find("���");
			end=star;
			while(user[end]!='<')
			{
				//cout<<star<<endl;
				pinglun+=user[end];
				end++;
			}
			if((end-star)==4)
					pinglun="�����0��";
		//��������
		user=strstr(user.c_str(),"f-info");
		star=user.find("\>")+1;
		end=user.find("\<");
		if(star==end)
		{
			cout<<"����Ϊ���ӻ�ͼƬ,��ʱ�޷���ʾ\n";
			goto loop;
			continue;
		}
		//cout<<"����Ϊ:";
		while(star<end)
			cout<<user[star++];
		cout<<endl;
loop:
		{
			cout<<"-------------------------------------"<<endl;
			cout<<"    ";
			//�����
			cout<<pinglun;
				pinglun="";
				cout<<"    ";
			//������
			star=user.find("����");
			end=star;
			while(user[end]!='<')
			{
				//cout<<star<<endl;
				pinglun+=user[end];
				end++;
			}
			if((end-star)==4)
					cout<<"���ۣ�0��";
				else
					cout<<pinglun;
				pinglun="";
			cout<<"    ";
			//������
			star=user.find("��");
			end=star;
			while(user[end]!='<')
			{
				//cout<<star<<endl;
				dianzan+=user[end];
				end++;
			}
			if((end-star)==2)
					cout<<"�ޣ�0��";
				else
					cout<<dianzan;
				dianzan="";	
		}
		cout<<endl<<endl;
	}
	return 0;
}

int main()
{
	FILE *fp;
	string html,star;int a,b;
	fp=fopen("d:\\qqzone.txt","r");
	char ch;
	ch=getc(fp);
	while(ch!=EOF)
	{
		html+=ch;
		ch=getc(fp);
	}
	a=html.find("feed_friend_list");
	if(a==-1)
		cout<<"�ռ�û�ж�̬"<<endl;
	b=html.find("\"feed_me\"");
	for(;a<b;a++)
		star+=html[a];
	htmljiexi(star);
	system("pause");
	return 0;
}