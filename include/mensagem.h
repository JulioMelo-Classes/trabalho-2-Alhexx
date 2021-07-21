#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <string>

using std::string;

class Mensagem {
private:
	string data_hora;
	int enviada_por;
	string conteudo;

public:
	Mensagem(string dh, int ep, string c);

	string get_data_hora();
	int get_enviada_por();
	string get_conteudo();
};

#endif

