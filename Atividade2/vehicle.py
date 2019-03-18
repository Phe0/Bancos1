from db import Db

class Vehicle:

    def __init__(self, lisencePlate, model, color):
        if Db.search(lisencePlate):
            print('Essa placa já existe no sistema')
            self.valid = False
        else:
            self.lisencePlate = lisencePlate
            self.model = model
            self.color = color
            self.valid = True