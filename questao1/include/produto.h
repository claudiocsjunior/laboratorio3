/**
* @file   produto.h
* @brief  Classe base responsável por gerênciar os produtos
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#ifndef _PRODUTO_H_  /**< Verifica se a variável _PRODUTO_H_ foi definida*/
#define _PRODUTO_H_	 /**< Define a variável _PRODUTO_H_*/

#include <iostream>

class Produto
{
public:
	Produto(); /**< Construtor padrão da Classe*/
	Produto(std::string _codigo, std::string _descricao, double _preco); /**< Construtor parametrizado da Classe*/
	virtual ~Produto(); /**< Destrutor da Classe*/
protected:
	std::string m_cod_barras; /**< Variável para armazenar o codigo de barras*/
	std::string m_descricao; /**< Variável para armazenar a descrição do produto*/
	double m_preco;	/**< Variável para armazenar o preço do produto*/
public:
	/**
	* @brief Método de acesso para o atributo codigo de barras
	* @return atributo codigo de barras
	*/
	std::string getCodBarras();

	/**
	* @brief Método de acesso para o atributo descrição
	* @return atributo descrição
	*/
	std::string getDescricao();

	/**
	* @brief Método de acesso para o atributo preço
	* @return atributo preço
	*/
	double getPreco();

	/**
	* @brief método de modificação do valor do atributo codigo
	* @param[in] Recebe codigo do tipo string
	* @return
	*/
	void setCodBarras(std::string _codigo);

	/**
	* @brief método de modificação do valor do atributo descrição
	* @param[in] Recebe descrição do tipo string
	* @return
	*/
	void setDescricao(std::string _descricao);

	/**
	* @brief método de modificação do valor do atributo preço
	* @param[in] Recebe preço do tipo double
	* @return
	*/
	void setPreco(double _preco);

	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend std::ostream& operator<< (std::ostream &o, Produto const &t);  

	/**
	* @brief Efetua a sobrecarga do operador +
	* @param[in] Recebe o objeto que será somado
	* @return a soma do tipo double
	*/
	double operator+(Produto &produtoSomado);

	/**
	* @brief Efetua a sobrecarga do operador -
	* @param[in] Recebe o objeto que será subtraido
	* @return a subtração do tipo double
	*/
	double operator-(Produto &produtoSubtraido);

	/**
	* @brief Efetua a sobrecarga do operador ==
	* @param[in] Recebe o objeto que será comparado
	* @return booleano
	*/
	bool operator==(Produto &produtoComparado);
private: /**< Local para declaração de métodos e atributos privados*/
	/**
	* @brief Efetua a impressão dos dados
	* @param[in] variável para o <<
	* @return valor do cout
	*/
	virtual std::ostream& print(std::ostream&) const = 0;
};
 
#endif
