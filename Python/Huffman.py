import math

encoded_dict = dict()
decoding_dict = dict()
one_more_mass = []
def encodeHuffman(fileIn, fileOut):
    if open(fileIn).read():
        letters_dict = {}
        binary_dict = {}
        first_len = 0
        second_len = 0
        for row in open(fileIn):
            for element in row:
                if element in letters_dict.keys():
                    letters_dict[element] += 1
                else:
                    letters_dict[element] = 1
                first_len += 1
        values_mass = []
        for a, b in letters_dict.items():
            values_mass.append([b, a])
        values_mass.sort()
        while len(values_mass) >= 2:
            d = [values_mass[0][0] + values_mass[1][0], [values_mass[0][1], values_mass[1][1]]]
            if values_mass[-1][0] < d[0]:
                values_mass.append(d)
            else:
                for num in range(2, len(values_mass)):
                    if values_mass[num][0] >= d[0]:
                        break
                values_mass.insert(num, d)
            values_mass.pop(0)
            values_mass.pop(0)
        values_mass = values_mass[0][1]
        one_more_mass = []
        print(values_mass)
        def hydra(statement, element):
            if type(element) == str:
                one_more_mass.append((element, statement))
            else:
                hydra(statement + "0", element[0])
                hydra(statement + "1", element[1])
        hydra("", values_mass)
        binary_dict = dict(one_more_mass)
        simple_file = open(fileOut, "w")
        print(binary_dict)
        for row in open(fileIn):
            for element in row:
                simple_file.write(binary_dict[element])
                second_len += len(binary_dict[element])
        letters_dict = {}
        for a, b in binary_dict.items():
            letters_dict[b] = a
        simple_file.close()
        print(math.log(2, second_len) / math.log(2, first_len))
        return letters_dict
    else:
        print(-1)

def decodeHuffman(fileIn, fileOut):
    simple_file = open(fileOut, "w")
    var = ""
    for row in open(fileIn):
        for element in row:
            var += element
            if var in decoding_dict.keys():
                simple_file.write(decoding_dict[var])
                var = ""
decoding_dict = encodeHuffman("text1.txt", "file3.txt")
decodeHuffman("file3.txt", "oneFile.txt")
