import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from pandas import DataFrame,Series

df=pd.read_csv('BlackFriday.csv')
print('----Headers----')
print(df.head())
print('----Description----')
df.describe()
df.info()
print("After setting the empty cells of City_category column with 'A':")
df['City_Category']=df['City_Category'].fillna('A')
print(df['City_Category'])
print("After changing the values attribute 'City_Category' to have 'A' as 'Metro Cities', 'B' as 'Small Towns' ,'C' as 'Villages'")
df['City_Category']=df['City_Category'].map({'A':'Metro Cities','B':'Small Cities','C':'Villages'})
print(df['City_Category'])
ax=sns.countplot(x='City_Category',hue='Gender',data=df,palette='Set3')
ax.set(xlabel='City categories',ylabel='Total',title='Categorical distribution based on city')
plt.show()