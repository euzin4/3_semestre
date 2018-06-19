	.global _start      @ ligador necessita deste rótulo

_start:
    /* int write(int fd, const void *buf, size_t count) */
	mov     r0, #1      @ fd -> stdout
	ldr     r1, =msg    @ buf -> msg
	ldr     r2, =len    @ count -> len(msg)
	mov     r7, #4      @ write é syscall #4
	svc     0x055       @ executa syscall

msg:
	.ascii   "\nMENU\n1-adicionar elemento\n2-remover elemento\n3-listar elementos\n4-sair\n"
len = . - msg
