/**
* @file   bebida.cpp
* @brief  Responsável por gerenciar os produtos dos tipos bebidas
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#include <iomanip> /**< Inclusão da lib iomanip*/
#include "../include/bebida.h" /**< Inclusão da Classe bebida.h*/
#include "../include/produto.h" /**< Inclusão da Classe produto.h*/

/**
* @brief Construtor padrão do objeto
*/
Bebida::Bebida(){
}

/**
* @brief Construtor parâmetrizado do objeto
*/
Bebida::Bebida(std::string _codigo, std::string _descricao, double _preco, double _teorAlcolico):
		Produto(_codigo, _descricao, _preco), m_teorAlcolico (_teorAlcolico){}

/**
* @brief Destrutor  do objeto
*/
Bebida::~Bebida(){}

/**
* @brief Método de acesso para o atributo teor alcólico
* @return atributo teor alcolico
*/
double Bebida::getTeorAlcolico(){
	return m_teorAlcolico;
}

/**
* @brief método de modificação do valor do atributo teor alcólico
* @param[in] Recebe teor alcólico do tipo double
* @return
*/
void Bebida::setTeorAlcolico(double _teorAlcolico) {
	m_teorAlcolico = _teorAlcolico;
}

/**
* @brief Efetua a impressão dos dados
* @param[in] variável para o <<
* @return valor do cout
*/
std::ostream& Bebida::print(std::ostream& o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | "
			<< std::setfill ('.') << std::setw (20) << m_descricao << " | "
			<< std::setfill (' ') << std::setw (5) << m_preco << " | "
			<< std::setfill (' ') << std::setw (5) << m_teorAlcolico;
		return o;
}

/**
* @brief Efetua a sobrecarga do operador <<
* @param[in] variável para o <<
* @param[in] Constante para guardar o objeto
* @return valor do cout
*/
std::ostream& operator<< (std::ostream &o, Bebida const &b){
	return b.print(o);
}

