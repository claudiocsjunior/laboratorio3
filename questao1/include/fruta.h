/**
* @file   fruta.h
* @brief  Classe responsável por gerenciar os produtos dos tipos frutas
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#ifndef _FRUTA_H_  /**< Verifica se a variável _FRUTA_H_ foi definida*/
#define _FRUTA_H_	 /**< Define a variável _FRUTA_H_*/

#include "produto.h" /**< Inclusão da classe produto.h*/

class Fruta : public Produto
{
public:
	Fruta(); /**< Construtor padrão da Classe*/
	Fruta(std::string _codigo, std::string _descricao, double _preco,
			std::string _data, short _validade); /**< Construtor parametrizado da Classe*/
	~Fruta(); /**< Destrutor da Classe*/
private: /**< Local para declaração de atributos privados*/
	std::string m_data_lote; /**< Variável para armazenar a data do lote*/
	short m_validade; /**< Variável para armazenar a validade*/
public:
	/**
	* @brief Método de acesso para o atributo data lote
	* @return atributo data lote
	*/
	std::string getDataLote();

	/**
	* @brief Método de acesso para o atributo validade
	* @return atributo validade
	*/
	short getValidade();

	/**
	* @brief método de modificação do valor do atributo data lote
	* @param[in] Recebe data do tipo string
	* @return
	*/
	void setDataLote(std::string _data);

	/**
	* @brief método de modificação do valor do atributo validade
	* @param[in] Recebe validade do tipo double
	* @return
	*/
	void setValidade(short _validade);

	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend std::ostream& operator<< (std::ostream &o, Fruta const &t);
private: /**< Local para declaração de métodos privados*/
	/**
	* @brief Efetua a impressão dos dados
	* @param[in] variável para o <<
	* @return valor do cout
	*/
	std::ostream& print(std::ostream &o) const;
};

#endif
