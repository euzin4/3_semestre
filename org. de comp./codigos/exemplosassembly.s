inicio:
	add r1,r2	@soma r1 e r2 e salva o resultado em r1
	add r1,2	@soma 2 ao valor que está em r1
	sub r3,r4	@subtrai r3=r3-r4
	sub r3,2	@subtrai r3=r3-2
	jmp fora	@pula para a linha em que está 'funçao' 'fora:' dentro do codigo jogando seu endereço para o registrador "ip"
	jmp r10		@usando registradores
	.org 0x4000
	depois:
		mov r4,r3 	@se r10 tem o valor 0x4000 esta é a proxima função a ser executada
	@desvios condicionais cap5 slide 19
	
