import vehicle
import os
from os import path


class Owner:

    def __init__(self, name, birth, id, cpd):
        self.name = name
        self.birth = birth
        self.id = id
        self.cpd = cpd
        print(self.id)

        if not path.exists('Arquivos'):
            os.mkdir('Arquivos')
        os.mkdir('Arquivos/' + self.id)
        os.mkdir('Arquivos/' + self.id + '/Vehicles')
        file = open('Arquivos/' + self.id + '/' + 'Description.txt', 'w+')
        file.write('Nome completo: ' + self.name + "\n" + 'Identidade: ' + self.id +
                   '\n' + 'CPD: ' + self.cpd + '\n' + 'Idade: ' + self.birth + '\n')
        file.close()

    def addVehicle(self, vehicle):
        file = open('Arquivos/' + self.id + '/Vehicles/' +
                    vehicle.lisencePlate + '.txt', 'w+')
        file.write('Modelo do carro: ' + vehicle.model + '\n' + 'Placa do carro: ' +
                   vehicle.lisencePlate + '\n' + 'Cor: ' + vehicle.color + '\n')
