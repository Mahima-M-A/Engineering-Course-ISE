import pandas as pd
with pd.ExcelFile('file.xls') as xls:
    df1=pd.read_excel(xls,'Sheet1')
    df2=pd.read_excel(xls,'Sheet2')
print('----Result Sheet1----')
print(df1[0:5]['salary'])
print()
print('----Result Sheet2----')
print(df2[0:5]['zipcode'])
