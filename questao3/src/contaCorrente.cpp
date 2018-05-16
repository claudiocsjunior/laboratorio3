/**
* @file   contaCorrente.cpp
* @brief  Responsável por gerênciar as contas correntes
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#include "../include/contaCorrente.h" /**<inclui a classe contaCorrente.h*/

/**
* @brief Construtor padrão da classe
*/
ContaCorrente::ContaCorrente(){

}

/**
* @brief Destrutor da classe
*/
ContaCorrente::~ContaCorrente(){

}

/**
* @brief Método acesso a taxa mensal
* @return taxa mensal
*/
double ContaCorrente::getTaxaMensal() const {
	return this->taxa_mensal;
}

/**
* @brief Método para modificação da taxa mensal
* @return
*/
void ContaCorrente::setTaxaMensal(double taxaMensal) {
	this->taxa_mensal = taxaMensal;
}
