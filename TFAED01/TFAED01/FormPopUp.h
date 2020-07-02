#pragma once
enum Option { NuevaTabla, Indexar, Filtrar, Ordenar, Buscar };
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
		System::Windows::Forms::Label^  lblOrdenCriterio;
		System::Windows::Forms::Button^  btnCrearNuevaTabla;
		System::Windows::Forms::Panel^  pnlFiltrar;
		System::Windows::Forms::Button^  btnFiltrar;
		System::Windows::Forms::Button^  btnOrdenar;
		System::Windows::Forms::Panel^  pnlIndexar;
		System::Windows::Forms::Button^  btnIndexar;
		System::Windows::Forms::Panel^  pnlQColumna;
		System::Windows::Forms::Button^  btnBuscar;
		System::Windows::Forms::Label^  lblQColumna;
		System::Windows::Forms::Label^  lblAuxQColumna;
		System::Windows::Forms::DataGridViewTextBoxColumn^  ColName;
		System::Windows::Forms::DataGridViewComboBoxColumn^  ColTipo;
		System::Windows::Forms::Label^  lblAuxQColumna2;
		System::Windows::Forms::Panel^  pnlBuscar;
	public: 
		System::Windows::Forms::TextBox^  tbxFiltroValor;
		System::Windows::Forms::ComboBox^  comboBoxFiltroCriterio;
		System::Windows::Forms::Label^  lblFiltroCriterio;
		System::Windows::Forms::ComboBox^  comboBoxQColumna;
		System::Windows::Forms::ComboBox^  comboBoxOrdenar;
		System::Windows::Forms::ComboBox^  comboBoxAuxQColumna;
		System::Windows::Forms::TextBox^  tbxFiltroValor2;
		System::Windows::Forms::ComboBox^  comboBoxFiltroCriterio2;
		System::Windows::Forms::Label^  lblFiltroCriterio2;
		System::Windows::Forms::ComboBox^  comboBoxAuxQColumna2;
		System::Windows::Forms::TextBox^  tbxBusquedaValor;

		System::Windows::Forms::DataGridView^  dgvNuevaTabla;
	public:
		FormPopUp(void)
		{
			InitializeComponent();
			pnlQColumna->SetBounds(3, 7, pnlQColumna->Width, pnlQColumna->Height);
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
			pnlIndexar->Visible = false; pnlIndexar->Enabled = false;
			pnlFiltrar->Visible = false; pnlFiltrar->Enabled = false;
			pnlOrdenar->Visible = false; pnlOrdenar->Enabled = false;
			pnlBuscar->Visible = false; pnlBuscar->Enabled = false;
			pnlQColumna->Visible = false; pnlQColumna->Enabled = false;
		}

		void ComoAbrirPopUp(Option o) {
			switch (o)
			{
			case NuevaTabla: FormPopUp::Height = pnlNuevaTabla->Height + 45;
				pnlNuevaTabla->Visible = true; pnlNuevaTabla->Enabled = true;
				pnlNuevaTabla->SetBounds(3, 7, pnlNuevaTabla->Width, pnlNuevaTabla->Height);
				this->Text = "Crear nueva"; break;
			case Indexar: FormPopUp::Height = pnlFiltrar->Height + 45 + 34;
				pnlIndexar->Visible = true; pnlIndexar->Enabled = true;
				pnlIndexar->SetBounds(3, 7 + 34,
					pnlIndexar->Width, pnlIndexar->Height);
				this->Text = "Indexar";  break;
			case Filtrar: FormPopUp::Height = pnlFiltrar->Height + 45 + 34; 
				pnlFiltrar->Visible = true; pnlFiltrar->Enabled = true;
				pnlFiltrar->SetBounds(3, 7 + 34,
					pnlFiltrar->Width, pnlFiltrar->Height);
				this->Text = "Filtro";  break;
			case Ordenar: FormPopUp::Height = pnlOrdenar->Height + 45 + 34; 
				pnlOrdenar->Visible = true; pnlOrdenar->Enabled = true; 
				pnlOrdenar->SetBounds(3, 7 + 34, 
					pnlOrdenar->Width, pnlOrdenar->Height);
				this->Text = "Ordenar"; break;
			case Buscar: FormPopUp::Height = pnlBuscar->Height + 45 + 34;
				pnlBuscar->Visible = true; pnlBuscar->Enabled = true;
				pnlBuscar->SetBounds(3, 7 + 34,
					pnlBuscar->Width, pnlBuscar->Height);
				this->Text = "Buscar"; break;
			} if (o != NuevaTabla) { pnlQColumna->Visible = true; pnlQColumna->Enabled = true; }
		}

		String^ GetNombre(bool tipo, int fila) {
			if (tipo)
				return dgvNuevaTabla[1, fila]->Value->ToString();
			return dgvNuevaTabla[0, fila]->Value->ToString();
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
			this->btnOrdenar = (gcnew System::Windows::Forms::Button());
			this->comboBoxOrdenar = (gcnew System::Windows::Forms::ComboBox());
			this->lblOrdenCriterio = (gcnew System::Windows::Forms::Label());
			this->pnlFiltrar = (gcnew System::Windows::Forms::Panel());
			this->tbxFiltroValor2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxFiltroCriterio2 = (gcnew System::Windows::Forms::ComboBox());
			this->lblFiltroCriterio2 = (gcnew System::Windows::Forms::Label());
			this->comboBoxAuxQColumna2 = (gcnew System::Windows::Forms::ComboBox());
			this->btnFiltrar = (gcnew System::Windows::Forms::Button());
			this->lblAuxQColumna2 = (gcnew System::Windows::Forms::Label());
			this->tbxFiltroValor = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxFiltroCriterio = (gcnew System::Windows::Forms::ComboBox());
			this->lblFiltroCriterio = (gcnew System::Windows::Forms::Label());
			this->pnlIndexar = (gcnew System::Windows::Forms::Panel());
			this->comboBoxAuxQColumna = (gcnew System::Windows::Forms::ComboBox());
			this->lblAuxQColumna = (gcnew System::Windows::Forms::Label());
			this->btnIndexar = (gcnew System::Windows::Forms::Button());
			this->pnlQColumna = (gcnew System::Windows::Forms::Panel());
			this->comboBoxQColumna = (gcnew System::Windows::Forms::ComboBox());
			this->lblQColumna = (gcnew System::Windows::Forms::Label());
			this->pnlBuscar = (gcnew System::Windows::Forms::Panel());
			this->tbxBusquedaValor = (gcnew System::Windows::Forms::TextBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->pnlNuevaTabla->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvNuevaTabla))->BeginInit();
			this->pnlOrdenar->SuspendLayout();
			this->pnlFiltrar->SuspendLayout();
			this->pnlIndexar->SuspendLayout();
			this->pnlQColumna->SuspendLayout();
			this->pnlBuscar->SuspendLayout();
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
			this->ColTipo->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"int", L"double", L"string" });
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
			this->pnlOrdenar->Controls->Add(this->btnOrdenar);
			this->pnlOrdenar->Controls->Add(this->comboBoxOrdenar);
			this->pnlOrdenar->Controls->Add(this->lblOrdenCriterio);
			this->pnlOrdenar->Location = System::Drawing::Point(3, 361);
			this->pnlOrdenar->Name = L"pnlOrdenar";
			this->pnlOrdenar->Size = System::Drawing::Size(226, 85);
			this->pnlOrdenar->TabIndex = 1;
			// 
			// btnOrdenar
			// 
			this->btnOrdenar->Location = System::Drawing::Point(77, 52);
			this->btnOrdenar->Name = L"btnOrdenar";
			this->btnOrdenar->Size = System::Drawing::Size(75, 23);
			this->btnOrdenar->TabIndex = 9;
			this->btnOrdenar->Text = L"Ordenar";
			this->btnOrdenar->UseVisualStyleBackColor = true;
			this->btnOrdenar->Click += gcnew System::EventHandler(this, &FormPopUp::btnOrdenar_Click);
			// 
			// comboBoxOrdenar
			// 
			this->comboBoxOrdenar->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxOrdenar->FormattingEnabled = true;
			this->comboBoxOrdenar->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Ascendente", L"Descendente" });
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
			this->pnlFiltrar->Controls->Add(this->tbxFiltroValor2);
			this->pnlFiltrar->Controls->Add(this->comboBoxFiltroCriterio2);
			this->pnlFiltrar->Controls->Add(this->lblFiltroCriterio2);
			this->pnlFiltrar->Controls->Add(this->comboBoxAuxQColumna2);
			this->pnlFiltrar->Controls->Add(this->btnFiltrar);
			this->pnlFiltrar->Controls->Add(this->lblAuxQColumna2);
			this->pnlFiltrar->Controls->Add(this->tbxFiltroValor);
			this->pnlFiltrar->Controls->Add(this->comboBoxFiltroCriterio);
			this->pnlFiltrar->Controls->Add(this->lblFiltroCriterio);
			this->pnlFiltrar->Location = System::Drawing::Point(3, 199);
			this->pnlFiltrar->Name = L"pnlFiltrar";
			this->pnlFiltrar->Size = System::Drawing::Size(226, 156);
			this->pnlFiltrar->TabIndex = 10;
			// 
			// tbxFiltroValor2
			// 
			this->tbxFiltroValor2->Location = System::Drawing::Point(124, 96);
			this->tbxFiltroValor2->Name = L"tbxFiltroValor2";
			this->tbxFiltroValor2->Size = System::Drawing::Size(99, 20);
			this->tbxFiltroValor2->TabIndex = 15;
			// 
			// comboBoxFiltroCriterio2
			// 
			this->comboBoxFiltroCriterio2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxFiltroCriterio2->FormattingEnabled = true;
			this->comboBoxFiltroCriterio2->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Es igual a...", L"Es menor que...",
					L"Es mayor que...", L"Contiene a ...", L"No contiene a ...", L"Inicia con ...", L"Finaliza con ..."
			});
			this->comboBoxFiltroCriterio2->Location = System::Drawing::Point(6, 96);
			this->comboBoxFiltroCriterio2->Name = L"comboBoxFiltroCriterio2";
			this->comboBoxFiltroCriterio2->Size = System::Drawing::Size(112, 21);
			this->comboBoxFiltroCriterio2->TabIndex = 14;
			// 
			// lblFiltroCriterio2
			// 
			this->lblFiltroCriterio2->AutoSize = true;
			this->lblFiltroCriterio2->Location = System::Drawing::Point(3, 80);
			this->lblFiltroCriterio2->Name = L"lblFiltroCriterio2";
			this->lblFiltroCriterio2->Size = System::Drawing::Size(99, 13);
			this->lblFiltroCriterio2->TabIndex = 13;
			this->lblFiltroCriterio2->Text = L"Criterio de filtración:";
			// 
			// comboBoxAuxQColumna2
			// 
			this->comboBoxAuxQColumna2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAuxQColumna2->FormattingEnabled = true;
			this->comboBoxAuxQColumna2->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Ninguna" });
			this->comboBoxAuxQColumna2->Location = System::Drawing::Point(84, 56);
			this->comboBoxAuxQColumna2->Name = L"comboBoxAuxQColumna2";
			this->comboBoxAuxQColumna2->Size = System::Drawing::Size(139, 21);
			this->comboBoxAuxQColumna2->TabIndex = 11;
			// 
			// btnFiltrar
			// 
			this->btnFiltrar->Location = System::Drawing::Point(77, 122);
			this->btnFiltrar->Name = L"btnFiltrar";
			this->btnFiltrar->Size = System::Drawing::Size(75, 23);
			this->btnFiltrar->TabIndex = 8;
			this->btnFiltrar->Text = L"Filtrar datos";
			this->btnFiltrar->UseVisualStyleBackColor = true;
			this->btnFiltrar->Click += gcnew System::EventHandler(this, &FormPopUp::btnFiltrar_Click);
			// 
			// lblAuxQColumna2
			// 
			this->lblAuxQColumna2->AutoSize = true;
			this->lblAuxQColumna2->Location = System::Drawing::Point(27, 59);
			this->lblAuxQColumna2->Name = L"lblAuxQColumna2";
			this->lblAuxQColumna2->Size = System::Drawing::Size(51, 13);
			this->lblAuxQColumna2->TabIndex = 12;
			this->lblAuxQColumna2->Text = L"Columna:";
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
			this->comboBoxFiltroCriterio->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxFiltroCriterio->FormattingEnabled = true;
			this->comboBoxFiltroCriterio->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Es igual a...", L"Es menor que...",
					L"Es mayor que...", L"Contiene a ...", L"No contiene a ...", L"Inicia con ...", L"Finaliza con ..."
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
			// pnlIndexar
			// 
			this->pnlIndexar->Controls->Add(this->comboBoxAuxQColumna);
			this->pnlIndexar->Controls->Add(this->lblAuxQColumna);
			this->pnlIndexar->Controls->Add(this->btnIndexar);
			this->pnlIndexar->Location = System::Drawing::Point(3, 452);
			this->pnlIndexar->Name = L"pnlIndexar";
			this->pnlIndexar->Size = System::Drawing::Size(226, 72);
			this->pnlIndexar->TabIndex = 10;
			// 
			// comboBoxAuxQColumna
			// 
			this->comboBoxAuxQColumna->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAuxQColumna->FormattingEnabled = true;
			this->comboBoxAuxQColumna->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Ninguna" });
			this->comboBoxAuxQColumna->Location = System::Drawing::Point(84, 8);
			this->comboBoxAuxQColumna->Name = L"comboBoxAuxQColumna";
			this->comboBoxAuxQColumna->Size = System::Drawing::Size(139, 21);
			this->comboBoxAuxQColumna->TabIndex = 10;
			// 
			// lblAuxQColumna
			// 
			this->lblAuxQColumna->AutoSize = true;
			this->lblAuxQColumna->Location = System::Drawing::Point(27, 11);
			this->lblAuxQColumna->Name = L"lblAuxQColumna";
			this->lblAuxQColumna->Size = System::Drawing::Size(51, 13);
			this->lblAuxQColumna->TabIndex = 10;
			this->lblAuxQColumna->Text = L"Columna:";
			// 
			// btnIndexar
			// 
			this->btnIndexar->Location = System::Drawing::Point(77, 37);
			this->btnIndexar->Name = L"btnIndexar";
			this->btnIndexar->Size = System::Drawing::Size(75, 23);
			this->btnIndexar->TabIndex = 9;
			this->btnIndexar->Text = L"Indexar";
			this->btnIndexar->UseVisualStyleBackColor = true;
			this->btnIndexar->Click += gcnew System::EventHandler(this, &FormPopUp::btnIndexar_Click);
			// 
			// pnlQColumna
			// 
			this->pnlQColumna->Controls->Add(this->comboBoxQColumna);
			this->pnlQColumna->Controls->Add(this->lblQColumna);
			this->pnlQColumna->Location = System::Drawing::Point(3, 610);
			this->pnlQColumna->Name = L"pnlQColumna";
			this->pnlQColumna->Size = System::Drawing::Size(226, 34);
			this->pnlQColumna->TabIndex = 10;
			// 
			// comboBoxQColumna
			// 
			this->comboBoxQColumna->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxQColumna->FormattingEnabled = true;
			this->comboBoxQColumna->Location = System::Drawing::Point(84, 6);
			this->comboBoxQColumna->Name = L"comboBoxQColumna";
			this->comboBoxQColumna->Size = System::Drawing::Size(139, 21);
			this->comboBoxQColumna->TabIndex = 9;
			// 
			// lblQColumna
			// 
			this->lblQColumna->AutoSize = true;
			this->lblQColumna->Location = System::Drawing::Point(27, 9);
			this->lblQColumna->Name = L"lblQColumna";
			this->lblQColumna->Size = System::Drawing::Size(51, 13);
			this->lblQColumna->TabIndex = 9;
			this->lblQColumna->Text = L"Columna:";
			// 
			// pnlBuscar
			// 
			this->pnlBuscar->Controls->Add(this->tbxBusquedaValor);
			this->pnlBuscar->Controls->Add(this->btnBuscar);
			this->pnlBuscar->Location = System::Drawing::Point(3, 530);
			this->pnlBuscar->Name = L"pnlBuscar";
			this->pnlBuscar->Size = System::Drawing::Size(226, 74);
			this->pnlBuscar->TabIndex = 11;
			// 
			// tbxBusquedaValor
			// 
			this->tbxBusquedaValor->Location = System::Drawing::Point(21, 12);
			this->tbxBusquedaValor->Name = L"tbxBusquedaValor";
			this->tbxBusquedaValor->Size = System::Drawing::Size(185, 20);
			this->tbxBusquedaValor->TabIndex = 16;
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(77, 38);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(75, 23);
			this->btnBuscar->TabIndex = 9;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &FormPopUp::btnBuscar_Click);
			// 
			// FormPopUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(234, 653);
			this->Controls->Add(this->pnlBuscar);
			this->Controls->Add(this->pnlQColumna);
			this->Controls->Add(this->pnlIndexar);
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
			this->pnlIndexar->ResumeLayout(false);
			this->pnlIndexar->PerformLayout();
			this->pnlQColumna->ResumeLayout(false);
			this->pnlQColumna->PerformLayout();
			this->pnlBuscar->ResumeLayout(false);
			this->pnlBuscar->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCrearNuevaTabla_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			for (int i = 0; i < dgvNuevaTabla->RowCount - 1; i++) {
				dgvNuevaTabla[0, i]->Value->ToString();
				dgvNuevaTabla[1, i]->Value->ToString();
			}
			dgvNuevaTabla->Sort(dgvNuevaTabla->Columns[0], ListSortDirection::Ascending);
			if (dgvNuevaTabla->RowCount > 1)
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
		}
		catch (Exception ^ex)
		{
			MessageBox::Show("Complete todos los cuadros faltantes." 
				+ "\n*La ultima fila puede estar vacía.");
		}
	}

	private: System::Void btnFiltrar_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxQColumna->SelectedIndex != -1 && tbxFiltroValor->Text != "" && comboBoxFiltroCriterio->SelectedIndex != -1) {
			if (comboBoxAuxQColumna2->SelectedIndex == 0)
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
			else if (comboBoxAuxQColumna2->SelectedIndex > 0 && tbxFiltroValor2->Text != "" && comboBoxFiltroCriterio2->SelectedIndex != -1)
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
		}
	}
	private: System::Void btnOrdenar_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxQColumna->SelectedIndex != -1 && comboBoxOrdenar->SelectedIndex != -1)
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
	}
	private: System::Void btnIndexar_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxQColumna->SelectedIndex != -1 && comboBoxAuxQColumna->SelectedIndex != -1)
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
	}
	private: System::Void btnBuscar_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxQColumna->SelectedIndex != -1 && tbxBusquedaValor->Text != "")
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
	}
};
}
