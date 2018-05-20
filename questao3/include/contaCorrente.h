/**
* @file   contaCorrente.h
* @brief  Classe responsável por gerênciar as contas correntes
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#ifndef _CONTACORRENTE_H_ /**< Verifica se a variável _CONTACORRENTE_H_ foi definida*/
#define _CONTACORRENTE_H_ /**< Define a variável _CONTACORRENTE_H_*/

#include <iostream> /**<inclui a lib iostream*/
#include "movimentacao.h" /**<inclui a classe movimentacao.h*/
#include <vector> /**<inclui a lib vector*/
#include <stdlib.h> /**<inclui a lib stdlib.h*/
#include "conta.h" /**<inclui a classe conta.h*/

using namespace std; /**<Usa namespace std*/

class ContaCorrente : public Conta
{

public:
	/**
	* @brief Construtor padrão da classe
	*/
	ContaCorrente();
	/**
	* @brief Destrutor da classe
	*/
	~ContaCorrente();


	/**
	* @brief Método para realizar saque na poupança
	* @param[in] variável valor
	* @return bool
	*/
	bool saque(double valor);


	/**
	* @brief Método para realizar depósito
	* @param[in] variável valor
	* @return
	*/
	void deposito(double valor);


	/**
	* @brief Método para consultar limite de conta corrente
	* @return tipo da conta
	*/
	void consultar_limite();
};

#endif
