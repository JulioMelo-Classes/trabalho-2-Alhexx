#ifndef USUARIO_H
#define USUARIO_H
#include <string>

using std::string;

/*
Classe usuário ok
*/
class Usuario {
private:
	int id;
	string nome;
	string email;
	string senha;

public:
	Usuario(int i, string n, string e, string s);

	int get_id();
	string get_nome();
	string get_email();

	bool igual_senha(string senha);
};

#endif

