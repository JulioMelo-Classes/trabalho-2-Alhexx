#include <string>
#include "mensagem.h"

Mensagem::Mensagem(string data_hora, int enviada_por, string conteudo)
{
    this->data_hora = data_hora;
    this->enviada_por = enviada_por;
    this->conteudo = conteudo;
}

string Mensagem::get_data_hora()
{
	return this->data_hora;
}

int Mensagem::get_enviada_por()
{
	return this->enviada_por;
}

string Mensagem::get_conteudo()
{
	return this->conteudo;
}
