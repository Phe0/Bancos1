import os

class Db:

    def search(id):
        file = open('Arquivos/Motoristas.txt', 'r')
        lines = file.readlines()
        for line in lines:
            if id in line:
                print(line)
                print(id)
                file.close()
                return True
        file.close()
        return False

    def register(owner, vehicle):
        file = open('Arquivos/Motoristas.txt', 'r')
        lines = file.readlines()

        content = []

        if len(lines) > 1:
            write = 1
            for line in lines:
                data = line.split(' | ')

                if int(owner.cpf) < int(data[0]) and write == 1:
                    write -= 1
                    content.append(owner.cpf + ' | ' + owner.name + ' | ' + vehicle.lisencePlate + ' | ' + vehicle.model + ' | ' + vehicle.color + '\n')
                    content.append(line)
                else:
                    content.append(line) 

            if write == 1:
                content.append(owner.cpf + ' | ' + owner.name + ' | ' + vehicle.lisencePlate + ' | ' + vehicle.model + ' | ' + vehicle.color + '\n')
        elif len(lines) == 1:
            data = lines[0].split(' | ')
            if int(owner.cpf) > int(data[0]):
                content.append(lines[0])
                content.append(owner.cpf + ' | ' + owner.name + ' | ' + vehicle.lisencePlate + ' | ' + vehicle.model + ' | ' + vehicle.color + '\n')
            else:
                content.append(owner.cpf + ' | ' + owner.name + ' | ' + vehicle.lisencePlate + ' | ' + vehicle.model + ' | ' + vehicle.color + '\n')
                content.append(lines[0])
        else:
            content.append(owner.cpf + ' | ' + owner.name + ' | ' + vehicle.lisencePlate + ' | ' + vehicle.model + ' | ' + vehicle.color + '\n')

        file.close()
        os.remove('Arquivos/Motoristas.txt')
        newFile = open('Arquivos/Motoristas.txt', 'w+')
        newFile.writelines(content)
        newFile.close()