#include <iostream>
#include <string>
#include <ctime>
#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	template <class type1>
	class X
	{
	public:
		int dlina;
		type1* XY;

		X(int dlina) //конструктор
		{
			this->dlina = dlina;
			XY = new type1[dlina];
		}

		~X()//деструктор
		{
			delete[] XY;
		}

		X(const X& r) //конструктор копирования
		{
			dlina = r.dlina;
			XY = new type1[dlina];
			for (int i = 0; i < r.dlina; i++)
			{
				XY[i] = r.XY[i];
			}
		}

		void input(int ras, type1 element) // функция ввода элемента
		{
			XY[ras] = element;
		}

		void show() //функция вывода 
		{
			for (int i = 0; i < dlina; i++)
			{
				cout << XY[i] << endl;
			}
			cout << endl;
		}

		int Get_dlina() // функция возращающая размер массива
		{
			return dlina;
		}

		type1 operator[](int i)
		{
			return XY[i];
		}

		X& operator=(const X& right) // перегрузка оператора присваивания
		{

			for (int i = 0; i < right.dlina; i++)
			{
				XY[i] = right.XY[i];
			}
			return *this;
		}

		X& operator+(type1 i)// перегрузка оператора вычитания элемента из массива
		{
			XY[dlina - 1] = XY[dlina - 1] + i;
			return *this;
		}

		X& operator+(X l)//перегрузка оператора вычитания массива
		{
			for (int i = 0; i < l.dlina; i++)
			{
				XY[i] = XY[i] + l.XY[i];
			}
			return *this;
		}

	};

	X <int> x(10);
	X <int> y(10);
	X <int> z(10);
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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;



	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(63, 69);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(152, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Массив x";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(63, 111);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(152, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Массив y";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(63, 157);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(152, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Сложение массивов x и y";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(63, 203);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(165, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Сложение массива с числом";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(234, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(234, 121);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(234, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(234, 213);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"label4";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(768, 420);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
			srand(time(0));

		}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		label2->Text = "Массив: ";
		for (int i = 0; i < y.Get_dlina(); i++)
		{
			y.input(i, rand() % 101 - 50);
			label2->Text += y[i] + " ";
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		label3->Text = "Массив: ";
		z = x + y;
		for (int i = 0; i < x.Get_dlina(); i++)
		{
			label3->Text += z[i] + " ";
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		label4->Text = "Массив: ";
		int k=5;
		z = z + k;
		for (int i = 0; i < z.Get_dlina(); i++)
		{
			label4->Text += z[i] + " ";
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		label1->Text = "Массив: ";
		for (int i = 0; i < x.Get_dlina(); i++)
		{
			x.input(i, rand() % 101 - 50);
			label1->Text += x[i] + " ";
		}
	}
};
}
