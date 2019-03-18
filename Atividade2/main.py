from owner import Owner
from vehicle import Vehicle
from db import Db
import os

plate = input('Insira a placa do carro: ')
model = input('Qual o modelo do carro? ')
color = input('Qual a cor do carro? ')

vehicle = Vehicle(plate, model, color)

if vehicle.valid != False:
    name = input('Insira o nome completo do proprietário: ')
    cpf = input('Insira o CPF: ')
    birth = input('Insira a data de nascimento: ')

    owner = Owner(name, birth, cpf)
    Db.register(owner, vehicle)