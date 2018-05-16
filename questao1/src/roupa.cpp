/**
* @file   roupa.cpp
* @brief  Responsável por gerenciar os produtos dos tipos roupas
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#include <iomanip> /**< Inclusão da lib iomanip*/
#include "../include/roupa.h" /**< Inclusão da classe roupa*/
#include "../include/produto.h" /**< Inclusão da classe produto*/

/**
* @brief Construtor padrão do objeto
*/
Roupa::Roupa() {
}

/**
* @brief Construtor parâmetrizado do objeto
*/
Roupa::Roupa(std::string _codigo, std::string _descricao, double _preco,
		std::string _marca, std::string _sexo, int _tamanho):
		Produto(_codigo, _descricao, _preco), m_marca (_marca), m_sexo(_sexo), m_tamanho(_tamanho)	{}

/**
* @brief Destrutor do objeto
*/
Roupa::~Roupa() {}

/**
* @brief Método de acesso para o atributo marca
* @return atributo marca
*/
std::string Roupa::getMarca() {
	return m_marca;
}

/**
* @brief Método de acesso para o atributo sexo
* @return atributo sexo
*/
std::string Roupa::getSexo() {
	return m_sexo;
}

/**
* @brief Método de acesso para o atributo tamanho
* @return atributo tamanho
*/
int Roupa::getTamanho() {
	return m_tamanho;
}

/**
* @brief método de modificação do valor do atributo marca
* @param[in] Recebe marca do tipo string
* @return
*/
void Roupa::setMarca(std::string _marca) {
	m_marca= _marca;
}

/**
* @brief método de modificação do valor do atributo sexo
* @param[in] Recebe sexo do tipo string
* @return
*/
void Roupa::setSexo(std::string _sexo) {
	m_sexo = _sexo;
}

/**
* @brief método de modificação do valor do atributo tamanho
* @param[in] Recebe tamanho do tipo inteiro
* @return
*/
void Roupa::setTamanho(int _tamanho) {
	m_tamanho = _tamanho;
}

/**
* @brief Efetua a sobrecarga do operador <<
* @param[in] variável para o <<
* @param[in] Constante para guardar o objeto
* @return valor do cout
*/
std::ostream& operator<< (std::ostream &o, Roupa const &r){
	return r.print(o);
}

/**
* @brief Efetua a impressão dos dados
* @param[in] variável para o <<
* @return valor do cout
*/
std::ostream& Roupa::print(std::ostream& o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | "
			<< std::setfill ('.') << std::setw (20) << m_descricao << " | "
			<< std::setfill (' ') << std::setw (5) << m_preco << " | "
			<< std::setfill (' ') << std::setw (10) << m_marca << " | "
			<< std::setfill (' ') << std::setw (10) << m_sexo << " | "
			<< std::setfill (' ') << std::setw (3) << m_tamanho;
		return o;
}
