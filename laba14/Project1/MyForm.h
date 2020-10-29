#pragma once
#pragma once
#include "table.h"
#include <ctime>
#include <iostream>
#include "strochka.h"
#include "autotable.h"
#include "sorttable.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ N;
	private: System::Windows::Forms::TextBox^ M;
	private: System::Windows::Forms::TextBox^ Sto;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ Stroka;


	private: System::Windows::Forms::DataGridView^ Table;
	private: System::Windows::Forms::DataGridView^ Table1;
	private: System::Windows::Forms::DataGridView^ Table2;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->N = (gcnew System::Windows::Forms::TextBox());
			this->M = (gcnew System::Windows::Forms::TextBox());
			this->Sto = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Stroka = (gcnew System::Windows::Forms::TextBox());
			this->Table = (gcnew System::Windows::Forms::DataGridView());
			this->Table1 = (gcnew System::Windows::Forms::DataGridView());
			this->Table2 = (gcnew System::Windows::Forms::DataGridView());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(441, 473);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Выполнить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 378);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Количество строк:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 409);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Количество столбцов:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 441);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(82, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Номер строки:";
			// 
			// N
			// 
			this->N->Location = System::Drawing::Point(163, 375);
			this->N->Name = L"N";
			this->N->Size = System::Drawing::Size(100, 20);
			this->N->TabIndex = 5;
			// 
			// M
			// 
			this->M->Location = System::Drawing::Point(163, 409);
			this->M->Name = L"M";
			this->M->Size = System::Drawing::Size(100, 20);
			this->M->TabIndex = 6;
			// 
			// Sto
			// 
			this->Sto->Location = System::Drawing::Point(163, 441);
			this->Sto->Name = L"Sto";
			this->Sto->Size = System::Drawing::Size(100, 20);
			this->Sto->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(427, 361);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Строка таблицы";
			// 
			// Stroka
			// 
			this->Stroka->Location = System::Drawing::Point(377, 409);
			this->Stroka->Name = L"Stroka";
			this->Stroka->Size = System::Drawing::Size(184, 20);
			this->Stroka->TabIndex = 9;
			// 
			// Table
			// 
			this->Table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table->Location = System::Drawing::Point(12, 63);
			this->Table->Name = L"Table";
			this->Table->Size = System::Drawing::Size(366, 293);
			this->Table->TabIndex = 10;
			// 
			// Table1
			// 
			this->Table1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table1->Location = System::Drawing::Point(441, 76);
			this->Table1->Name = L"Table1";
			this->Table1->Size = System::Drawing::Size(424, 258);
			this->Table1->TabIndex = 11;
			// 
			// Table2
			// 
			this->Table2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table2->Location = System::Drawing::Point(991, 95);
			this->Table2->Name = L"Table2";
			this->Table2->Size = System::Drawing::Size(418, 334);
			this->Table2->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(146, 47);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Таблица";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(601, 47);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(124, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Таблица с автосуммой";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1124, 47);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(193, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Таблица с сортировкой по строчкам";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1475, 665);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Table2);
			this->Controls->Add(this->Table1);
			this->Controls->Add(this->Table);
			this->Controls->Add(this->Stroka);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Sto);
			this->Controls->Add(this->M);
			this->Controls->Add(this->N);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Stroka->Text = " ";
		try {
			srand(time(NULL));
			int n, m, sto;

			n = Convert::ToInt32(N->Text);
			m = Convert::ToInt32(M->Text);
			//////////////////////////
			int** tab = new int* [n];
			for (int i = 0; i < n; i++)
				tab[i] = new int[m];
			table t1(tab, n, m);
			tab[n - 1][m] = t1.filltable(&tab[0]);
			Table->ColumnCount = m;
			Table->RowCount = n;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					this->Table->Rows[i]->Cells[j]->Value = Convert::ToString(tab[i][j]);
			//////////////////////////
			sto = Convert::ToInt32(Sto->Text);
			int* s = new int[m];
			strochka s1(tab, n, m, sto, s);
			s[m] = s1.fillstroka(&s[0]);
			for (int i = 0; i < m; i++)
				Stroka->Text += " " + s[i];
			//////////////////////////
			m = m + 1;
			int** tab1 = new int* [n];
			for (int i = 0; i < n; i++)
				tab1[i] = new int[m];
			autotable t2(tab, n, m, tab1);
			tab1[n - 1][m] = t2.fillautotable(&tab1[0]);
			Table1->ColumnCount = m;
			Table1->RowCount = n;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					this->Table1->Rows[i]->Cells[j]->Value = Convert::ToString(tab1[i][j]);
			//////////////////////////
			m = m - 1;
			int** tab2 = new int* [n];
			for (int i = 0; i < n; i++)
				tab2[i] = new int[m];
			sorttable t3(tab, n, m, tab2);
			tab2[n - 1][m] = t3.fillsorttable(&tab2[0]);
			Table2->ColumnCount = m;
			Table2->RowCount = n;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					this->Table2->Rows[i]->Cells[j]->Value = Convert::ToString(tab2[i][j]);
		}
		catch (System::FormatException^ ex) {
			MessageBox::Show("Заполните все поля.", "Ошибка!",
				MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);
		}
	}

	private: System::Void M_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar >= '0' && e->KeyChar <= '9') return;
		if (Char::IsControl(e->KeyChar)) {
			if (e->KeyChar == (Char)Keys::Enter)
				button1->Focus();
			return;
		}
		e->Handled = true;
	}

	private: System::Void N_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar >= '0' && e->KeyChar <= '9') return;
		if (Char::IsControl(e->KeyChar)) {
			if (e->KeyChar == (Char)Keys::Enter)
				button1->Focus();
			return;
		}
		e->Handled = true;
	}

	private: System::Void Sto_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar >= '0' && e->KeyChar <= '9') return;
		if (Char::IsControl(e->KeyChar)) {
			if (e->KeyChar == (Char)Keys::Enter)
				button1->Focus();
			return;
		}
		e->Handled = true;
	}
	};
}