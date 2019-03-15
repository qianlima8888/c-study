#pragma once
#include"动态演示.h"

struct paint 
{
	double angle1;//原动机位置角（已知）
	double s;//滑块距原点水平距离
	double angle2;//连杆位置角
	double angularrate2;//连杆角速度
	double jiaojiasudu;//连杆角加速度
	double acceleration_speed;//滑块加速度
	double speed;//滑块速度
}slide[360];

	double L1;//曲柄长度（已知）
	double L2;//连杆长度（已知）
	double h;//滑块导路距曲柄转轴的偏置距离（已知）
	double angle1;//原动机位置角（已知）
	double angularrate1;//原动机角速度（已知）   
	double s;//滑块距原点水平距离
	double angle2;//连杆位置角
	double angularrate2;//连杆角速度

namespace 机械原理大作业 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			system("regesvr32 msvcr100d.dll");
			int i;
			for(i=0;i<360;i++)
	{
		array<String^>^row1= gcnew array<String^>{
			" "," "," "," "," "," "};//
         dataGridView1->Rows->Add(row1);
	}
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;








	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  length1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  length2;
	private: System::Windows::Forms::Label^  Label3;
	private: System::Windows::Forms::TextBox^  chujiao1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  pianjuh;
	private: System::Windows::Forms::TextBox^  jiaosudu1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  JIAO1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  JIAO2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  JIAOSUDU2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  JIAOJIASUDU;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  huakuais;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SPEED;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  JIASUDU;
	private: System::Windows::Forms::PictureBox^  pictureBox1;



















	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->JIAO1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->JIAO2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->JIAOSUDU2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->JIAOJIASUDU = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->huakuais = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SPEED = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->JIASUDU = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->length1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->length2 = (gcnew System::Windows::Forms::TextBox());
			this->Label3 = (gcnew System::Windows::Forms::Label());
			this->chujiao1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pianjuh = (gcnew System::Windows::Forms::TextBox());
			this->jiaosudu1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {this->JIAO1, 
				this->JIAO2, this->JIAOSUDU2, this->JIAOJIASUDU, this->huakuais, this->SPEED, this->JIASUDU});
			this->dataGridView1->Location = System::Drawing::Point(319, 39);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 27;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(1019, 524);
			this->dataGridView1->TabIndex = 0;
			// 
			// JIAO1
			// 
			this->JIAO1->HeaderText = L"曲柄位置角";
			this->JIAO1->Name = L"JIAO1";
			this->JIAO1->ReadOnly = true;
			// 
			// JIAO2
			// 
			this->JIAO2->HeaderText = L"连杆位置角";
			this->JIAO2->Name = L"JIAO2";
			this->JIAO2->ReadOnly = true;
			// 
			// JIAOSUDU2
			// 
			this->JIAOSUDU2->HeaderText = L"连杆角速度";
			this->JIAOSUDU2->Name = L"JIAOSUDU2";
			this->JIAOSUDU2->ReadOnly = true;
			// 
			// JIAOJIASUDU
			// 
			this->JIAOJIASUDU->HeaderText = L"连杆角加速度";
			this->JIAOJIASUDU->Name = L"JIAOJIASUDU";
			this->JIAOJIASUDU->ReadOnly = true;
			// 
			// huakuais
			// 
			this->huakuais->HeaderText = L"滑块水平位置";
			this->huakuais->Name = L"huakuais";
			// 
			// SPEED
			// 
			this->SPEED->HeaderText = L"滑块速度";
			this->SPEED->Name = L"SPEED";
			this->SPEED->ReadOnly = true;
			// 
			// JIASUDU
			// 
			this->JIASUDU->HeaderText = L"滑块加速度";
			this->JIASUDU->Name = L"JIASUDU";
			this->JIASUDU->ReadOnly = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(51, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"曲柄长L1:";
			// 
			// length1
			// 
			this->length1->Location = System::Drawing::Point(152, 36);
			this->length1->Name = L"length1";
			this->length1->Size = System::Drawing::Size(100, 25);
			this->length1->TabIndex = 2;
			this->length1->Text = L"100";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(51, 105);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 15);
			this->label2->TabIndex = 3;
			this->label2->Text = L"连杆长L2:";
			// 
			// length2
			// 
			this->length2->Location = System::Drawing::Point(152, 95);
			this->length2->Name = L"length2";
			this->length2->Size = System::Drawing::Size(100, 25);
			this->length2->TabIndex = 4;
			this->length2->Text = L"300";
			// 
			// Label3
			// 
			this->Label3->AutoSize = true;
			this->Label3->Location = System::Drawing::Point(14, 162);
			this->Label3->Name = L"Label3";
			this->Label3->Size = System::Drawing::Size(113, 15);
			this->Label3->TabIndex = 5;
			this->Label3->Text = L"曲柄位置角θ1:";
			// 
			// chujiao1
			// 
			this->chujiao1->Location = System::Drawing::Point(152, 152);
			this->chujiao1->Name = L"chujiao1";
			this->chujiao1->Size = System::Drawing::Size(100, 25);
			this->chujiao1->TabIndex = 6;
			this->chujiao1->Text = L"66";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(42, 224);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(83, 15);
			this->label4->TabIndex = 7;
			this->label4->Text = L"偏置距离h:";
			// 
			// pianjuh
			// 
			this->pianjuh->Location = System::Drawing::Point(152, 214);
			this->pianjuh->Name = L"pianjuh";
			this->pianjuh->Size = System::Drawing::Size(100, 25);
			this->pianjuh->TabIndex = 8;
			this->pianjuh->Text = L"40";
			// 
			// jiaosudu1
			// 
			this->jiaosudu1->Location = System::Drawing::Point(152, 270);
			this->jiaosudu1->Name = L"jiaosudu1";
			this->jiaosudu1->Size = System::Drawing::Size(100, 25);
			this->jiaosudu1->TabIndex = 9;
			this->jiaosudu1->Text = L"15";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 280);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(113, 15);
			this->label5->TabIndex = 10;
			this->label5->Text = L"曲柄角速度ω1:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(119, 344);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 27);
			this->button1->TabIndex = 11;
			this->button1->Text = L"计算";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(755, 580);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(95, 25);
			this->button2->TabIndex = 12;
			this->button2->Text = L"动态演示";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(28, 377);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(259, 172);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HighlightText;
			this->ClientSize = System::Drawing::Size(1339, 606);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->jiaosudu1);
			this->Controls->Add(this->pianjuh);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->chujiao1);
			this->Controls->Add(this->Label3);
			this->Controls->Add(this->length2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->length1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"曲柄滑块机构";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 int i=0;
	L1=Convert::ToDouble(length1->Text);
	L2=Convert::ToDouble(length2->Text);
	h=Convert::ToDouble(pianjuh->Text);
	angle1=Convert::ToDouble(chujiao1->Text);slide[0].angle1=angle1;
	angularrate1=Convert::ToDouble(jiaosudu1->Text);
	slide[0].angle2=asin(h/L2-L1*sin(slide[0].angle1*hudu)/L2)*jiao;
	slide[0].s=L1*cos(slide[0].angle1*hudu)+L2*cos(asin((h-L1*sin(slide[0].angle1*hudu))/L2));
	slide[0].angularrate2=-L1*angularrate1*cos(slide[0].angle1*hudu)/(L2*cos(slide[i].angle2*hudu));
	slide[i].jiaojiasudu=(L1*angularrate1*angularrate1*sin(slide[i].angle1*hudu)+L2*slide[i].angularrate2*slide[i].angularrate2*sin(slide[i].angle2*hudu))/(L2*cos(slide[i].angle2*hudu));
		slide[i].acceleration_speed=-L1*angularrate1*angularrate1*cos(slide[i].angle1*hudu)-L2*slide[i].angularrate2*slide[i].angularrate2*cos(slide[i].angle2*hudu)-L2*slide[i].angularrate2*sin(slide[i].angle2*hudu);
		slide[i].speed=-L1*angularrate1*sin(slide[i].angle1*hudu)-L2*slide[i].angularrate2*sin(slide[i].angle2*hudu);
		i=1;
	for(angle1++;i<360;i++,angle1++)
	{
		if(angle1>=360)
			angle1-=360;
		slide[i].angle1=angle1;
		slide[i].angle2=asin((h-L1*sin(slide[i].angle1*hudu))/L2)*jiao;
		slide[i].s=L1*cos(slide[i].angle1*hudu)+L2*cos(asin((h-L1*sin(slide[i].angle1*hudu))/L2));
		slide[i].angularrate2=-L1*angularrate1*cos(slide[i].angle1*hudu)/(L2*cos(asin((h-L1*sin(slide[i].angle1*hudu))/L2)));
		slide[i].jiaojiasudu=(L1*angularrate1*angularrate1*sin(slide[i].angle1*hudu)+L2*slide[i].angularrate2*slide[i].angularrate2*sin(slide[i].angle2*hudu))/(L2*cos(slide[i].angle2*hudu));
		slide[i].acceleration_speed=-L1*angularrate1*angularrate1*cos(slide[i].angle1*hudu)-L2*slide[i].angularrate2*slide[i].angularrate2*cos(slide[i].angle2*hudu)-L2*slide[i].angularrate2*sin(slide[i].angle2*hudu);
		slide[i].speed=-L1*angularrate1*sin(slide[i].angle1*hudu)-L2*slide[i].angularrate2*sin(slide[i].angle2*hudu);
	}
	dataGridView1->Rows->Clear(); 
	for(i=0;i<360;i++)
	{
		array<String^>^row = gcnew array<String^>{
         Convert::ToString(slide[i].angle1),Convert::ToString(slide[i].angle2),Convert::ToString(slide[i].angularrate2),Convert::ToString(slide[i].jiaojiasudu),Convert::ToString(slide[i].s),Convert::ToString(slide[i].speed/1000),Convert::ToString(slide[i].acceleration_speed/1000)};
		 dataGridView1->Rows->Add(row);
	}
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 动态演示^ data = gcnew 动态演示();
			 //传递数字
			 data->a=L1;
			 data->b=L2;
			 data->c=h;
			 data->d=angle1;
			 data->aa=angle1;
			 data->w=angularrate1;
			 data->cc=3;
			 data->pause=1;
      // Display the new form.
      data->Show();
		 }
};
}

