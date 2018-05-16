/**
* @file   agencia.h
* @brief  Classe responsável por gerênciar todas  as contas
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#ifndef _AGENCIA_H_ /**< Verifica se a variável _AGENCIA_H_ foi definida*/
#define _AGENCIA_H_ /**< Define a variável _AGENCIA_H_*/


#include <iostream> /**<inclui a lib iostream*/
#include "contaCorrente.h" /**<inclui a classe contaCorrente.h*/
#include <vector> /**<inclui a lib vector*/
#include "contaPoupanca.h" /**<inclui a classe contaPoupanca.h*/
#include "conta.h" /**<inclui a classe conta*/

class Agencia
{
private:
	std::vector<Conta> conta; /**< Variável para armazenar a descrição*/
public:
	/**
	* @brief Construtor padrão da classe
	*/
	Agencia();

	/**
	* @brief Destrutor da classe
	*/
	~Agencia();
	/**
	* @brief Método para adicionar conta corrente
	* @return
	*/
	void adicionar_conta_corrente();

	/**
	* @brief Método para adicionar conta poupança
	* @return
	*/
	void adicionar_conta_poupanca();
	/**
	* @brief Método para exclusão de conta
	* @return
	*/
	void excluir_conta();

	/**
	* @brief Método de acesso as funcionalidades
	* @return
	*/
	void funcionalidades();

	/**
	* @brief Método para saque em conta
	* @return
	*/
	void saque();

	/**
	* @brief Método para depósito em conta
	* @return
	*/
	void deposito();

	/**
	* @brief Método para verificação do saldo de conta
	* @return
	*/
	void saldo();

	/**
	* @brief Método para verificação do extrato de conta
	* @return
	*/
	void extrato();

	/**
	* @brief Método para transferências entra contas
	* @return
	*/
	void transferencia();
};

#endif
