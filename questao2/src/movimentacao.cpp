/**
* @file   movimentacao.cpp
* @brief  Responsável por gerênciar os movimentos por conta
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#include "../include/movimentacao.h" /**<inclui a classe movimentacao.h*/

/**
* @brief Construtor padrão do objeto
*/
Movimentacao::Movimentacao() {
}

/**
* @brief Construtor parâmetrizado do objeto
*/
Movimentacao::Movimentacao(std::string descricao, double valor, std::string tipo):
	descricao(descricao), valor(valor), tipo(tipo){}

/**
* @brief Destrutor do objeto
*/
Movimentacao::~Movimentacao() {
}

/**
* @brief Método de acesso para o atributo descrição
* @return atributo descrição
*/
const std::string& Movimentacao::getDescricao() const {
	return descricao;
}

/**
* @brief método de modificação do valor do atributo descrição
* @param[in] Recebe descrição do tipo string
* @return
*/
void Movimentacao::setDescricao(const std::string& descricao) {
	this->descricao = descricao;
}

/**
* @brief Método de acesso para o atributo valor
* @return atributo valor
*/
double Movimentacao::getValor() const {
	return valor;
}

/**
* @brief método de modificação do valor do atributo valor
* @param[in] Recebe codigo do tipo double
* @return
*/
void Movimentacao::setValor(double valor) {
	this->valor = valor;
}

/**
* @brief Efetua a sobrecarga do operador <<
* @param[in] variável para o <<
* @param[in] Constante para guardar o objeto
* @return valor do cout
*/
ostream& operator<<(ostream &e, Movimentacao const m){
	e << "Descrição: "<< m.descricao
		  << "| Valor: " << m.valor
		  << "| tipo: " <<  m.tipo
		  << endl;
		return e;
}
