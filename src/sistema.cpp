#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "sistema.h"
#include "usuario.h"
#include "servidor.h"

using namespace std;

template <typename StreamableT>
string concat(StreamableT s)
{
	stringstream ss;
	ss << s;
	return ss.str();
}

template <typename StreamableHead, typename... StreamableTail>
string concat(StreamableHead h, StreamableTail... t)
{
	stringstream ss;
	ss << h;
	return ss.str() + concat(t...);
}

/* COMANDOS */
string Sistema::quit()
{
	return ">>>Adios...";
}

string Sistema::create_user(const string email, const string senha, const string nome)
{
	if (email == "")
        	return ">>>Voce esqueceu de botar um email, tente novamente...";
	if (senha == "")
        	return ">>>Voce esqueceu de botar uma senha, tente novamente...";
	if (nome == "")
        	return ">>>Voce esqueceu de botar um nome, tente novamente...";

	for (auto& u : this->usuarios) {
		if (email == u.get_email())
			return ">>>Email já utilizado, brother...";
		if (nome == u.get_nome())
			return ">>>Nome já utilizado, brother...";
	}

	int id = this->usuarios.size() + 1;
	Usuario usuario(id, nome, email, senha);
	this->usuarios.push_back(usuario);

	//return ">>>Usuario criado com sucesso, filhão. Seu id é: " + to_string(id);
	return concat(">>>Usuario criado com sucesso, filhão. Seu id é: ", id);
}

string Sistema::login(const string email, const string senha)
{
	for (auto& u : this->usuarios) {
		if (email == u.get_email() && !u.igual_senha(senha))
			return ">>>Senha incorreta, consagrado...";

		if (email == u.get_email() && u.igual_senha(senha)) {
			if (this->usuarios_logados.count(u.get_id()))
				return ">>>Usuário já está logado...";

			this->usuarios_logados[u.get_id()] = make_pair("","");
			return ">>>Conectado com sucesso!";
		}
	}
	return ">>>Email nao cadastrado, consagrado...";
}

string Sistema::disconnect(int id)
{
	if (!this->usuarios_logados.count(id))
		return ">>>Usuário já está desconectado...";

	this->usuarios_logados.erase(id);
	return ">>>Desconectado com sucesso!";
}

string Sistema::create_server(int id, const string nome)
{
	if (!this->usuarios_logados.count(id))
		return ">>>Usuario não está logado...";

	for (auto& s : this->servidores) {
		if (nome == s.get_nome())
			return ">>>Servidor com este nome ja criado...";
	}

	Servidor servidor(id, nome);
	this->servidores.push_back(servidor);
	return ">>>Servidor criado com sucesso!";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao)
{
	if (!this->usuarios_logados.count(id))
		return ">>>Usuario não está logado...";

	for (auto& s : this->servidores) {
		if (nome == s.get_nome()) {
			if (id != s.get_usuario_dono_id())
				return ">>>Id não é o dono do servidor...";

			s.set_descricao(descricao);
			return ">>>Descrição do servidor criada!";
		}
	}
	return ">>>Servidor inexistente...";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo)
{
	if (!this->usuarios_logados.count(id))
		return ">>>Usuario não está logado...";

	for (auto& s : this->servidores) {
		if (nome == s.get_nome()) {
			if (id != s.get_usuario_dono_id())
				return ">>>Id não é o dono do servidor...";

			s.set_codigo_convite(codigo);
			return ">>>Descrição do servidor criada!";
		}
	}
	return ">>>Servidor inexistente...";
}

string Sistema::list_servers(int id)
{
	vector<string> servidores_nome;
	if (!this->usuarios_logados.count(id))
		return ">>>Usuario não está logado...";

	for (auto& s : this->servidores)
			servidores_nome.push_back(s.get_nome());

	if (servidores_nome.size() == 0)
		return ">>>Nenhum servidor foi criado ainda...";

	int size = servidores_nome.size()-1;
	for (int i = 0; i<size; i++) {
		cout << "- " << servidores_nome[i] << endl;
	}
	return "- " + servidores_nome[size];
}

string Sistema::remove_server(int id, const string nome)
{
	if (!this->usuarios_logados.count(id))
		return ">>>Usuario não está logado...";

	for (auto& u : usuarios) {
		if (this->usuarios_logados[u.get_id()].first == nome)
			this->usuarios_logados[u.get_id()].first == "";
	}

	auto i = servidores.begin();
	while (i != servidores.end()) {
		if (i->get_nome() == nome) {
			if (i->get_usuario_dono_id() != id)
				return "Usuario nao e dono do servidor...";

			servidores.erase(i);
			return "Servidor removido com sucesso!";
		}
		++i;
	}
	return "Servidor nao existe...";
}

string Sistema::enter_server(int id, const string nome, const string codigo)
{
	if (!this->usuarios_logados.count(id))
		return ">>>Usuario não está logado...";

	for (auto& s : this->servidores) {
		if (nome == s.get_nome()) {
			if (this->usuarios_logados[id].first == nome)
				return ">>>Usuário já está no servidor...";

			if (codigo != s.get_codigo_convite())
				return ">>>Código inválido...";

			this->usuarios_logados[id].first = nome;
			return ">>>Usuário entrou no servidor com sucesso!";
		}
	}
	return ">>>Servidor inexistente...";
}

string Sistema::leave_server(int id, const string nome)
{
	if (!this->usuarios_logados.count(id))
		return ">>>Usuario não está logado...";

	for (auto& s : this->servidores) {
		if (nome == s.get_nome()) {
			if (this->usuarios_logados[id].first != nome)
				return ">>>Usuário não está no servidor...";

			this->usuarios_logados[id].first = "";
			return ">>>Usuário saiu do servidor com sucesso!";
		}
	}
	return ">>>Servidor inexistente...";
}

string Sistema::list_participants(int id)
{
	return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id)
{
	return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome)
{
	return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome)
{
	return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id)
{
	return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem)
{
	return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id)
{
	return "list_messages NÃO IMPLEMENTADO";
}

/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
