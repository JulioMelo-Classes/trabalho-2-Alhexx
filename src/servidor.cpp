#include <string>
#include <ostream>
#include "servidor.h"

using namespace std;

Servidor::Servidor(int dono_id, string nome)
{
	this->usuario_dono_id = dono_id;
	this->nome = nome;
	this->descricao = "";
	this->codigo_convite = "";
	this->participantes_id.push_back(dono_id);
}

int Servidor::get_usuario_dono_id()
{
	return this->usuario_dono_id;
}

string Servidor::get_nome()
{
	return this->nome;
}

string Servidor::get_descricao()
{
	return this->descricao;
}

string Servidor::get_codigo_convite()
{
	return this->codigo_convite;
}

void Servidor::set_descricao(string descricao)
{
	this->descricao = descricao;
}

void Servidor::set_codigo_convite(string convite)
{
	this->codigo_convite = convite;
}

void Servidor::add_participantes(int id)
{
	this->participantes_id.push_back(id);
}

bool Servidor::equal_participantes(int id)
{
	for(auto& i : this->participantes_id) {
		if (i == id)
			return true;
	}
	return false;
}

void Servidor::print_canais_texto(ostream& out_stream)
{
	for (auto& c : this->canais_texto)
		out_stream << c.get_nome() << endl;
}

void Servidor::print_participantes_id(ostream& out_stream)
{
	for (auto& p : this->participantes_id)
		out_stream << p << endl;
}
