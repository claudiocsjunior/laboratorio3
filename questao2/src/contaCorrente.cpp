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
ContaCorrente::ContaCorrente() {
	this->agencia = "";
	this->numero = "";
	this->saldo = 0;
	this->status = 0;
	this->limite = 2000;

}

/**
* @brief Método para exclusão de conta corrente
* @return agencia
*/
const std::string& ContaCorrente::getAgencia() const {
	return agencia;
}

/**
* @brief Método de modificação para o atributo agencia
* @param[in] variável agencia
* @return
*/
void ContaCorrente::setAgencia(const std::string& agencia) {
	this->agencia = agencia;
}

/**
* @brief Método de acesso para o limite da conta
* @return limite
*/
double ContaCorrente::getLimite() const {
	return limite;
}

/**
* @brief Método de modificação para o atributo limite
* @param[in] variável limite
* @return
*/
void ContaCorrente::setLimite(double limite) {
	this->limite = limite;
}

/**
* @brief Método de acesso para as movimentações
* @return movimentacao
*/
const std::vector<Movimentacao>& ContaCorrente::getMovimentacao() const {
	return movimentacao;
}

/**
* @brief Método de modificação para o atributo movimentação
* @param[in] variável movimentacão
* @return
*/
void ContaCorrente::setMovimentacao(
		const std::vector<Movimentacao>& movimentacao) {
	this->movimentacao = movimentacao;
}

/**
* @brief Método de acesso ao numero da conta
* @return numero
*/
const std::string& ContaCorrente::getNumero() const {
	return numero;
}

/**
* @brief Método de modificação para o atributo numero
* @param[in] variável numero
* @return
*/
void ContaCorrente::setNumero(const std::string& numero) {
	this->numero = numero;
}

/**
* @brief Método de acesso ao saldo
* @return saldo
*/
double ContaCorrente::getSaldo() const {
	return saldo;
}

/**
* @brief Método de modificação para o atributo saldo
* @param[in] variável saldo
* @return
*/
void ContaCorrente::setSaldo(double saldo) {
	this->saldo = saldo;
}

/**
* @brief Método de acesso para o status da conta
* @return status
*/
const int ContaCorrente::getStatus() const {
	return status;
}

/**
* @brief Método de modificação para o atributo status
* @param[in] variável status
* @return
*/
void ContaCorrente::setStatus(const int status) {
	this->status = status;
}

/**
* @brief Efetua a sobrecarga do operador >>
* @param[in] variável para o >>
* @param[in] Constante para guardar o objeto
* @return valor do cin
*/
istream& operator>>(istream &a, ContaCorrente &c){
	cin.ignore();
	cout << "Digite a agência da conta: " << endl;
	a >> c.agencia;
	cout << "Digite o numero da conta: " << endl;
	a >> c.numero;
	return a;
}

/**
* @brief Efetua a sobrecarga do operador <<
* @param[in] variável para o <<
* @param[in] Constante para guardar o objeto
* @return valor do cout
*/
ostream& operator<<(ostream &e, ContaCorrente const c){
	e << "Agencia: "<< c.agencia
	  << "| Numero: " << c.numero
	  << "| saldo: " <<  c.saldo
	  << "| status: " <<  c.status
	  << "| limite: " <<  c.limite
	  << endl;
	return e;
}

/**
* @brief Efetua a sobrecarga do operador ==
* @param[in] Constante para guardar o objeto a ser comparado
* @return booleano
*/
bool ContaCorrente::operator ==(ContaCorrente& conta_comparada){
	if((this->agencia.compare(conta_comparada.getAgencia()) == 0) &&
			(this->numero.compare(conta_comparada.getNumero()) == 0))
		return true;
	else
		return false;
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
		Movimentacao movimentacao_debito("Saque/limite", valor, "debito");
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
* @brief Método para consulta do saque
* @return
*/
double ContaCorrente::consultar_saldo(){
	return this->saldo;
}

/**
* @brief Método para consulta do extrato
* @return
*/
void ContaCorrente::consultar_extrato(){
	int quantidade_movimentacoes = this->movimentacao.size();
	if(quantidade_movimentacoes > 0){
		for (int i = 0;i != quantidade_movimentacoes; ++i)
		{
			cout << this->movimentacao[i] << endl;
		}
	}else{
		cout << "Não existem movimentações para esta conta" << endl;
	}

}

/**
* @brief Método para realizar transferências
* @param[in] conta a tranferir
* @param[in] variável valor
* @return agencia
*/
void ContaCorrente::tranferencia(ContaCorrente& conta_tranferir, double valor){
	cout << "Quantia tranferida da conta " << this->numero << " para a conta " << conta_tranferir.getNumero() << endl;
	cout << "Valor transferido: " <<  valor << endl;
	if(valor <= this->saldo){
		this->saldo = this->saldo - valor;
		Movimentacao movimentacao_debito("Transferência", valor, "debito");
		this->movimentacao.push_back(movimentacao_debito);

		double saldo_conta_tranferir = conta_tranferir.getSaldo() + valor;
		conta_tranferir.setSaldo(saldo_conta_tranferir);
		conta_tranferir.add_movimentacao("Transferência", valor, "credito");

	//fazer a verificação do cheque especial
	}else{
		cout << "Saldo Insuficiente para tranferencia" << endl;
	}

}

/**
* @brief Método para adicionar movimentação na tranferência
* @return
*/
void ContaCorrente::add_movimentacao(std::string descricao, double valor, std::string tipo){
	Movimentacao movimentacao(descricao, valor, tipo);
	this->movimentacao.push_back(movimentacao);
}


/**
* @brief Destrutor da classe
*/
ContaCorrente::~ContaCorrente() {
}
