#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <string>
#include <vector>
#include <ostream>
#include "canaltexto.h"

using namespace std;

/*
Classe servidor ok
*/
class Servidor {
private:
	int usuario_dono_id;
	string nome;
	string descricao;
	string codigo_convite;
	vector<CanalTexto> canais_texto;
	vector<int> participantes_id;

public:
	Servidor(int udi, string n);

	int get_usuario_dono_id();
	string get_nome();
	string get_descricao();
	string get_codigo_convite();


	void set_descricao(string descricao);
	void set_codigo_convite(string codigo);

	void add_participantes(int id);
	bool equal_participantes(int id);

	void print_canais_texto(ostream& out_stream);
	
	/*neste caso o melhor era receber o vetor de participantes também como referencia*/
	void print_participantes_id(ostream& out_stream);
};

#endif

