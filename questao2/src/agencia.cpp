/**
* @file   agencia.cpp
* @brief  Responsável por gerênciar todas  as contas
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#include <iostream> /**<inclui a lib iostream*/
#include "../include/agencia.h" /**<inclui a classe agencia.h*/

using namespace std; /**<usa o namespace std*/

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
* @brief Método para crição de conta corrente
* @return
*/
void Agencia::adicionar_conta() {
	ContaCorrente conta_corrente;
	cin >> conta_corrente;
	cout << "(0) - Conta Normal, (1) - Conta Especial" << endl;
	int status;
	cin >> status;
	conta_corrente.setStatus(status);
	int tamanho = this->conta_corrente.size();
	bool existeIgual = false;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta_corrente[i] == conta_corrente)
			existeIgual = true;

	}

	if(existeIgual == false){
		this->conta_corrente.push_back(conta_corrente);
		cout << "Conta adicionada com sucesso" << endl;
		tamanho = this->conta_corrente.size();
		cout << "---Contas Adicionadas---" << endl;
		for (int j = 0;j != tamanho; ++j)
		{
			cout << this->conta_corrente[j] << endl;
		}
	}else{
		cout << "Erro. Conta existente" << endl;
	}


}

/**
* @brief Método para exclusão de conta corrente
* @return
*/
void Agencia::excluir_conta() {
	ContaCorrente conta_corrente;
	cin >> conta_corrente;
	int tamanho = this->conta_corrente.size();
	bool existeIgual = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta_corrente[i] == conta_corrente){
			existeIgual = true;
			posicao = i;
			break;
		}
	}

	if(existeIgual == true){
		this->conta_corrente.erase(this->conta_corrente.begin()+posicao);
		cout << "Conta Excluida com sucesso" << endl;
		tamanho = this->conta_corrente.size();
		cout << "---Contas Restantes---" << endl;
		for (int j = 0;j != tamanho; ++j)
		{
			cout << this->conta_corrente[j] << endl;
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
		cout << "(1) +    Adicionar Conta" << endl;
		cout << "(2) -    Excluir conta" << endl;
		cout << "(3) ->   Efetuar Saque" << endl;
		cout << "(4) <-   Efetuar Deposito" << endl;
		cout << "(5) $    Consultar Saldo" << endl;
		cout << "(6) #    Extrato" << endl;
		cout << "(7) $--> Transferência" << endl;
		cout << "(0) SAIR" <<endl;
		cin >> escolha;
		switch (escolha)
		{
			case 0:
				break;
			case 1:
				adicionar_conta();
				break;
			case 2:
				excluir_conta();
				break;
			case 3:
				saque();
				break;
			case 4:
				deposito();
				break;
			case 5:
				saldo();
				break;
			case 6:
				extrato();
				break;
			case 7:
				transferencia();
				break;
			default:
				cout <<"Opção invalida! "<< endl;
				escolha = 0;
		}
	}while(escolha > 0);
}

/**
* @brief Método para saque em conta corrente
* @return
*/
void Agencia::saque(){
	cout << "Digite os dados da conta para saque." << endl;
	ContaCorrente conta_corrente;
	cin >> conta_corrente;
	int tamanho = this->conta_corrente.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta_corrente[i] == conta_corrente){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		cout << "Digite o valor para saque" << endl;
		double valor;
		cin >> valor;
		if(this->conta_corrente[posicao].saque(valor)){
			cout << "saque efetuado com sucesso" << endl;
		}else{
			cout << "Erro no saque. Verifique se há quantia disponível na conta" << endl;
		}
	}else{
		cout << "Conta não encontrada no banco de dados da aplicação" << endl;
	}
}

/**
* @brief Método para depósito em conta corrente
* @return
*/
void Agencia::deposito(){
	cout << "Digite os dados da conta para depósito." << endl;
	ContaCorrente conta_corrente;
	cin >> conta_corrente;
	int tamanho = this->conta_corrente.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta_corrente[i] == conta_corrente){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		cout << "Digite o valor para deposito" << endl;
		double valor;
		cin >> valor;
		this->conta_corrente[posicao].deposito(valor);
	}else{
		cout << "Conta corrente não encontrada no banco de dados da aplicação" << endl;
	}
}

/**
* @brief Método para verificação do saldo de conta corrente
* @return
*/
void Agencia::saldo(){
	cout << "Digite os dados da conta para consultar o saldo." << endl;
	ContaCorrente conta_corrente;
	cin >> conta_corrente;
	int tamanho = this->conta_corrente.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta_corrente[i] == conta_corrente){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		cout << "Saldo: " << this->conta_corrente[posicao].consultar_saldo()   << endl;
	}else{
		cout << "Conta corrente não encontrada no banco de dados da aplicação" << endl;
	}

}

/**
* @brief Método para verificação do extrato de conta corrente
* @return
*/
void Agencia::extrato(){
	cout << "Digite os dados da conta para retirar o extrato." << endl;
	ContaCorrente conta_corrente;
	cin >> conta_corrente;
	int tamanho = this->conta_corrente.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta_corrente[i] == conta_corrente){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		cout << "Extrato da conta:" << endl;
		this->conta_corrente[posicao].consultar_extrato();
	}else{
		cout << "Conta corrente não encontrada no banco de dados da aplicação" << endl;
	}
}

/**
* @brief Método para transferências entra contas correntes
* @return
*/
void Agencia::transferencia(){
	cout << "Digite os dados da conta que será retirado o saldo." << endl;
	ContaCorrente conta_corrente_subtrair;
	cin >> conta_corrente_subtrair;
	int tamanho = this->conta_corrente.size();
	bool existe_conta_subtrair = false;
	int posicao1 = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta_corrente[i] == conta_corrente_subtrair){
			existe_conta_subtrair = true;
			posicao1 = i;
			break;
		}
	}

	cout << "Digite os dados da conta que será adicionado o saldo." << endl;
	ContaCorrente conta_corrente_adicionar;
	cin >> conta_corrente_adicionar;
	bool existe_conta_adicionar = false;
	int posicao2 = 0;
	for (int j = 0;j != tamanho; ++j)
	{
		if(this->conta_corrente[j] == conta_corrente_adicionar){
			existe_conta_adicionar = true;
			posicao2 = j;
			break;
		}
	}

	if(existe_conta_adicionar == true && existe_conta_subtrair == true){
		cout << "Digite o valor da tranferencia" << endl;
		int valor;
		cin >> valor;
		this->conta_corrente[posicao1].tranferencia( this->conta_corrente[posicao2],valor);
	}else{
		cout << "Erro. Conta Inesxistente" << endl;
	}

}


