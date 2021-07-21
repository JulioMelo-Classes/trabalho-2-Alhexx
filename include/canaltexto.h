#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <string>
#include <vector>
#include <ostream>
#include "mensagem.h"

using std::string;
using std::vector;
using namespace std;

class CanalTexto {
private:
	string nome;
	vector<Mensagem> mensagens;

public:
	CanalTexto(string n);

	string get_nome();

	void add_mensagem();
	void print_mensagens(ostream &out_stream);
};

#endif

