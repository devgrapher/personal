import xlrd3 as xlrd
import sys

src = "거래내역_간략조회 리스트.xls"
dst = "output.txt"
if len(sys.argv) is 3:
    src = sys.argv[1]
    dst = sys.argv[2]

def ExtractContent(content):
    return content.replace("체크카드/", "")
    

book = xlrd.open_workbook(src)
sheet = book.sheet_by_index(0)

totalInterest = 0
output = []
for r in range(sheet.nrows-1, 3, -1):
    interest = sheet.cell(r,4).value # 이자
    if interest:
        totalInterest += int(interest)
        continue
    else:    
        date = sheet.cell(r,0).value
        content = ExtractContent(sheet.cell(r,1).value)
        amount = int(sheet.cell(r,5).value)

        deal = date + " " + content + " " + str(amount) + " 동양-"
        output += [deal,]

interestDeal = date + " 이자정산 " + str(totalInterest) + " 동양+"
output += [interestDeal,]

with open(dst, 'w') as out:
    out.writelines("\n".join(output))
    
        

