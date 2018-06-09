nome .equ 10 				@define uma constante nome com valor decimal 10
.org 0x1000					@o programa inicia (é montado) no endereço 0x1000
inicio:
	set	r5,0x7000		@carrega o reg5 com o valor 7000
	set 	r6,r5			@carrega reg6 com o endereço de r5
	add 	r5,r6			@soma r5 com r6 e salva o resultado em r5
	.org 	0x2000			@mudamos o endereço de montagem novamente para 0x2000
	variavel: 	.skip	4	@reserva para a "variavel" 4 bytes de memoria a partir do endereço inicial dela, sem iniciar a 							@variavel com valores definidos
	variavel2: 	.byte 	0, MAXVAL-1 	@ inicia a "variavel2" como uma lista de valores (pode iniciar com um só valor tambem ou 							@caracter usando aspas simples '')
	palavra:	.word	4000			@inicia a "palavra" com uma string (pode guardar valores numericos e de outras variaveis 							@tambem)
				.org	0x400			@pula para o endereço de memoria 0x400
	mov		rd, rf			@copia o valor do reg fonte "rf" para o reg de destino "rd"
	ld		r9, cont 		@carrega o conteudo direto do endereço de memoria "cont" em "r9"
	ld		r9,r8			@carrega o conteudo indiretamente acessando-o atraves do endereço salvo em outro registrador
	st 		var, r7			@os dados que estao em "r7" é gravado no endereço em que "var" esta na memoria
	stb		var1, r5 		@faz o mesmo que o codigo acima mas é usado com "char" ja que esse tipo só usa 1 byte 
	
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
	
