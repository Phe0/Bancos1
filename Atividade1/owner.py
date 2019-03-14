import vehicle

class Owner:
    vehicles = []

    def __init__(self, name, birth, id, cpd):
        self.name = name 
        self.birth = birth
        self.id = id
        self.cpd = cpd 

    def addVehicle(self, vehicle):
        self.vehicles.append(vehicle)

    def createFile(self):
        file = open(self.name + '.txt', 'w+')
        file.write('Nome completo: ' + self.name + "\n" + 'Identidade: ' + self.id + '\n' + 'CPD: ' +  self.cpd + '\n' + 'Idade: ' + self.birth + '\n\n')
        
        for vehicle in self.vehicles:
            file.write('Modelo do carro: ' + vehicle.model + '\n' + 'Placa do carro: ' + vehicle.lisencePlate + '\n' + 'Cor: ' + vehicle.color + '\n\n')

        file.close()