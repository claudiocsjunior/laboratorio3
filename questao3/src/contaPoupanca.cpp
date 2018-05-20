/**
* @file   contaPoupanca.cpp
* @brief  Responsável por gerênciar as contas poupança
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/


#include "../include/contaPoupanca.h"
/**
* @brief Construtor padrão da classe
*/
ContaPoupanca::ContaPoupanca():Conta(1){
}

/**
* @brief Destrutor da classe
*/
ContaPoupanca::~ContaPoupanca() {
}

/**
* @brief Método para realizar saque
* @param[in] variável valor
* @return bool
*/
bool ContaPoupanca::saque(double valor){
	if(valor <= this->saldo){
		cout << "Quantia sacada " << valor << endl;
		this->saldo = this->saldo - valor;
		cout << "Quantia restante" << this->saldo << endl;
		Movimentacao movimentacao_debito("Saque", valor, "debito");
		this->movimentacao.push_back(movimentacao_debito);
		return true;
	}else{
		return false;
	}

}

/**
* @brief Método para realizar depósito
* @param[in] variável valor
* @return
*/
void ContaPoupanca::deposito(double valor){
	cout << "Quantia depositada " << valor << endl;
	this->saldo = this->saldo + valor;
	Movimentacao movimentacao_credito("Deposito", valor, "credito");
	this->movimentacao.push_back(movimentacao_credito);
	cout << "Depósito realizado com sucesso" << endl;
}
