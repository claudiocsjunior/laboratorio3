/**
* @file   contaPoupanca.h
* @brief  Classe responsável por gerênciar as contas poupança
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#ifndef _CONTAPOUPANCA_H_ /**< Verifica se a variável _CONTAPOUPANCA_H_ foi definida*/
#define _CONTAPOUPANCA_H_ /**< Define a variável _CONTAPOUPANCA_H_*/

#include <iostream> /**<inclui a lib iostream*/
#include "movimentacao.h" /**<inclui a classe movimentacao.h*/
#include <vector> /**<inclui a lib vector*/
#include <stdlib.h> /**<inclui a lib stdlib.h*/
#include "conta.h" /**<inclui a classe conta.h*/

using namespace std; /**<Usa namespace std*/

class ContaPoupanca : public Conta
{
public:
	/**
	* @brief Construtor padrão da classe
	*/
	ContaPoupanca();
	/**
	* @brief Destrutor da classe
	*/
	~ContaPoupanca();
};

#endif
