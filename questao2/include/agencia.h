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

class Agencia
{
private:
	std::vector<ContaCorrente> conta_corrente; /**< Variável para armazenar a descrição*/
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
	* @brief Método para crição de conta corrente
	* @return
	*/
	void adicionar_conta();

	/**
	* @brief Método para exclusão de conta corrente
	* @return
	*/
	void excluir_conta();

	/**
	* @brief Método de acesso as funcionalidades
	* @return
	*/
	void funcionalidades();

	/**
	* @brief Método para saque em conta corrente
	* @return
	*/
	void saque();

	/**
	* @brief Método para depósito em conta corrente
	* @return
	*/
	void deposito();

	/**
	* @brief Método para verificação do saldo de conta corrente
	* @return
	*/
	void saldo();

	/**
	* @brief Método para verificação do extrato de conta corrente
	* @return
	*/
	void extrato();

	/**
	* @brief Método para transferências entra contas correntes
	* @return
	*/
	void transferencia();
};

#endif
