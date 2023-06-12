symadd = {}
litadd = {}

with open("symtab.txt", "r") as sym:
    for s in sym:
        word = s.split("  ")
        symadd[int(word[0])] = word[2]
    print(symadd)

with open("littab.txt", "r") as lit:
    for s in lit:
        word = s.split("  ")
        litadd[int(word[0])] = word[2]
    print(litadd)

with open("intermediate.txt", "r") as intm, open("Pass2.txt", "w") as pass2:
    for string in intm:
        word = string.split(" ")
        if(len(word)==2):
            address = word[0]
            s = str(word[1])
            
            for_s = 0
            #(IS,01)(RG,01)(L,01)
            if s[1:6].lower() == "is,00":
                pass2.write(address+ " ")
                pass2.write("+ 00 00 000\n")


            elif s[1:3].lower() == "is":
                pass2.write(address+ " ")
                pass2.write("+ " + s[4:6] + " ")
                if s[8:10].lower() == "rg":
                    pass2.write(s[11:13] + " ")
                    for_s = 7
                    if s[8+for_s].lower() == "s":
                        pass2.write(symadd[int(s[17:19])])
                    if s[8+for_s].lower() == "l":
                        pass2.write(litadd[int(s[17:19])])
                        for_s = 0
                if s[8].lower() == "s":
                        pass2.write("00"+" ")
                        pass2.write(symadd[int(s[10:12])])
            elif s[1:6].lower() == "dl,01":
                pass2.write(address + "+ 00 00 " + s[-4:-2] + "\n")
            else:
                pass2.write(address+ " + " + " "+"\n")
