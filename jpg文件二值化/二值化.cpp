#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <gdiplus.h>
#include<tchar.h>
#include<stdio.h>
#include<stdlib.h>
#pragma comment(lib, "gdiplus.lib")

using namespace std;
using namespace Gdiplus;

int quxiangsu( int col[22][62],int ma)
{
    //int col[62][22];
	GdiplusStartupInput gdiplusstartupinput;
	ULONG_PTR gdiplustoken;
	GdiplusStartup(&gdiplustoken, &gdiplusstartupinput, NULL);wchar_t yanzm[20];
	swprintf(yanzm,L"d:\\photo\\%d.jpg",ma);
	wstring infilename(yanzm);
	//¶ÁÍ¼Æ¬
	Bitmap* bmp = new Bitmap(infilename.c_str());
	UINT height = bmp->GetHeight();
	UINT width = bmp->GetWidth();
	cout << "width " << width << ", height " << height << endl;
	Color color;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			bmp->GetPixel(x, y, &color);
			if(((int)color.GetRed()+(int)color.GetGreen()+(int)color.GetBlue())>700) 
			{
				cout<<" ";
				col[y][x]=0;//±³¾°Í¼
			}
			else
			{
				cout<<1;
				col[y][x]=1;//×ÖÄ¸Í¼
			}
		}
		cout<<endl;
	}
		delete bmp;
		GdiplusShutdown(gdiplustoken);
		return 0;
}

int qubian(int col[22][62])
{
	int x;
	for(x=0;x<62;x++)
	{
	    col[0][x]=0;
		col[21][x]=0;
	}
	for(x=0;x<22;x++)
	{
		col[x][0]=0;
		col[x][61]=0;
	}
	int y;int num=1;
	while(num<3)
	{
		for(x=0;x<22;x++)
			{
				if(x==0||x==21)
					continue;
				for(y=0;y<62;y++)
				{
					if(y==0||y==61)
						continue;
					if(num==1)
					{
						if(col[x][y]==1&&col[x][y-1]==0&&col[x][y+1]==0)
							col[x][y]=0;
					}
					else
					{
						if(col[x][y]==1&&col[x-1][y]==0&&col[x+1][y]==0)
							col[x][y]=0;
					}
				}	
			}
		num++;
	}
	return 0;
}
int huatu()
{
	int ma=1;
	while(ma<=400)
	{
	int col[22][62];int x,y;
	quxiangsu(col,ma);
	qubian(col);
	for(x=0;x<22;x++)
	{
		for(y=0;y<62;y++)
		{
			if(col[x][y]==1)
			cout<<1;
			else
				cout<<" ";
		}
		cout<<endl;
	}
	system("pause");
	system("cls");
	ma++;
	}
	return 0;
}


int main()
{
	huatu();
	return 0;
}