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
		i=user.find("浏览");
		t=user.find("f-info");
		if(i>t)
		{
			user=strstr(user.c_str(),"f-info");
			continue;
		}
		//用户名
		cout<<"用户名：";
		star=user.find("\>")+1;
		end=user.find("\<");
		while(star<end)
			cout<<user[star++];
		cout<<endl;
		//发布时间
		user=strstr(user.c_str(),"ui-mr8");
		star=user.find("\>")+1;
		end=user.find("\<");
		cout<<"  发布时间:";
		while(star<end)
			cout<<user[star++];
		cout<<endl;
		//浏览
		star=user.find("浏览");
			end=star;
			while(user[end]!='<')
			{
				//cout<<star<<endl;
				pinglun+=user[end];
				end++;
			}
			if((end-star)==4)
					pinglun="浏览（0）";
		//发布正文
		user=strstr(user.c_str(),"f-info");
		star=user.find("\>")+1;
		end=user.find("\<");
		if(star==end)
		{
			cout<<"内容为链接或图片,暂时无法显示\n";
			goto loop;
			continue;
		}
		//cout<<"内容为:";
		while(star<end)
			cout<<user[star++];
		cout<<endl;
loop:
		{
			cout<<"-------------------------------------"<<endl;
			cout<<"    ";
			//浏览数
			cout<<pinglun;
				pinglun="";
				cout<<"    ";
			//评论数
			star=user.find("评论");
			end=star;
			while(user[end]!='<')
			{
				//cout<<star<<endl;
				pinglun+=user[end];
				end++;
			}
			if((end-star)==4)
					cout<<"评论（0）";
				else
					cout<<pinglun;
				pinglun="";
			cout<<"    ";
			//点赞数
			star=user.find("赞");
			end=star;
			while(user[end]!='<')
			{
				//cout<<star<<endl;
				dianzan+=user[end];
				end++;
			}
			if((end-star)==2)
					cout<<"赞（0）";
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
		cout<<"空间没有动态"<<endl;
	b=html.find("\"feed_me\"");
	for(;a<b;a++)
		star+=html[a];
	htmljiexi(star);
	system("pause");
	return 0;
}