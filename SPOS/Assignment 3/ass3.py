argdic = {}
with open("input.txt", "r") as f:
    mnt = open("mnt.txt", "w")
    mdt = open("mdt.txt", "w")
    aal = open("aal.txt", "w")
    ir = open("intermediate.txt", "w")
    mntind = 1
    mdtind = 1
    flag = 0
    for line in f:
        parts = line.strip().split()
        if parts[0].upper() == "MACRO":
            flag =1;
            line = next(f)
            mdt.write(f"{mdtind}\t{line}")
            parts = line.strip().split()
            Macro_name = parts[0]
            ARG = parts[1].split()
            place = 1;
            for i in range(0, len(ARG)):
                ARG[i] = ARG[i].replace("&", "")
                tp = ARG[i].split(",")
                for i in range(0, len(tp)):
                    aal.write(f"{tp[i]}\t{place}\n")
                    argdic[tp[i]] = place
                    place +=1
            # print("LIST of Arguments")
            # print(ARG)
            # print(argdic[str(ARG[i])])
            #mnt.write(f"{mntind}\t{Macro_name}\n")s
            mnt.write(f"{mntind}\t{Macro_name}\t{mdtind}\n")
            mntind +=1
        elif parts[0].upper() == "MEND":
            mdt.write(f"{mdtind}\t{line}")
            flag = 0
            argdic.clear()
        elif flag == 1:
            line = line.strip().split()
            mdt.write(f"{mdtind}\t")
            for i in range(0, len(line)):
                if "&" not in line[i]:
                    mdt.write(f"{line[i]}\t")
                else:
                    line[i] = line[i].replace("&", "")
                    mdt.write("#")
                    mdt.write(f"{argdic[line[i]]}\n")
        else:
            ir.write(f"{line}")
        mdtind +=1
    mdt.close()
    mnt.close()
    ir.close()
    aal.close()
print("PASS-I is DONE ;)")