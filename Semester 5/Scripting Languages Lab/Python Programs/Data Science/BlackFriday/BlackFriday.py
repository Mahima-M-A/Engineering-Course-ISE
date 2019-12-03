import pandas as pd
from pandas import Series,DataFrame
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

data=pd.read_csv('BlackFriday.csv')
print("--Data Headers--")
print(data.head())

print("--Data Description--")
data.info()
data.describe()

data=data.drop(['User_ID', 'Product_ID', 'Stay_In_Current_City_Years'],axis=1)
print("=====Check if columns were really dropped=====")
print(data.head())

data['City_Category']=data['City_Category'].fillna('None')
print(data['City_Category'])

findv=['A','B','C']
repv=['Metro Cities','Small Towns','Villages']
data['City_Category']=data['City_Category'].replace(findv,repv)
print(data['City_Category'])

data=data.rename(columns={'Product_Category_1':'Baseball Caps','Product_Category_2':'Wine Tumblers','Product_Category_3':'Pet Raincoats'})
print(data)

data['Marital_Status']=data['Marital_Status'].map({1:'Married',0:'Un-Married'})
print(data['Marital_Status'])

ax = sns.countplot(x = 'Gender', hue = 'Baseball Caps', palette = 'Set3',data = data)
ax.set(title="Product of category 1 bought based on gender",xlabel="Gender", ylabel="total")
plt.show()

ax = sns.countplot(x = 'Gender', hue = 'Wine Tumblers', palette = 'Set2',data = data)
ax.set(title="Product of category 2 bought based on gender",xlabel="Gender", ylabel="total")
plt.show()

ax = sns.countplot(x = 'City_Category', hue = 'Gender', palette = 'Set2',data = data)
ax.set(title="Based on Categories they belong to", xlabel="categories",ylabel="total")
plt.show()
