// As fun��es abaixo, com exce��o da empacotar, servem para desempacotar e retornar o valor 
// correspondente, ambas recebem o valor empacotado.

unsigned int passo(unsigned int emp) {
	// Criei uma vari�vel inteira sem sinal para fazer a opera��o,
	// ela recebe o valor e joga os 8 bits, 24 casas a frente e retorna.
	unsigned int desempacotado;
	desempacotado = emp >> 24;

	return desempacotado;
}

unsigned int cor(unsigned int emp) {
	// Dessa vez como eu queria pegar os 8 subsequentes do passo e se fizesse da mesma forma 
	// apenas jogando 16 bits para frente viria tamb�m o valor do passo, ent�o salvei em 
	// uma vari�vel do tipo char que s� comporta 8 bits. 
	unsigned char desempacotado;
	desempacotado = emp >> 16;

	return desempacotado;
}
// A partir daqui a logica utilizada para as fun��es, posi��o, velocidade e pista � a mesma.
// 1� - Criei uma vari�vel mascara para pegar os bits ate chegar nos bits que a fun��o precisava.
// 2� - Criei uma vari�vel para fazer a opera��o e retornar o valor.
// 3� - Para opera��o fiz um AND entre a mascara e um n�mero que seus bits "ligados" fossem apenas 
// os mesmos que seria preciso obter. 
unsigned int posi��o(unsigned int emp) {
	unsigned int desempacotado, mascara;
	mascara = emp >> 9;
	desempacotado = mascara & 127;

	return desempacotado;
}

unsigned int velocidade(unsigned int emp) {
	unsigned int desempacotado, mascara;
	mascara = emp >> 5;
	desempacotado = mascara & 15;

	return desempacotado;
}

unsigned int pista(unsigned int emp) {
	unsigned int desempacotado, mascara;
	mascara = emp >> 4;
	desempacotado = mascara & 1;

	return desempacotado;
}

// A fun��o a seguir serve para empacotar os 5 valores do jogo em um inteiro de 32 bits.
unsigned int empacotar(unsigned int pass, unsigned int color, unsigned int position, unsigned int speed, unsigned int lane) {
	unsigned int total;
	
	// Cada valor recebido vai ser puxado a quantidade de bits correspondente at� formar 32 bits.
	pass = pass << 24;
	color = color << 16;
	position = position << 9;
	speed = speed << 5;
	lane = lane << 4;
	// Ap�s todos serem colocodos nas suas posi��es, somei todos valores.
	total = pass + color + position + speed + lane;

	return total;
}