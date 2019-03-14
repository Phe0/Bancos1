from owner import Owner
from vehicle import Vehicle

name = input('Insira seu nome completo: ')
identity = input('Insira seu numero da identidade: ')
cpd = input('Insira o numero da sua carteira de motorista: ')
birth = input('Insira a sua data de nascimento: ')
qtd = int(input('Quantos veiculos voce tem? '))

owner = Owner(name, birth, identity, cpd)

for i in range(0, qtd):
    print('Carro' + str(i+1))
    model = input('Qual o modelo do carro?')
    plate = input('Qual a placa do carro?')
    color = input('Qual a cor do carro?')

    vehicle = Vehicle(plate, model, color)

    owner.addVehicle(vehicle)

owner.createFile()