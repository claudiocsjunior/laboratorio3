/**
* @file   fruta.cpp
* @brief  Responsável por gerenciar os produtos dos tipos frutas
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#include <iomanip> /**< Inclusão da lib iomanip*/
#include "../include/fruta.h" /**< Inclusão da classe fruta.h*/

/**
* @brief Construtor padrão do objeto
*/
Fruta::Fruta() {}

/**
* @brief Construtor parâmetrizado do objeto
*/
Fruta::Fruta(std::string _codigo, std::string _descricao, double _preco,
	std::string _data, short _validade):
	Produto(_codigo, _descricao, _preco), m_data_lote(_data), m_validade(_validade) {}

/**
* @brief Destrutor do objeto
*/
Fruta::~Fruta() {}

/**
* @brief Método de acesso para o atributo data lote
* @return atributo data lote
*/
std::string 
Fruta::getDataLote() {
	return m_data_lote;
}

/**
* @brief Método de acesso para o atributo validade
* @return atributo validade
*/
short
Fruta::getValidade() {
	return m_validade;
}

/**
* @brief método de modificação do valor do atributo data lote
* @param[in] Recebe data do tipo string
* @return
*/
void 
Fruta::setDataLote(std::string _data) {
	m_data_lote = _data;
}

/**
* @brief método de modificação do valor do atributo validade
* @param[in] Recebe validade do tipo double
* @return
*/
void 
Fruta::setValidade(short _validade) {
	m_validade = _validade;
}
 
/**
* @brief Efetua a impressão dos dados
* @param[in] variável para o <<
* @return valor do cout
*/
std::ostream& 
Fruta::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << m_data_lote << " | " 
		<< std::setfill (' ') << std::setw (3) << m_validade;
	return o;
}

/**
* @brief Efetua a sobrecarga do operador <<
* @param[in] variável para o <<
* @param[in] Constante para guardar o objeto
* @return valor do cout
*/
std::ostream& operator<< (std::ostream &o, Fruta const &t){
	return t.print(o);

}
