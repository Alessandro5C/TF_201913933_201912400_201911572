#pragma once
#include "FormPopUp.h"
#include "CTabla.h"
#include "HeapSort.h"
#include "Filtros.h"
#include <fstream>
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
	private: System::Windows::Forms::DataGridView^  dgvAux;
	private: System::Windows::Forms::Splitter^  splitter1;
	private: System::Windows::Forms::ToolStripButton^  tsbtnBuscar;



	private: CTabla* tbl;
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			tsbtnIndexar->Enabled = false; tsbtnFiltrar->Enabled = false; tsbtnOrdenar->Enabled = false;
		}
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}

		void MarshalString(String ^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		} //Convierte String^ a std::string

		//Para dgvPrincipal
		void AñadirColumna(String ^name, String^ tipo) {
			//Para el DGV
			int i = dgvPrincipal->ColumnCount;
			dgvPrincipal->Columns->Add("Columna" + i.ToString(), name);
			dgvPrincipal->Columns[i]->SortMode 
				= DataGridViewColumnSortMode::NotSortable;
			//Para nuestra clase Cols
			string aux_nombre, aux_tipo;
			MarshalString(name, aux_nombre); MarshalString(tipo, aux_tipo);
			CCols* aux_col = new CCols(aux_nombre, aux_tipo); tbl->addCol(aux_col);
			//nose si hay q borrar
		}
		//Para dgvAux
		void AñadirColumna(String ^name) {
			int i = dgvAux->ColumnCount;
			dgvAux->Columns->Add("Columna" + i.ToString(), name);
			dgvAux->Columns[i]->SortMode
				= DataGridViewColumnSortMode::NotSortable;
		}

		void AñadirFila() {

		}

		bool IsItCorrect(String^ auxs, string tipo) {
			if (tipo == "int") {
				int number;
				return Int32::TryParse(auxs, number);
			} else if (tipo == "double") {
				double fraccion;
				return Double::TryParse(auxs, fraccion);
			}
		}

		int LastRowIsComplete() {
			try
			{
				string aux_nombre;
				for (int i = 0; i < dgvPrincipal->ColumnCount; i++) {
					MarshalString(dgvPrincipal->Columns[i]->HeaderText, aux_nombre);
					if (tbl->getCol(aux_nombre)->getType() == "int") {
						if (!IsItCorrect(dgvPrincipal[i, dgvPrincipal->RowCount - 1]->Value->ToString(), "int"))
							return 0;
					} else if (tbl->getCol(aux_nombre)->getType() == "double") {
						if (!IsItCorrect(dgvPrincipal[i, dgvPrincipal->RowCount - 1]->Value->ToString(), "double"))
							return 0;
					} else { dgvPrincipal[i, dgvPrincipal->RowCount - 1]->Value->ToString(); }
				} return 1;
			}
			catch (Exception ^ex) { return 0; }
		}

		void ShowOnAux(CTabla* grup) {
			//Crear las columnas a mostrar
			for (int idxg = 0; idxg < grup->getNcols(); idxg++)
				AñadirColumna(dgvPrincipal->Columns[idxg]->HeaderText);
			//Crear las filas a mostrar
			string aux_nombre; int auxi;
			for (int i = 0; i < grup->getNfilas(); i++) {
				dgvAux->Rows->Add(); //Añade nueva fila
				for (int idxg = 0; idxg < grup->getNcols(); idxg++) {
					MarshalString(dgvPrincipal->Columns[idxg]->HeaderText, aux_nombre);
					auxi = tbl->getFila(i)->getidx();
					String ^name = gcnew String(tbl->getCol(aux_nombre)->getDato(auxi).c_str());
					dgvAux[idxg, i]->Value = name; delete name;
				}
			}
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
			this->tsbtnBuscar = (gcnew System::Windows::Forms::ToolStripButton());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dgvPrincipal = (gcnew System::Windows::Forms::DataGridView());
			this->dgvAux = (gcnew System::Windows::Forms::DataGridView());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPrincipal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAux))->BeginInit();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {
				this->toolStripSplitButton1,
					this->toolStripButton7, this->toolStripSeparator1, this->toolStripSeparator2, this->tsbtnIndexar, this->toolStripSeparator3,
					this->tsbtnFiltrar, this->toolStripSeparator4, this->tsbtnOrdenar, this->toolStripSeparator5, this->tsbtnBuscar
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
			this->tsbtnIndexar->Enabled = false;
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
			this->tsbtnFiltrar->Enabled = false;
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
			this->tsbtnOrdenar->Enabled = false;
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
			// tsbtnBuscar
			// 
			this->tsbtnBuscar->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->tsbtnBuscar->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tsbtnBuscar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbtnBuscar.Image")));
			this->tsbtnBuscar->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbtnBuscar->Name = L"tsbtnBuscar";
			this->tsbtnBuscar->Size = System::Drawing::Size(62, 22);
			this->tsbtnBuscar->Text = L"Buscar en";
			this->tsbtnBuscar->Click += gcnew System::EventHandler(this, &MenuPrincipal::tsbtnBuscar_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// dgvPrincipal
			// 
			this->dgvPrincipal->AllowUserToAddRows = false;
			this->dgvPrincipal->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvPrincipal->Location = System::Drawing::Point(0, 25);
			this->dgvPrincipal->Name = L"dgvPrincipal";
			this->dgvPrincipal->Size = System::Drawing::Size(844, 485);
			this->dgvPrincipal->TabIndex = 2;
			this->dgvPrincipal->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MenuPrincipal::dgvPrincipal_KeyPress);
			// 
			// dgvAux
			// 
			this->dgvAux->AllowUserToAddRows = false;
			this->dgvAux->AllowUserToDeleteRows = false;
			this->dgvAux->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvAux->Dock = System::Windows::Forms::DockStyle::Right;
			this->dgvAux->Location = System::Drawing::Point(778, 25);
			this->dgvAux->Name = L"dgvAux";
			this->dgvAux->ReadOnly = true;
			this->dgvAux->Size = System::Drawing::Size(66, 485);
			this->dgvAux->TabIndex = 4;
			// 
			// splitter1
			// 
			this->splitter1->Dock = System::Windows::Forms::DockStyle::Right;
			this->splitter1->Location = System::Drawing::Point(775, 25);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(3, 485);
			this->splitter1->TabIndex = 5;
			this->splitter1->TabStop = false;
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(844, 510);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->dgvAux);
			this->Controls->Add(this->dgvPrincipal);
			this->Controls->Add(this->toolStrip1);
			this->Name = L"MenuPrincipal";
			this->Text = L"MiniSGBD";
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPrincipal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAux))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void tsbtnGuardarArch_Click(System::Object^  sender, System::EventArgs^  e) {
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//código aquí
			string aux_arch, aux_last_col; 
			MarshalString(saveFileDialog1->FileName->ToString(), aux_arch);
			MarshalString(dgvPrincipal->Columns[dgvPrincipal->ColumnCount - 1]->HeaderText->ToString(), aux_last_col);
			tbl->saveOnArch(aux_arch, aux_last_col);
		}

	}

	private: System::Void tsbtnAbrirArch_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//código aquí
			/*
			string auxs; MarshalString(openFileDialog1->FileName->ToString(), auxs);
			std::ifstream arch(auxs);
			if (arch.is_open() == NULL)
			{
				MessageBox::Show(L"Ha ocurrido un error, intente nuevamente.", "Atención",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				_exit(0);
			}

			*/
		}
	}
	private: System::Void tsbtnNuevaTabla_Click(System::Object^  sender, System::EventArgs^  e) {
		FormPopUp ^fpu = gcnew FormPopUp();
		fpu->ComoAbrirPopUp(NuevaTabla); tbl = new CTabla();
		if (fpu->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			dgvPrincipal->Rows->Clear(); dgvPrincipal->Columns->Clear();
			for (int i = 0; i < fpu->dgvNuevaTabla->RowCount - 1; i++)
				AñadirColumna(fpu->GetNombre(false, i), fpu->GetNombre(true, i));
			dgvPrincipal->Rows->Add(); 
			tsbtnIndexar->Enabled = true; tsbtnFiltrar->Enabled = true; tsbtnOrdenar->Enabled = true;
		}
		delete fpu;
	}
	private: System::Void tsbtnIndexar_Click(System::Object^  sender, System::EventArgs^  e) {
		FormPopUp ^fpu = gcnew FormPopUp();
		for (int i = 0; i < dgvPrincipal->ColumnCount; i++)
			fpu->comboBoxQColumna->Items->Add(dgvPrincipal->Columns[i]->HeaderText);
		for (int i = 0; i < fpu->comboBoxQColumna->Items->Count; i++)
			fpu->comboBoxAuxQColumna->Items->Add(fpu->comboBoxQColumna->Items[i]);
		fpu->ComoAbrirPopUp(Indexar);
		//código aquí
		if (fpu->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			string aux_nombre;
			MarshalString(dgvPrincipal->Columns[fpu->comboBoxQColumna->SelectedIndex]->HeaderText, aux_nombre);
			
			tbl->indexar(aux_nombre);
			if (fpu->comboBoxAuxQColumna->SelectedIndex > 0) {
				MarshalString(dgvPrincipal->Columns[fpu->comboBoxAuxQColumna->SelectedIndex - 1]->HeaderText, aux_nombre);
				tbl->indexar(aux_nombre);
			}

		} delete fpu;

	}
	private: System::Void tsbtnFiltrar_Click(System::Object^  sender, System::EventArgs^  e) {
		FormPopUp ^fpu = gcnew FormPopUp();
		for (int i = 0; i < dgvPrincipal->ColumnCount; i++)
			fpu->comboBoxQColumna->Items->Add(dgvPrincipal->Columns[i]->HeaderText);
		for (int i = 0; i < dgvPrincipal->ColumnCount; i++)
			fpu->comboBoxAuxQColumna2->Items->Add(dgvPrincipal->Columns[i]->HeaderText);
		fpu->ComoAbrirPopUp(Filtrar);
		//código aquí
		if (fpu->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			dgvAux->Rows->Clear(); dgvAux->Columns->Clear();

			string aux_nombre, aux_cmp;
			MarshalString(dgvPrincipal->Columns[fpu->comboBoxQColumna->SelectedIndex]->HeaderText, aux_nombre);
			MarshalString(fpu->tbxFiltroValor->Text, aux_cmp);
			if (fpu->comboBoxAuxQColumna2->SelectedIndex == 0) //un solo filtro
			{
				switch (fpu->comboBoxFiltroCriterio->SelectedIndex)
				{
				case 0: tbl->filtrar(aux_nombre, aux_cmp, filtro_igual); break;
				case 1: tbl->filtrar(aux_nombre, aux_cmp, filtro_menor); break;
				case 2: tbl->filtrar(aux_nombre, aux_cmp, filtro_mayor); break;
				case 3: tbl->filtrar(aux_nombre, aux_cmp, filtro_contenido); break;
				case 4: tbl->filtrar(aux_nombre, aux_cmp, filtro_nocontenido); break;
				case 5: tbl->filtrar(aux_nombre, aux_cmp, filtro_inicia); break;
				case 6: tbl->filtrar(aux_nombre, aux_cmp, filtro_finaliza); break;
				}
			}
			else //doble filtro
			{
				switch (fpu->comboBoxFiltroCriterio->SelectedIndex)
				{
				case 0: fx_primero = filtro_igual; break;
				case 1: fx_primero = filtro_menor; break;
				case 2: fx_primero = filtro_mayor; break;
				case 3: fx_primero = filtro_contenido; break;
				case 4: fx_primero = filtro_nocontenido; break;
				case 5: fx_primero = filtro_inicia; break;
				case 6: fx_primero = filtro_finaliza; break;
				}
				string aux_nombre2, aux_cmp2;
				MarshalString(dgvPrincipal->Columns[fpu->comboBoxAuxQColumna2->SelectedIndex - 1]->HeaderText, aux_nombre2);
				MarshalString(fpu->tbxFiltroValor2->Text, aux_cmp2);
				switch (fpu->comboBoxFiltroCriterio2->SelectedIndex)
				{
				case 0: tbl->filtrar(aux_nombre, aux_cmp, fx_primero, aux_nombre2, aux_cmp2, filtro_igual); break;
				case 1: tbl->filtrar(aux_nombre, aux_cmp, fx_primero, aux_nombre2, aux_cmp2, filtro_menor); break;
				case 2: tbl->filtrar(aux_nombre, aux_cmp, fx_primero, aux_nombre2, aux_cmp2, filtro_mayor); break;
				case 3: tbl->filtrar(aux_nombre, aux_cmp, fx_primero, aux_nombre2, aux_cmp2, filtro_contenido); break;
				case 4: tbl->filtrar(aux_nombre, aux_cmp, fx_primero, aux_nombre2, aux_cmp2, filtro_nocontenido); break;
				case 5: tbl->filtrar(aux_nombre, aux_cmp, fx_primero, aux_nombre2, aux_cmp2, filtro_inicia); break;
				case 6: tbl->filtrar(aux_nombre, aux_cmp, fx_primero, aux_nombre2, aux_cmp2, filtro_finaliza); break;
				}
			}
		} delete fpu;
	}
			
	private: System::Void tsbtnOrdenar_Click(System::Object^  sender, System::EventArgs^  e) {
		FormPopUp ^fpu = gcnew FormPopUp();
		for (int i = 0; i < dgvPrincipal->ColumnCount; i++)
			fpu->comboBoxQColumna->Items->Add(dgvPrincipal->Columns[i]->HeaderText);
		fpu->ComoAbrirPopUp(Ordenar); CTabla* tblaux = new CTabla();
		//código aquí
		if (fpu->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			dgvAux->Rows->Clear(); dgvAux->Columns->Clear(); tblaux = tbl;
			string aux_nombre;
			MarshalString(dgvPrincipal->Columns[fpu->comboBoxQColumna->SelectedIndex]->HeaderText, aux_nombre);
			string aux_tipo = tbl->getCol(aux_nombre)->getType();

			if (fpu->comboBoxOrdenar->SelectedIndex == 0) { //Ascendente
				if (aux_tipo == "int") {
					vector<int> aux;
					for (auto e : tbl->getCol(aux_nombre)->getAllData())
						aux.push_back(stoi(e));
					maxheapSort(aux, aux.size(), tblaux);
				} else if (aux_tipo == "double") {
					vector<double> aux;
					for (auto e : tbl->getCol(aux_nombre)->getAllData())
						aux.push_back(stod(e));
					maxheapSort(aux, aux.size(), tblaux);
				} else {
					vector<string> aux = tbl->getCol(aux_nombre)->getAllData();
					maxheapSort(aux, aux.size(), tblaux);
				}
			} else if (fpu->comboBoxOrdenar->SelectedIndex == 1) { //Descendente
				if (aux_tipo == "int") {
					vector<int> aux;
					for (auto e : tbl->getCol(aux_nombre)->getAllData())
						aux.push_back(stoi(e));
					minheapSort(aux, aux.size(), tblaux);
				}
				else if (aux_tipo == "double") {
					vector<double> aux;
					for (auto e : tbl->getCol(aux_nombre)->getAllData())
						aux.push_back(stod(e));
					minheapSort(aux, aux.size(), tblaux);
				} else {
					vector<string> aux = tbl->getCol(aux_nombre)->getAllData();
					minheapSort(aux, aux.size(), tblaux);
				}
			} 
			ShowOnAux(tblaux); //Mostrar en la otra tabla
		} delete fpu, tblaux;
	}

	private: System::Void tsbtnBuscar_Click(System::Object^  sender, System::EventArgs^  e) {
		FormPopUp ^fpu = gcnew FormPopUp();
		for (int i = 0; i < dgvPrincipal->ColumnCount; i++)
			fpu->comboBoxQColumna->Items->Add(dgvPrincipal->Columns[i]->HeaderText);
		fpu->ComoAbrirPopUp(Buscar);
		if (fpu->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			//código aquí
			string aux_nombre, aux_dato;
			MarshalString(dgvPrincipal->Columns[fpu->comboBoxQColumna->SelectedIndex]->HeaderText, aux_nombre);
			MarshalString(fpu->tbxBusquedaValor->Text, aux_dato);
			tbl->buscar(aux_nombre, aux_dato);
		}
		delete fpu;
	}

	private: System::Void dgvPrincipal_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {		
		if (LastRowIsComplete() == 1) {
			dgvPrincipal->Rows[dgvPrincipal->RowCount - 1]->ReadOnly = true;
			//Para nuestra clase Tabla
			string aux_nombre, aux_dato; 
			CTabla::CFila* aux_fila = tbl->addFila(); //Añade nueva fila
			for (int idxg = 0; idxg < dgvPrincipal->ColumnCount; idxg++)
			{
				MarshalString(dgvPrincipal->Columns[idxg]->HeaderText->ToString(), aux_nombre);
				MarshalString(dgvPrincipal[idxg, dgvPrincipal->RowCount - 1]->Value->ToString(), aux_dato);
				aux_fila->add(aux_nombre, aux_dato); //Añade los valores de cada celda de la fila
			}
			dgvPrincipal->Rows->Add(); //Añade nueva fila
		}
	}
};
}
