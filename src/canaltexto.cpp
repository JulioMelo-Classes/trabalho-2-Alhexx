#include <string>
#include <ostream>
#include <vector>
#include "canaltexto.h"
#include "mensagem.h"

using namespace std;

CanalTexto::CanalTexto(string nome)
{
	this->nome = nome;
}

string CanalTexto::get_nome()
{
	return this->nome;
}

/*
void CanalTexto::add_mensagem(string mensagem)
{
	Mensagem("", id)
	this->mensagens.push_back(mensagem)
}
*/

void CanalTexto::print_mensagens(ostream &out_stream)
{
	for (auto& m : this->mensagens)
		out_stream << m.get_conteudo() << endl;
}
