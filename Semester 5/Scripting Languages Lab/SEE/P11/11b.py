import pandas as pd
import seaborn as sns
from pandas import DataFrame,Series
import matplotlib.pyplot as plt
stud_df=pd.read_csv('StudentsPerformance.csv')
print('----Headers----')
print(stud_df.head())
print('----Description----')
stud_df.describe()
stud_df.info()
print('After dropping columns-Lunch and Test Preparation Course')
df=stud_df.drop(['lunch','test preparation course'],axis=1)
print(df.head())
print('After replacing null values in parental level of education with a default value')
stud_df['parental level of education']=stud_df['parental level of education'].fillna('None')
print(stud_df['parental level of education'])
ax=sns.countplot(x='gender',hue='test preparation course',data=stud_df,palette='Set1')
ax.set(xlabel='Test preparation course',ylabel='total',title='Tally of those who did and did not take up the course')
plt.show()