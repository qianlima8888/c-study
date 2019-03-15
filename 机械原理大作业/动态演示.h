#pragma once
#include<math.h>
#include<tchar.h>
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>

#define hudu 0.01745329
#define jiao 57.29577951


namespace 机械原理大作业 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// 动态演示 摘要
	/// </summary>
	public ref class 动态演示 : public System::Windows::Forms::Form
	{
	public:
		动态演示(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			
		}
		double a,b,c,d,w,aa;int cc,pause;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: Thread^ demoThread;
	private: void f1()//画图线程
{
  double x1,x2,y1,x,y,dd,ma,xz;dd=d;
  HWND hwnd;
  hwnd=::FindWindow(NULL,_T("动态演示"));
  HDC hDC,hDCMem;   // DC(可画图的内存对象) 的句柄
  hDC=::GetDC(hwnd);
  HBITMAP  hBm;
  hDCMem=CreateCompatibleDC(hDC);  //创建虚拟DC
  RECT rc;
  GetClientRect(hwnd,&rc);
  hBm=CreateCompatibleBitmap(hDC,rc.right-rc.left,rc.bottom -rc.top);//将窗口矩形存入位图
  SelectObject(hDCMem,hBm);
  HPEN h1,h2,h3,h4,h5; // 画笔
  // 创建画笔
  h1=CreatePen(PS_SOLID, 5, RGB(255,5,0));
  h2=CreatePen(PS_SOLID, 5, RGB(0,255,0));
  h3=CreatePen(PS_SOLID, 10, RGB(255,100,0));
  h4=CreatePen(PS_DASHDOT, 1, RGB(255,5,0));
  h5=CreatePen(PS_DASHDOT, 5, RGB(0,0,0));
  // DC 选择画笔
  x=400+a*cos(aa*hudu);y=300-a*sin(aa*hudu);
  ma=360+sqrt((b-a)*(b-a)-c*c);
  xz=430+sqrt((b+a)*(b+a)-c*c);
  for(;(pause!=0)&&(cc<360);cc++,d++)
  { 
 FillRect(hDCMem,&rc,(HBRUSH)RGB(255,255,255));
 //画轨道
 MoveToEx(hDCMem,ma,310-c,NULL);
 SelectObject(hDCMem,h5);
 LineTo(hDCMem,xz,310-c);
 x1=400+a*cos(d*hudu);y1=300-a*sin(d*hudu);x2=x1+b*cos(asin((c-a*sin(d*hudu))/b));
  MoveToEx(hDCMem, 400,300, NULL);
  // 画曲柄
  SelectObject(hDCMem,h1);
  LineTo(hDCMem,x1,y1);
  SelectObject(hDCMem,h4);
  Arc(hDCMem,400-a,300-a,400+a,300+a,x,y,x1,y1);
  MoveToEx(hDCMem,x1,y1, NULL);
  //画滑块
  SelectObject(hDCMem,h3);
  ::Rectangle(hDCMem,x2-20,295-c,x2+20,305-c);
  // 画连杆
  SelectObject(hDCMem,h2);
  LineTo(hDCMem,x2,300-c);
  if(cc==359)
	  cc=0;
  BitBlt(hDC,this->Left,this->Top,rc.right-rc.left,rc.bottom-rc.top,hDCMem,this->Left,this->Top,SRCCOPY);
  Sleep(15);
  }
 }  
	public: 

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~动态演示()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(524, 718);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 27);
			this->button1->TabIndex = 0;
			this->button1->Text = L"开始";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &动态演示::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(668, 718);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 28);
			this->button2->TabIndex = 1;
			this->button2->Text = L"暂停";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &动态演示::button2_Click);
			// 
			// 动态演示
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(1246, 758);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->DoubleBuffered = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"动态演示";
			this->Text = L"动态演示";
			this->ResumeLayout(false);

		}
#pragma endregion

					
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				if(pause++==1||pause==1)
				{
					this->demoThread=gcnew Thread(gcnew ThreadStart(this,&动态演示::f1));
					this->demoThread->Start();
					this->demoThread->IsBackground=true;
					pause++;
				}
			 }
				 
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 pause=0;
			 }
};
}
