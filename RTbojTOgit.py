import os
import requests
from bs4 import BeautifulSoup
import time

ID = input("your BOJ handle : ")

logPath = "/Users/ming._.nine9/Library/ApplicationSupport/Google/Chrome/Default/Current Session"

newCodePath = "/Users/ming._.nine9/Programming/git/algorithm/Problems/"
mainURL = "https://www.acmicpc.net/"
URL = "https://www.acmicpc.net/status?problem_id=&user_id=" + ID + "&language_id=-1&result_id=4"

PL = ("C++", "C", "Java", "Python")
fileEx = (".cpp", ".c", ".java", ".py")
codePath = ("/Users/ming._.nine9/CLionProjects/BOJ/main.cpp", "/Users/ming._.nine9/CLionProjects/BOJ/main.cpp", "/Users/ming._.nine9/IdeaProjects/BOJ/src/main.java", "/Users/ming._.nine9/PycharmProjects/BOJ/main.py")

add = "git add "
commit = "git commit -m "
pull = "git pull"
push = "git push"

os.popen("/Applications/CLion.app/Contents/MacOS/clion")
os.chdir(newCodePath)

fname = ""

while True :
    com = input()
    if com == "exit" :
        exit()
    elif com == "p" :
        os.system(pull)
        os.system(push)
        continue
    elif com == "d" :
        if fname == "" :
            print("new file is nothing")
            continue
        while True :
            com = input(fname + " is  deleted. Y/N ")
            if com == "Y" or com == "y" :
                os.system("rm " + fname)
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
            probTitle = str(solNum.findAll("td")[2].find("a").get("data-original-title"))
            pl = solNum.findAll("td")[6].text

            fname = "boj" + probNum
            for idx in range(len(PL)) :
                if pl.find(PL[idx]) == 0 :
                    fname = fname + fileEx[idx]
                    codeFile = open(codePath[idx], "r")
                    break


            code = codeFile.read()
            newFile = open(newCodePath + fname, "w")

            newFile.write("//Problem Number : " + probNum + "\n")
            newFile.write("//Problem Title : " + probTitle + "\n")
            newFile.write("//Problem Link : " + mainURL + "problem/" + probNum + "\n\n")
            newFile.write(code)

            codeFile.close()
            newFile.close()

            print(fname)
            os.system(add + fname)
            os.system(commit + "Solutions")
            break