import os	

class Pilha:

	def __init__(self):
		self.pilha = []

	def adicionar(self, valor):
		self.pilha.append(valor)
		
	def soma(self):
		return self.pilha.append(self.pilha.pop() + self.pilha.pop())

	def sub(self):
		return self.pilha.append(self.pilha.pop() - self.pilha.pop())

	def mult(self):
		return self.pilha.append(self.pilha.pop() * self.pilha.pop())

	def div(self):
		return self.pilha.append(self.pilha.pop() / self.pilha.pop())

	def mostrar(self):
		return self.pilha

	def topo(self):
		return id(self.pilha[len(self.pilha)-1])

class Main():

	a = Pilha()
	
	while True:
		os.system('cls' if os.name == 'nt' else 'clear')
		print("\tMENU\n1-Inserir Valor\n2-Somar\n3-Subtrair\n4-Multiplicar\n5-Dividir\n0-Sair\n")
		
		if len(a.pilha) > 0: 
			stack = a.topo()
			print("\nPilha:",a.mostrar())
			print("Stack Pointer: %i" %stack)

		op = int(input(""))

		if op == 1:		#inserir
			if len(a.pilha) < 8:
				a.adicionar(int(input("Valor: ")))

		elif op == 2:		#somar
			if len(a.pilha) > 1:
				a.soma()
			
		elif op == 3:		#subtracao
			if len(a.pilha) > 1:
				a.sub()

		elif op == 4:		#multiplicacao
			if len(a.pilha) > 1:
				a.mult()

		elif op == 5:		#divisao
			if len(a.pilha) > 1:
				a.div()
			
		elif op == 0:		#sair
			print("Até logo!")
			break
