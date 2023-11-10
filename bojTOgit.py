import os
import requests
from bs4 import BeautifulSoup
from selenium import webdriver
import time

#깃 저장소에 올릴 폴더 위치
path = "/Users/ming._.nine9/Programming/git/algorithm/Problems/"
#크롬 드라이버가 있는 위치
driverPath = "/Users/ming._.nine9/PycharmProjects/chromedriver"

#백준 사이트 정보
URL = 'https://www.acmicpc.net/'
mysource1 = "status?from_mine=1&problem_id="
mysource2 = "&user_id="

#깃 명령어
add = "git add "
commit = "git commit -m "
push = "git push"

PL = ("C++", "C", "Java", "Python")
fileEx = (".cpp", ".c", ".java", ".py")

print("Input Your BOJ handle")
ID = input()

os.chdir(path)
wd = webdriver.Chrome(driverPath)
wd.implicitly_wait(3)

#크롬창으로 백준 로그인
wd.get(URL + "login?next=%2F")
wd.find_element_by_name("login_user_id").send_keys(ID)
time.sleep(0.5)
wd.find_element_by_name("login_password").send_keys("")
time.sleep(5)

#로그인 확인
while str(wd.current_url) != URL :
    time.sleep(3)
    continue;

bshtml = BeautifulSoup(requests.get(URL + 'user/' + ID).text, "html.parser")

probNum = bshtml.select("span.problem_number")      #문제 목록을 저장하고 있는 리스트
probTitle = bshtml.select("span.problem_title")


for i in range(len(probNum)) :
    MySourceURL = URL + mysource1 + probNum[i].text + mysource2 + ID

    bshtml = BeautifulSoup(requests.get(MySourceURL).text, "html.parser")

    solList = bshtml.tbody.findAll("tr")            #현재 문제에 대한 풀이 목록을 저장하고 있는 리스트`

    for solNum in solList :
        if solNum.select(".result-ac") :            #ac를 받은 제일 처음 풀이 하나만 파일로 생성 후 깃에 추가 
            sn = solNum.td.text
            pl = solNum.findAll("td")[6].text

            fname = "boj" + probNum[i].text
            for idx in range(len(PL)) :             #어떤 언어로 풀었는지 검사
                if pl.find(PL) == 0 :
                    fname = fname + fileEx[idx]
                    break

            sourceURL = URL + "source/" + sn
            wd.get(sourceURL)
            time.sleep(0.5)

            bshtml2 = BeautifulSoup(wd.page_source, "html.parser")
            MySource = bshtml2.select("textarea")

            tmpFile = open(path + fname, "w")       #임시 파일 하나를 생성하여

            tmpFile.write("//Problem Number : " + probNum[i].text + "\n")                   #문제 번호, 제목, 링크를 처음에 삽입한 뒤 
            tmpFile.write("//Problem Title : " + probTitle[i].text + "\n")
            tmpFile.write("//Problem Link : " + URL + "problem/" + probNum[i].text + "\n\n")
            tmpFile.write(MySource[0].contents[0])                                          #코드를 입력

            tmpFile.close()

            os.system(add + fname)                  #깃에 추가 
            os.system("rm " + fname)                #임시 파일 삭제
            break

os.system(commit + "Solutions")                     #깃에 커밋
os.system(push)                                     #깃에 푸쉬

print("Finish!!!")
