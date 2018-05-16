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

using namespace std; /**<Usa namespace std*/

class ContaCorrente
{
private:
	std::string agencia;/**< Variável para armazenar a agencia*/
	std::string numero;/**< Variável para armazenar o numero*/
	double saldo;/**< Variável para armazenar o saldo*/
	int status; /**< Variável para armazenar o status, 0 - normal; 1 - especial; */
	double limite; /**< Variável para armazenar o limite, 2000 - default */
	std::vector<Movimentacao> movimentacao;/**< Vetor para armazenar as movimentações*/
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
	* @brief Método para exclusão de conta corrente
	* @return agencia
	*/
	const std::string& getAgencia() const;

	/**
	* @brief Método de modificação para o atributo agencia
	* @param[in] variável agencia
	* @return
	*/
	void setAgencia(const std::string& agencia);

	/**
	* @brief Método de acesso para o limite da conta
	* @return limite
	*/
	double getLimite() const;

	/**
	* @brief Método de modificação para o atributo limite
	* @param[in] variável limite
	* @return
	*/
	void setLimite(double limite);

	/**
	* @brief Método de acesso para as movimentações
	* @return movimentacao
	*/
	const std::vector<Movimentacao>& getMovimentacao() const;

	/**
	* @brief Método de modificação para o atributo movimentação
	* @param[in] variável movimentacão
	* @return
	*/
	void setMovimentacao(const std::vector<Movimentacao>& movimentacao);

	/**
	* @brief Método de acesso ao numero da conta
	* @return numero
	*/
	const std::string& getNumero() const;

	/**
	* @brief Método de modificação para o atributo numero
	* @param[in] variável numero
	* @return
	*/
	void setNumero(const std::string& numero);

	/**
	* @brief Método de acesso ao saldo
	* @return saldo
	*/
	double getSaldo() const;

	/**
	* @brief Método de modificação para o atributo saldo
	* @param[in] variável saldo
	* @return
	*/
	void setSaldo(double saldo);

	/**
	* @brief Método de acesso para o status da conta
	* @return status
	*/
	const int getStatus() const;

	/**
	* @brief Método de modificação para o atributo status
	* @param[in] variável status
	* @return
	*/
	void setStatus(const int status);

	/**
	* @brief Método para realizar saque
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
	* @brief Método para realizar transferências
	* @param[in] conta a tranferir
	* @param[in] variável valor
	* @return agencia
	*/
	void tranferencia(ContaCorrente &conta_tranferir, double valor);
	/**
	* @brief Método para consulta do saque
	* @return
	*/
	double consultar_saldo();

	/**
	* @brief Método para consulta do extrato
	* @return
	*/
	void consultar_extrato();

	/**
	* @brief Método para adicionar movimentação na tranferência
	* @return
	*/
	void add_movimentacao(std::string descricao, double valor, std::string tipo);

	/**
	* @brief Efetua a sobrecarga do operador >>
	* @param[in] variável para o >>
	* @param[in] Constante para guardar o objeto
	* @return valor do cin
	*/
	friend istream& operator>>(istream &a, ContaCorrente &c);

	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, ContaCorrente const c);

	/**
	* @brief Efetua a sobrecarga do operador ==
	* @param[in] Constante para guardar o objeto a ser comparado
	* @return booleano
	*/
	bool operator==(ContaCorrente &conta_comparada);
};

#endif
