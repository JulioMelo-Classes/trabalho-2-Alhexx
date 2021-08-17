#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <string>

using namespace std;

/*
CP2 ok

Documentação: vou considerar 80% da documentação, uma vez que faltou documentar os atributos
*/
class Mensagem {
private:
	string data_hora; //<! faltou documentação dos atributos
	int enviada_por;
	string conteudo;

public:
	/*o formato doxygen usa dois * no começo do cabeçalho, talvez o editor de vcs não tenha marcado*/
	/**
	 * @brief Constructor. Also data_hora is auto-generated.
	 * @param enviada_por Sender's ID.
	 * @param conteudo Message's content.
	 */
	Mensagem(int enviada_por, string conteudo);

	/* @brief Getters for attributes.
	 * @return Value of corresponding attribute.
	 */
	string get_data_hora();
	int get_enviada_por();
	string get_conteudo();
};

#endif

