import pandas as pd
import seaborn as sns
from pandas import DataFrame,Series
import matplotlib.pyplot as plt

titanic_df=pd.read_csv('train.csv')
print('----Headers----')
print(titanic_df.head())
print('----Description----')
titanic_df.describe()
titanic_df.info()
print('After dropping columns-Ticket,Fare,Cabin')
titanic_df=titanic_df.drop(['Ticket','Fare','Cabin'],axis=1)
print(titanic_df.head())
print('After setting empty values of Age column with "NA"')
titanic_df['Age']=titanic_df['Age'].fillna('NA')
print(titanic_df['Age'])
titanic_df['Survived']=titanic_df['Survived'].map({0:'Died',1:'Survived'})
ax=sns.countplot(x='Pclass',hue='Survived',data=titanic_df,palette='Set1')
ax.set(xlabel='Passenger Class',ylabel='Total',title='Passenger status(died/survived) against passenger class')
plt.show()