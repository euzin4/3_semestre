inicio:
	add r1,r2	@soma r1 e r2 e salva o resultado em r1
	add r1,2	@soma 2 ao valor que está em r1
	sub r3,r4	@subtrai r3=r3-r4
	sub r3,2	@subtrai r3=r3-2
	jmp fora	@pula para a linha em que está 'funçao' 'fora:' dentro do codigo jogando seu endereço para o registrador "ip"
