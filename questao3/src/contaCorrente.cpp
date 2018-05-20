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
ContaCorrente::ContaCorrente():Conta(0){

}

/**
* @brief Destrutor da classe
*/
ContaCorrente::~ContaCorrente(){

}

/**
* @brief Método para realizar saque
* @param[in] variável valor
* @return bool
*/
bool ContaCorrente::saque(double valor){
	if(valor <= this->saldo){
		cout << "Quantia sacada " << valor << endl;
		this->saldo = this->saldo - valor;
		cout << "Quantia restante" << this->saldo << endl;
		Movimentacao movimentacao_debito("Saque", valor, "debito");
		this->movimentacao.push_back(movimentacao_debito);
		return true;
	}
	else if(valor > this->saldo && valor <= this->limite){
		cout << "Quantia sacada do saldo " << this->saldo << endl;
		valor = valor - this->saldo;
		this->saldo = 0;
		cout << "Quantia sacada do limite " << valor << endl;
		this->limite = this->limite - valor;
		cout << "Limite disponivel: " << this->limite << endl;
		Movimentacao movimentacao_debito("Saque/Retirado do limite", valor, "debito");
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
void ContaCorrente::deposito(double valor){
	cout << "Quantia depositada " << valor << endl;
	if(this->limite < 2000){
		this->limite = this->limite + valor;
		if(this->limite > 2000){
			int valor_restado = this->limite - 2000;
			this->limite = 2000;
			this->saldo = valor_restado;
		}
	}else{
		this->saldo = this->saldo + valor;
	}
	Movimentacao movimentacao_credito("Deposito", valor, "credito");
	this->movimentacao.push_back(movimentacao_credito);
	cout << "Depósito realizado com sucesso" << endl;
}


/**
* @brief Método para consultar limite de conta corrente
* @return tipo da conta
*/
void ContaCorrente::consultar_limite() {
	cout << "Saldo devedor: " << 2000 - this->limite << endl;
	cout << "Limite: " << this->limite << endl;
}
