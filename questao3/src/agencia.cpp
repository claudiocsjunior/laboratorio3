/**
* @file   agencia.cpp
* @brief  Responsável por gerênciar todas  as contas
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/
#include <iostream> /**<inclui a lib iostream*/
#include "../include/agencia.h" /**<inclui a classe agencia.h*/

using namespace std;

/**
* @brief Construtor padrão da classe
*/
Agencia::Agencia() {
}

/**
* @brief Destrutor da classe
*/
Agencia::~Agencia() {
}

/**
* @brief Método para adicionar conta corrente
* @return
*/
void Agencia::adicionar_conta_corrente() {
	ContaCorrente conta_corrente;
	cin >> conta_corrente;
	cout << "(0) - Conta Normal, (1) - Conta Especial" << endl;
	int status;
	cin >> status;
	conta_corrente.setStatus(status);
	int tamanho = this->conta.size();
	bool existeIgual = false;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta_corrente)
			existeIgual = true;

	}

	if(existeIgual == false){
		this->conta.push_back(conta_corrente);
		cout << "Conta adicionada com sucesso" << endl;
		tamanho = this->conta.size();
		cout << "---Contas Adicionadas---" << endl;
		for (int j = 0;j != tamanho; ++j)
		{
			cout << this->conta[j] << endl;
		}
	}else{
		cout << "Erro. Conta existente" << endl;
	}


}

/**
* @brief Método para adicionar conta poupança
* @return
*/
void Agencia::adicionar_conta_poupanca() {
	ContaPoupanca conta_poupanca;
	cin >> conta_poupanca;
	cout << "(0) - Conta Normal, (1) - Conta Especial" << endl;
	int status;
	cin >> status;
	conta_poupanca.setStatus(status);
	int tamanho = this->conta.size();
	bool existeIgual = false;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta_poupanca)
			existeIgual = true;

	}

	if(existeIgual == false){
		this->conta.push_back(conta_poupanca);
		cout << "Conta adicionada com sucesso" << endl;
		tamanho = this->conta.size();
		cout << "---Contas Adicionadas---" << endl;
		for (int j = 0;j != tamanho; ++j)
		{
			cout << this->conta[j] << endl;
		}
	}else{
		cout << "Erro. Conta existente" << endl;
	}


}

/**
* @brief Método para exclusão de conta
* @return
*/
void Agencia::excluir_conta() {
	Conta conta;
	cin >> conta;
	int tamanho = this->conta.size();
	bool existeIgual = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existeIgual = true;
			posicao = i;
			break;
		}
	}

	if(existeIgual == true){
		this->conta.erase(this->conta.begin()+posicao);
		cout << "Conta Excluida com sucesso" << endl;
		tamanho = this->conta.size();
		cout << "---Contas Restantes---" << endl;
		for (int j = 0;j != tamanho; ++j)
		{
			cout << this->conta[j] << endl;
		}
	}else{
		cout << "Conta não existente no banco de dados." << endl;
	}
}


/**
* @brief Método de acesso as funcionalidades
* @return
*/
void Agencia::funcionalidades() {
	int escolha;
	do{

		cout << "---AGÊNCIA FUNCIONALIDADES---" << endl;
		cout << "(1) +    Adicionar Conta Corrente" << endl;
		cout << "(2) +    Adicionar Conta Poupança" << endl;
		cout << "(3) -    Excluir conta" << endl;
		cout << "(4) ->   Efetuar Saque" << endl;
		cout << "(5) <-   Efetuar Deposito" << endl;
		cout << "(6) $    Consultar Saldo" << endl;
		cout << "(7) #    Extrato" << endl;
		cout << "(8) $--> Transferência" << endl;
		cout << "(0) SAIR" <<endl;
		cin >> escolha;
		switch (escolha)
		{
			case 0:
				break;
			case 1:
				adicionar_conta_corrente();
				break;
			case 2:
				adicionar_conta_poupanca();
				break;
			case 3:
				excluir_conta();
				break;
			case 4:
				saque();
				break;
			case 5:
				deposito();
				break;
			case 6:
				saldo();
				break;
			case 7:
				extrato();
				break;
			case 8:
				transferencia();
				break;
			default:
				cout <<"Opção invalida! "<< endl;
				escolha = 0;
		}
	}while(escolha > 0);
}

/**
* @brief Método para saque em conta
* @return
*/
void Agencia::saque(){
	cout << "Digite os dados da conta para saque." << endl;
	Conta conta;
	cin >> conta;
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		cout << "Digite o valor para saque" << endl;
		double valor;
		cin >> valor;
		if(this->conta[posicao].saque(valor)){
			cout << "saque efetuado com sucesso" << endl;
		}else{
			cout << "Erro no saque. Verifique se há quantia disponível na conta" << endl;
		}
	}else{
		cout << "Conta não encontrada no banco de dados da aplicação" << endl;
	}
}


/**
* @brief Método para depósito em conta
* @return
*/
void Agencia::deposito(){
	cout << "Digite os dados da conta para depósito." << endl;
	Conta conta;
	cin >> conta;
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		cout << "Digite o valor para deposito" << endl;
		double valor;
		cin >> valor;
		this->conta[posicao].deposito(valor);
	}else{
		cout << "Conta corrente não encontrada no banco de dados da aplicação" << endl;
	}
}

/**
* @brief Método para verificação do saldo de conta
* @return
*/
void Agencia::saldo(){
	cout << "Digite os dados da conta para consultar o saldo." << endl;
	Conta conta;
	cin >> conta;
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		cout << "Saldo: " << this->conta[posicao].consultar_saldo()   << endl;
	}else{
		cout << "Conta corrente não encontrada no banco de dados da aplicação" << endl;
	}

}

/**
* @brief Método para verificação do extrato de conta
* @return
*/
void Agencia::extrato(){
	cout << "Digite os dados da conta para retirar o extrato." << endl;
	Conta conta;
	cin >> conta;
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		cout << "Extrato da conta:" << endl;
		this->conta[posicao].consultar_extrato();
	}else{
		cout << "Conta corrente não encontrada no banco de dados da aplicação" << endl;
	}
}

/**
* @brief Método para transferências entra contas
* @return
*/
void Agencia::transferencia(){
	cout << "Digite os dados da conta que será retirado o saldo." << endl;
	Conta conta_subtrair;
	cin >> conta_subtrair;
	int tamanho = this->conta.size();
	bool existe_conta_subtrair = false;
	int posicao1 = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta_subtrair){
			existe_conta_subtrair = true;
			posicao1 = i;
			break;
		}
	}

	cout << "Digite os dados da conta que será adicionado o saldo." << endl;
	Conta conta_adicionar;
	cin >> conta_adicionar;
	bool existe_conta_adicionar = false;
	int posicao2 = 0;
	for (int j = 0;j != tamanho; ++j)
	{
		if(this->conta[j] == conta_adicionar){
			existe_conta_adicionar = true;
			posicao2 = j;
			break;
		}
	}

	if(existe_conta_adicionar == true && existe_conta_subtrair == true){
		cout << "Digite o valor da tranferencia" << endl;
		int valor;
		cin >> valor;
		this->conta[posicao1].tranferencia( this->conta[posicao2],valor);
	}

}


