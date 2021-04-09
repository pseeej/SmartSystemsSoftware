payed = int(input("구매금액을 입력하세요 (만원) : "))

if payed<10 :
    print("상품권 5천원이 지급됩니다.")
elif payed >=10 :
    print("상품권 1만원이 지급됩니다.")
elif payed >=30 :
    print("상품권 5만원이 지급됩니다.")
