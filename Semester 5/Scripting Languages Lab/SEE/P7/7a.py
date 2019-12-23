import pandas as pd
import seaborn as sns
from pandas import DataFrame,Series
import matplotlib.pyplot as plt

iris_df=pd.read_csv('iris.csv')
print('----Headers----')
print(iris_df.head())
print('----Description----')
iris_df.describe()
iris_df.info()
print('After dropping the column- Petal length')
iris_df=iris_df.drop(['Petal.Length'],axis=1)
print(iris_df.head())
print(iris_df[['Species','Petal.Width']].groupby(['Species'],as_index=True).mean())
ax=sns.countplot(x='Sepal.Width',hue='Species',data=iris_df,palette='Set2')
ax.set(xlabel='Sepal Width',ylabel='Total',title='Categorical Distribution based on Sepal Width')
plt.show()