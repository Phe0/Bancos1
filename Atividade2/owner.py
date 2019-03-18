import vehicle
import os
from db import Db

class Owner:

    def __init__(self, name, birth, cpf):

            self.name = name 
            self.birth = birth
            self.cpf = cpf