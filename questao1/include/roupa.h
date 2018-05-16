/**
* @file   roupa.h
* @brief  Classe responsável por gerenciar os produtos dos tipos roupas
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#ifndef _ROUPA_H_  /**< Verifica se a variável _ROUPA_H_ foi definida*/
#define _ROUPA_H_	 /**< Define a variável _ROUPA_H_*/

#include "produto.h" /**< Inclusão da classe produto.h*/

class Roupa : public Produto
{
public:
	Roupa(); /**< Construtor padrão da Classe*/
	Roupa(std::string _codigo, std::string _descricao, double _preco, std::string _marca, std::string _sexo, int _tamanho); /**< Construtor Paramtrizado da Classe*/
	~Roupa(); /**< Destrutor da Classe*/
private: /**< Local para declaração de atributos privados*/
	std::string m_marca; /**< Variável para armazenar a marca*/
	std::string m_sexo; /**< Variável para armazenar o sexo*/
	int m_tamanho; /**< Variável para armazenar o tamamho*/
public:
	/**
	* @brief Método de acesso para o atributo marca
	* @return atributo marca
	*/
	std::string getMarca();

	/**
	* @brief Método de acesso para o atributo sexo
	* @return atributo sexo
	*/
	std::string getSexo();

	/**
	* @brief Método de acesso para o atributo tamanho
	* @return atributo tamanho
	*/
	int getTamanho();

	/**
	* @brief método de modificação do valor do atributo marca
	* @param[in] Recebe marca do tipo string
	* @return
	*/
	void setMarca(std::string _marca);

	/**
	* @brief método de modificação do valor do atributo sexo
	* @param[in] Recebe sexo do tipo string
	* @return
	*/
	void setSexo(std::string _sexo);

	/**
	* @brief método de modificação do valor do atributo tamanho
	* @param[in] Recebe tamanho do tipo inteiro
	* @return
	*/
	void setTamanho(int _tamanho);

	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend std::ostream& operator<< (std::ostream &o, Roupa const &t);
private: /**< Local para declaração de métodos privados*/
	/**
	* @brief Efetua a impressão dos dados
	* @param[in] variável para o <<
	* @return valor do cout
	*/
	std::ostream& print(std::ostream &o) const;
};

#endif
