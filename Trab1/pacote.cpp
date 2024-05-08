// As funções abaixo, com exceção da empacotar, servem para desempacotar e retornar o valor 
// correspondente, ambas recebem o valor empacotado.

unsigned int passo(unsigned int emp) {
	// Criei uma variável inteira sem sinal para fazer a operação,
	// ela recebe o valor e joga os 8 bits, 24 casas a frente e retorna.
	unsigned int desempacotado;
	desempacotado = emp >> 24;

	return desempacotado;
}

unsigned int cor(unsigned int emp) {
	// Dessa vez como eu queria pegar os 8 subsequentes do passo e se fizesse da mesma forma 
	// apenas jogando 16 bits para frente viria também o valor do passo, então salvei em 
	// uma variável do tipo char que só comporta 8 bits. 
	unsigned char desempacotado;
	desempacotado = emp >> 16;

	return desempacotado;
}
// A partir daqui a logica utilizada para as funções, posição, velocidade e pista é a mesma.
// 1º - Criei uma variável mascara para pegar os bits ate chegar nos bits que a função precisava.
// 2º - Criei uma variável para fazer a operação e retornar o valor.
// 3º - Para operação fiz um AND entre a mascara e um número que seus bits "ligados" fossem apenas 
// os mesmos que seria preciso obter. 
unsigned int posição(unsigned int emp) {
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

// A função a seguir serve para empacotar os 5 valores do jogo em um inteiro de 32 bits.
unsigned int empacotar(unsigned int pass, unsigned int color, unsigned int position, unsigned int speed, unsigned int lane) {
	unsigned int total;
	
	// Cada valor recebido vai ser puxado a quantidade de bits correspondente até formar 32 bits.
	pass = pass << 24;
	color = color << 16;
	position = position << 9;
	speed = speed << 5;
	lane = lane << 4;
	// Após todos serem colocodos nas suas posições, somei todos valores.
	total = pass + color + position + speed + lane;

	return total;
}