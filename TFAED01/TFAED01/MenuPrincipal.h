#pragma once
#include "FormPopUp.h"

namespace TFAED01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	private: System::ComponentModel::IContainer^  components;
	private:

		System::Windows::Forms::ToolStrip^  toolStrip1;
		System::Windows::Forms::ToolStripButton^  tsbtnIndexar;
		System::Windows::Forms::ToolStripButton^  tsbtnFiltrar;
		System::Windows::Forms::ToolStripButton^  tsbtnOrdenar;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
		System::Windows::Forms::ToolStripSeparator^  toolStripButton7;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
		System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
		System::Windows::Forms::ToolStripSplitButton^  toolStripSplitButton1;
		System::Windows::Forms::ToolStripMenuItem^  tsbtnGuardarArch;
		System::Windows::Forms::ToolStripMenuItem^  tsbtnAbrirArch;
		System::Windows::Forms::ToolStripMenuItem^  tsbtnNuevaTabla;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
		System::Windows::Forms::OpenFileDialog^  openFileDialog1;

		System::Windows::Forms::DataGridView^  dgvPrincipal;

	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			
		}
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}

		void AñadirColumna(String ^name) {
			int i = dgvPrincipal->ColumnCount;
			dgvPrincipal->Columns->Add("Columna" + i.ToString(), name);
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripSplitButton1 = (gcnew System::Windows::Forms::ToolStripSplitButton());
			this->tsbtnNuevaTabla = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsbtnAbrirArch = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsbtnGuardarArch = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tsbtnIndexar = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tsbtnFiltrar = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tsbtnOrdenar = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dgvPrincipal = (gcnew System::Windows::Forms::DataGridView());
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPrincipal))->BeginInit();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->toolStripSplitButton1,
					this->toolStripButton7, this->toolStripSeparator1, this->toolStripSeparator2, this->tsbtnIndexar, this->toolStripSeparator3,
					this->tsbtnFiltrar, this->toolStripSeparator4, this->tsbtnOrdenar, this->toolStripSeparator5
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(844, 25);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripSplitButton1
			// 
			this->toolStripSplitButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::None;
			this->toolStripSplitButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->tsbtnNuevaTabla,
					this->tsbtnAbrirArch, this->tsbtnGuardarArch
			});
			this->toolStripSplitButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripSplitButton1.Image")));
			this->toolStripSplitButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSplitButton1->Name = L"toolStripSplitButton1";
			this->toolStripSplitButton1->Size = System::Drawing::Size(16, 22);
			this->toolStripSplitButton1->Text = L"toolStripSplitButton1";
			// 
			// tsbtnNuevaTabla
			// 
			this->tsbtnNuevaTabla->Name = L"tsbtnNuevaTabla";
			this->tsbtnNuevaTabla->Size = System::Drawing::Size(116, 22);
			this->tsbtnNuevaTabla->Text = L"Nueva";
			this->tsbtnNuevaTabla->Click += gcnew System::EventHandler(this, &MenuPrincipal::tsbtnNuevaTabla_Click);
			// 
			// tsbtnAbrirArch
			// 
			this->tsbtnAbrirArch->Name = L"tsbtnAbrirArch";
			this->tsbtnAbrirArch->Size = System::Drawing::Size(116, 22);
			this->tsbtnAbrirArch->Text = L"Abrir";
			this->tsbtnAbrirArch->Click += gcnew System::EventHandler(this, &MenuPrincipal::tsbtnAbrirArch_Click);
			// 
			// tsbtnGuardarArch
			// 
			this->tsbtnGuardarArch->Name = L"tsbtnGuardarArch";
			this->tsbtnGuardarArch->Size = System::Drawing::Size(116, 22);
			this->tsbtnGuardarArch->Text = L"Guardar";
			this->tsbtnGuardarArch->Click += gcnew System::EventHandler(this, &MenuPrincipal::tsbtnGuardarArch_Click);
			// 
			// toolStripButton7
			// 
			this->toolStripButton7->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->toolStripButton7->Name = L"toolStripButton7";
			this->toolStripButton7->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
			// 
			// tsbtnIndexar
			// 
			this->tsbtnIndexar->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tsbtnIndexar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbtnIndexar.Image")));
			this->tsbtnIndexar->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbtnIndexar->Name = L"tsbtnIndexar";
			this->tsbtnIndexar->Size = System::Drawing::Size(50, 22);
			this->tsbtnIndexar->Text = L"Indexar";
			this->tsbtnIndexar->Click += gcnew System::EventHandler(this, &MenuPrincipal::tsbtnIndexar_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(6, 25);
			// 
			// tsbtnFiltrar
			// 
			this->tsbtnFiltrar->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tsbtnFiltrar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbtnFiltrar.Image")));
			this->tsbtnFiltrar->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbtnFiltrar->Name = L"tsbtnFiltrar";
			this->tsbtnFiltrar->Size = System::Drawing::Size(74, 22);
			this->tsbtnFiltrar->Text = L"Filtrar por ...";
			this->tsbtnFiltrar->Click += gcnew System::EventHandler(this, &MenuPrincipal::tsbtnFiltrar_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(6, 25);
			// 
			// tsbtnOrdenar
			// 
			this->tsbtnOrdenar->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tsbtnOrdenar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbtnOrdenar.Image")));
			this->tsbtnOrdenar->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbtnOrdenar->Name = L"tsbtnOrdenar";
			this->tsbtnOrdenar->Size = System::Drawing::Size(87, 22);
			this->tsbtnOrdenar->Text = L"Ordenar por ...";
			this->tsbtnOrdenar->Click += gcnew System::EventHandler(this, &MenuPrincipal::tsbtnOrdenar_Click);
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(6, 25);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// dgvPrincipal
			// 
			this->dgvPrincipal->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvPrincipal->Location = System::Drawing::Point(0, 28);
			this->dgvPrincipal->Name = L"dgvPrincipal";
			this->dgvPrincipal->Size = System::Drawing::Size(844, 482);
			this->dgvPrincipal->TabIndex = 2;
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(844, 510);
			this->Controls->Add(this->dgvPrincipal);
			this->Controls->Add(this->toolStrip1);
			this->Name = L"MenuPrincipal";
			this->Text = L"MiniSGBD";
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPrincipal))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void tsbtnGuardarArch_Click(System::Object^  sender, System::EventArgs^  e) {
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//código aquí
			MessageBox::Show(saveFileDialog1->FileName);
			
		}
	}
	private: System::Void tsbtnAbrirArch_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//código aquí
			MessageBox::Show(openFileDialog1->FileName);
		}
	}
	private: System::Void tsbtnNuevaTabla_Click(System::Object^  sender, System::EventArgs^  e) {
		FormPopUp ^fpu = gcnew FormPopUp();
		fpu->ComoAbrirPopUp(NuevaTabla); //fpu->ShowDialog(this);
		if (fpu->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			for (int i = 0; i < fpu->dgvNuevaTabla->RowCount - 1; i++)
				AñadirColumna(fpu->GetNombre(true, i));
		}
		delete fpu;
	}
	private: System::Void tsbtnIndexar_Click(System::Object^  sender, System::EventArgs^  e) {
		//código aquí

	}
	private: System::Void tsbtnFiltrar_Click(System::Object^  sender, System::EventArgs^  e) {
		FormPopUp ^fpu = gcnew FormPopUp();
		fpu->ComoAbrirPopUp(Filtrar); fpu->ShowDialog(this);
		delete fpu;
	}
	private: System::Void tsbtnOrdenar_Click(System::Object^  sender, System::EventArgs^  e) {
		FormPopUp ^fpu = gcnew FormPopUp();
		fpu->ComoAbrirPopUp(Ordenar); fpu->ShowDialog(this);
		delete fpu;
	}
};
}
