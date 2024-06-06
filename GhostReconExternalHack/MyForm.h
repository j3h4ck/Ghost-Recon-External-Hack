#pragma once
#include "Game.h"

namespace GhostReconExternalHack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int PID;
	int ticker = 0;
	int desired = 1;
	int desired2 = 0;
	TCHAR gameModule[] = _T("GRW.exe");
	DWORD64 gamebaseaddress;
	DWORD64 ammoAddress;
	DWORD64 ammobaseaddress = 0x0490A1D0;
	std::vector<DWORD64> ammoOffsets = { 0x30 };
	HANDLE hProc;
	const wchar_t* process = L"GRW.exe";
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		

	public:
		
		
		
		MyForm(void)
		{
			InitializeComponent();
			this->TopMost = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Location = System::Drawing::Point(256, 403);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Location = System::Drawing::Point(393, 376);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"[+] Game Status :";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label2->Location = System::Drawing::Point(393, 420);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(129, 23);
			this->label2->TabIndex = 2;
			this->label2->Text = L"[+] PID : ";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->ForeColor = System::Drawing::Color::IndianRed;
			this->label3->Location = System::Drawing::Point(482, 376);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 23);
			this->label3->TabIndex = 3;
			this->label3->Text = L"NOT RUNNING";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->ForeColor = System::Drawing::Color::IndianRed;
			this->label4->Location = System::Drawing::Point(438, 420);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(129, 23);
			this->label4->TabIndex = 4;
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label5->Location = System::Drawing::Point(47, 366);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(129, 23);
			this->label5->TabIndex = 5;
			this->label5->Text = L"[+] Handle :";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->ForeColor = System::Drawing::Color::Lime;
			this->label6->Location = System::Drawing::Point(112, 366);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(129, 23);
			this->label6->TabIndex = 6;
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label7->Location = System::Drawing::Point(47, 403);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(129, 23);
			this->label7->TabIndex = 7;
			this->label7->Text = L"[+] Game Base :";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->ForeColor = System::Drawing::Color::Lime;
			this->label8->Location = System::Drawing::Point(130, 403);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(120, 23);
			this->label8->TabIndex = 8;
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label9->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label9->Location = System::Drawing::Point(47, 442);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(129, 23);
			this->label9->TabIndex = 9;
			this->label9->Text = L"[+] Ammo Address :";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label10->ForeColor = System::Drawing::Color::Lime;
			this->label10->Location = System::Drawing::Point(143, 442);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(107, 23);
			this->label10->TabIndex = 10;
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label11->Location = System::Drawing::Point(186, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(266, 23);
			this->label11->TabIndex = 11;
			this->label11->Text = L"Ghost Recon External Hack";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label12->Location = System::Drawing::Point(167, 32);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(266, 23);
			this->label12->TabIndex = 12;
			this->label12->Text = L"Made by :               ";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Red;
			this->label13->Location = System::Drawing::Point(304, 32);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(102, 23);
			this->label13->TabIndex = 13;
			this->label13->Text = L"Jehad Abu Dagga";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(614, 474);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MyForm";
			this->Text = L"GRW External - j3h4ck";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		

		if (ticker == 0) {
			PID = FindProcessIdByName(process);

			if (PID == 0) {

			}
			else {
				label3->ForeColor = Color::Lime;
				label3->Text = "RUNNING";
				label4->ForeColor = Color::Lime;
				label4->Text = PID.ToString();
				timer1->Start();
				button1->Text = "Stop";
			}
		}
		if (ticker == 1) {
			ticker = 0;
			timer1->Stop();
			WriteProcessMemory(hProc, (LPVOID)ammoAddress, &desired2, sizeof(desired2), NULL);
			label3->Text = "STOPPED";
			label3->ForeColor = Color::Red;
			label10->Text = "";
			label6->Text = "";
			label8->Text = "";
			label4->Text = "";
			button1->Text = "Start";

		}

	}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	if (ticker == 0) {
		hProc = OpenProcess(PROCESS_ALL_ACCESS, NULL, PID);

		if (hProc == 0) {
			timer1->Stop();
		}
		else {
			IntPtr hProcPtr(hProc);
			label6->Text = String::Format("0x{0:X}", hProcPtr.ToInt64());
		}
		gamebaseaddress = GetModuleBaseAddress64(gameModule, PID);

		if (gamebaseaddress == 0) {
			timer1->Stop();
		}
		else {
			label8->Text = String::Format("0x{0:X}", gamebaseaddress);
		}

		ammoAddress = GetPointerAddress64(hProc, gamebaseaddress, ammobaseaddress, ammoOffsets);

		if (ammoAddress == 0) {
			timer1->Stop();
		}
		else {
			label10->Text = String::Format("0x{0:X}", ammoAddress);
		}
		ticker = 1;


	}
	else {
		//timer2->Start();
		WriteProcessMemory(hProc, (LPVOID)ammoAddress, &desired, sizeof(desired), NULL);
	}

}
	   private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		   WriteProcessMemory(hProc, (LPVOID)ammoAddress, &desired, sizeof(desired), NULL);

	   }
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}

};
}
