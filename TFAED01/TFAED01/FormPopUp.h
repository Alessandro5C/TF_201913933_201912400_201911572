#pragma once
enum Option { NuevaTabla, Filtrar, Ordenar };
namespace TFAED01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FormPopUp : public System::Windows::Forms::Form
	{
	private:
		System::ComponentModel::Container ^components;
		System::Windows::Forms::Panel^  pnlNuevaTabla;
		System::Windows::Forms::Panel^  pnlOrdenar;
		System::Windows::Forms::DataGridViewTextBoxColumn^  ColName;
		System::Windows::Forms::DataGridViewComboBoxColumn^  ColTipo;
		System::Windows::Forms::Label^  lblOrdenCriterio;
		System::Windows::Forms::Button^  btnCrearNuevaTabla;
		System::Windows::Forms::Panel^  pnlFiltrar;
		System::Windows::Forms::Button^  btnFiltrar;
		System::Windows::Forms::TextBox^  tbxFiltroValor;
		System::Windows::Forms::ComboBox^  comboBoxFiltroCriterio;
		System::Windows::Forms::Label^  lblFiltroCriterio;
		System::Windows::Forms::Button^  button1;
		System::Windows::Forms::ComboBox^  comboBoxOrdenar;
	public: System::Windows::Forms::DataGridView^  dgvNuevaTabla;
	public:
		FormPopUp(void)
		{
			InitializeComponent();
			pnlNuevaTabla->SetBounds(3, 7, pnlNuevaTabla->Width, pnlNuevaTabla->Height);
			pnlFiltrar->SetBounds(3, 7, pnlFiltrar->Width, pnlFiltrar->Height);
			pnlOrdenar->SetBounds(3, 7, pnlOrdenar->Width, pnlOrdenar->Height);
			ReturnToZero();
		}
		~FormPopUp()
		{
			if (components)
			{
				delete components;
			}
		}

		void ReturnToZero() {
			pnlNuevaTabla->Visible = false; pnlNuevaTabla->Enabled = false;
			pnlFiltrar->Visible = false; pnlFiltrar->Enabled = false;
			pnlOrdenar->Visible = false; pnlOrdenar->Enabled = false;
		}

		void ComoAbrirPopUp(Option o) {
			switch (o)
			{
			case NuevaTabla: FormPopUp::Height = pnlNuevaTabla->Height + 45;
				pnlNuevaTabla->Visible = true; pnlNuevaTabla->Enabled = true; 
				this->Text = "Crear nueva"; break;
			case Filtrar: FormPopUp::Height = pnlFiltrar->Height + 45; 
				pnlFiltrar->Visible = true; pnlFiltrar->Enabled = true; 
				this->Text = "Filtro";  break;
			case Ordenar: FormPopUp::Height = pnlOrdenar->Height + 45; 
				pnlOrdenar->Visible = true; pnlOrdenar->Enabled = true; 
				this->Text = "Ordenar"; break;
			default:
				break;
			}
		}

		String^ GetNombre(bool nombre, int fila) {
			if (nombre)
				return dgvNuevaTabla[0, fila]->Value->ToString();
			//return dgvNuevaTabla[1, fila]->Value->ToString();
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlNuevaTabla = (gcnew System::Windows::Forms::Panel());
			this->dgvNuevaTabla = (gcnew System::Windows::Forms::DataGridView());
			this->ColName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColTipo = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->btnCrearNuevaTabla = (gcnew System::Windows::Forms::Button());
			this->pnlOrdenar = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBoxOrdenar = (gcnew System::Windows::Forms::ComboBox());
			this->lblOrdenCriterio = (gcnew System::Windows::Forms::Label());
			this->pnlFiltrar = (gcnew System::Windows::Forms::Panel());
			this->btnFiltrar = (gcnew System::Windows::Forms::Button());
			this->tbxFiltroValor = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxFiltroCriterio = (gcnew System::Windows::Forms::ComboBox());
			this->lblFiltroCriterio = (gcnew System::Windows::Forms::Label());
			this->pnlNuevaTabla->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvNuevaTabla))->BeginInit();
			this->pnlOrdenar->SuspendLayout();
			this->pnlFiltrar->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlNuevaTabla
			// 
			this->pnlNuevaTabla->Controls->Add(this->dgvNuevaTabla);
			this->pnlNuevaTabla->Controls->Add(this->btnCrearNuevaTabla);
			this->pnlNuevaTabla->Location = System::Drawing::Point(3, 12);
			this->pnlNuevaTabla->Name = L"pnlNuevaTabla";
			this->pnlNuevaTabla->Size = System::Drawing::Size(226, 181);
			this->pnlNuevaTabla->TabIndex = 0;
			// 
			// dgvNuevaTabla
			// 
			this->dgvNuevaTabla->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvNuevaTabla->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->ColName,
					this->ColTipo
			});
			this->dgvNuevaTabla->Location = System::Drawing::Point(6, 3);
			this->dgvNuevaTabla->Name = L"dgvNuevaTabla";
			this->dgvNuevaTabla->Size = System::Drawing::Size(217, 146);
			this->dgvNuevaTabla->TabIndex = 0;
			// 
			// ColName
			// 
			this->ColName->HeaderText = L"Nombre de la columna";
			this->ColName->Name = L"ColName";
			this->ColName->Width = 85;
			// 
			// ColTipo
			// 
			this->ColTipo->HeaderText = L"Tipo de dato de la columna";
			this->ColTipo->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"int ", L"float", L"char" });
			this->ColTipo->Name = L"ColTipo";
			this->ColTipo->Width = 70;
			// 
			// btnCrearNuevaTabla
			// 
			this->btnCrearNuevaTabla->Location = System::Drawing::Point(77, 155);
			this->btnCrearNuevaTabla->Name = L"btnCrearNuevaTabla";
			this->btnCrearNuevaTabla->Size = System::Drawing::Size(75, 23);
			this->btnCrearNuevaTabla->TabIndex = 8;
			this->btnCrearNuevaTabla->Text = L"Crear";
			this->btnCrearNuevaTabla->UseVisualStyleBackColor = true;
			this->btnCrearNuevaTabla->Click += gcnew System::EventHandler(this, &FormPopUp::btnCrearNuevaTabla_Click);
			// 
			// pnlOrdenar
			// 
			this->pnlOrdenar->Controls->Add(this->button1);
			this->pnlOrdenar->Controls->Add(this->comboBoxOrdenar);
			this->pnlOrdenar->Controls->Add(this->lblOrdenCriterio);
			this->pnlOrdenar->Location = System::Drawing::Point(3, 288);
			this->pnlOrdenar->Name = L"pnlOrdenar";
			this->pnlOrdenar->Size = System::Drawing::Size(226, 85);
			this->pnlOrdenar->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(77, 52);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Filtrar datos";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// comboBoxOrdenar
			// 
			this->comboBoxOrdenar->FormattingEnabled = true;
			this->comboBoxOrdenar->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Contiene a ...", L"No contiene a ...",
					L"Comienza con ...", L"Finaliza con ..."
			});
			this->comboBoxOrdenar->Location = System::Drawing::Point(6, 25);
			this->comboBoxOrdenar->Name = L"comboBoxOrdenar";
			this->comboBoxOrdenar->Size = System::Drawing::Size(217, 21);
			this->comboBoxOrdenar->TabIndex = 9;
			// 
			// lblOrdenCriterio
			// 
			this->lblOrdenCriterio->AutoSize = true;
			this->lblOrdenCriterio->Location = System::Drawing::Point(9, 9);
			this->lblOrdenCriterio->Name = L"lblOrdenCriterio";
			this->lblOrdenCriterio->Size = System::Drawing::Size(124, 13);
			this->lblOrdenCriterio->TabIndex = 9;
			this->lblOrdenCriterio->Text = L"Criterio de ordenamiento:";
			// 
			// pnlFiltrar
			// 
			this->pnlFiltrar->Controls->Add(this->btnFiltrar);
			this->pnlFiltrar->Controls->Add(this->tbxFiltroValor);
			this->pnlFiltrar->Controls->Add(this->comboBoxFiltroCriterio);
			this->pnlFiltrar->Controls->Add(this->lblFiltroCriterio);
			this->pnlFiltrar->Location = System::Drawing::Point(3, 199);
			this->pnlFiltrar->Name = L"pnlFiltrar";
			this->pnlFiltrar->Size = System::Drawing::Size(226, 83);
			this->pnlFiltrar->TabIndex = 10;
			// 
			// btnFiltrar
			// 
			this->btnFiltrar->Location = System::Drawing::Point(77, 51);
			this->btnFiltrar->Name = L"btnFiltrar";
			this->btnFiltrar->Size = System::Drawing::Size(75, 23);
			this->btnFiltrar->TabIndex = 8;
			this->btnFiltrar->Text = L"Filtrar datos";
			this->btnFiltrar->UseVisualStyleBackColor = true;
			// 
			// tbxFiltroValor
			// 
			this->tbxFiltroValor->Location = System::Drawing::Point(124, 25);
			this->tbxFiltroValor->Name = L"tbxFiltroValor";
			this->tbxFiltroValor->Size = System::Drawing::Size(99, 20);
			this->tbxFiltroValor->TabIndex = 4;
			// 
			// comboBoxFiltroCriterio
			// 
			this->comboBoxFiltroCriterio->FormattingEnabled = true;
			this->comboBoxFiltroCriterio->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Contiene a ...", L"No contiene a ...",
					L"Comienza con ...", L"Finaliza con ..."
			});
			this->comboBoxFiltroCriterio->Location = System::Drawing::Point(6, 25);
			this->comboBoxFiltroCriterio->Name = L"comboBoxFiltroCriterio";
			this->comboBoxFiltroCriterio->Size = System::Drawing::Size(112, 21);
			this->comboBoxFiltroCriterio->TabIndex = 3;
			// 
			// lblFiltroCriterio
			// 
			this->lblFiltroCriterio->AutoSize = true;
			this->lblFiltroCriterio->Location = System::Drawing::Point(3, 9);
			this->lblFiltroCriterio->Name = L"lblFiltroCriterio";
			this->lblFiltroCriterio->Size = System::Drawing::Size(99, 13);
			this->lblFiltroCriterio->TabIndex = 2;
			this->lblFiltroCriterio->Text = L"Criterio de filtración:";
			// 
			// FormPopUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(234, 379);
			this->Controls->Add(this->pnlFiltrar);
			this->Controls->Add(this->pnlOrdenar);
			this->Controls->Add(this->pnlNuevaTabla);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormPopUp";
			this->Text = L"FormPopUp";
			this->pnlNuevaTabla->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvNuevaTabla))->EndInit();
			this->pnlOrdenar->ResumeLayout(false);
			this->pnlOrdenar->PerformLayout();
			this->pnlFiltrar->ResumeLayout(false);
			this->pnlFiltrar->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCrearNuevaTabla_Click(System::Object^  sender, System::EventArgs^  e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
	}
};
}
