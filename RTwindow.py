import os
import requests
from bs4 import BeautifulSoup
import time
import subprocess

ID = input("your BOJ handle : ")
VS = subprocess.Popen("C:/Users/alsrn/source/repos/BOJ/BOJ.sln", shell = True, stdout = subprocess.PIPE)

newCodePath = "C:/Users/alsrn/source/algorithm/Problems/"
mainURL = "https://www.acmicpc.net/"
URL = "https://www.acmicpc.net/status?problem_id=&user_id=" + ID + "&language_id=-1&result_id=4"

PL = ("C++", "C", "Java", "Python")
fileEx = (".cpp", ".c", ".java", ".py")
codePath = ("C:\\Users\\alsrn\\source\\repos\\BOJ\\BOJ\\", "C:\\Users\\alsrn\\source\\repos\\BOJ\\BOJ\\", "C:\\Users\\alsrn\\source\\repos\\BOJ\\BOJ\\", "C:\\Users\\alsrn\\source\\repos\\pyBOJ\\pyBOJ\\")

add = "git add "
commit = "git commit -m "
pull = "git pull"
push = "git push"

os.chdir(newCodePath)

fname = ""
lastIdx = 0

while True :
    com = input()
    if com == "exit" :
        VS.kill()
        exit()
    elif com == "p" :
        os.system(pull)
        os.system(push)
        print("\n");
        continue
    elif com == "d" :
        if fname == "" :
            print("new file is nothing")
            continue
        while True :
            com = input(fname + " is  deleted. Y/N ")
            if com == "Y" or com == "y" :
                os.system("del " + codePath[lastIdx] + fname)
                print("removed the " + fname + " in BOJ\n")
                fname = ""
                break
            elif com == "N" or com == "n" :
                break
        continue
    elif com != "c" :
        continue

    bshtml = BeautifulSoup(requests.get(URL).text, "html.parser")

    solList = bshtml.tbody.findAll("tr")
    for solNum in solList :
        if solNum.select(".result-ac") :
            acTime = int(solNum.findAll("td")[8].find("a").get("data-timestamp"))
            print(time.asctime(time.localtime(acTime)))
            if int(time.time()) - acTime > 180 :
                print("Last ac-submit is over the 3 minutes")

                while True :
                    com = input("Is it OK? Y/N ")
                    if com == "N" or com == "n" or com == "Y" or com == "y":
                        break
                    elif com != "Y" or com != "y" :
                        continue
                if com == "N" or com == "n" :
                    break

            probNum = solNum.findAll("td")[2].text
            probTitle = str(solNum.findAll("td")[2].find("a").get("title"))
            pl = solNum.findAll("td")[6].text

            fname = "boj" + probNum
            for idx in range(len(PL)) :
                if pl.find(PL[idx]) == 0 :
                    fname = fname + fileEx[idx]
                    try :
                        codeFile = open(codePath[idx] + fname, "r")
                        lastIdx = idx
                    except :
                        print("File doesn't exist")
                        fname = ""

                    break

            if fname == "" :
                break

            code = codeFile.read()
            newFile = open(newCodePath + fname, "w")

            comment = "//"
            if lastIdx == 3 :
                comment = "#"

            newFile.write("//Problem Number : " + probNum + "\n")
            newFile.write("//Problem Title : " + probTitle + "\n")
            newFile.write("//Problem Link : " + mainURL + "problem/" + probNum + "\n\n")
            newFile.write(code)

            codeFile.close()
            newFile.close()

            os.system(add + fname)
            os.system(commit + "Solutions")

            print("\nComplete to commit " + fname + "!!!\n")
            break
