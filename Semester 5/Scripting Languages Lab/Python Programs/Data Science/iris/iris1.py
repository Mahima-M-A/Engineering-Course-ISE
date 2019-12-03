import pandas as pd
from pandas import Series,DataFrame
iris_df=pd.read_csv('iris.csv')
print('---DataFrame---')
print(iris_df)
print('---info---')
iris_df.info()
print('---Functions---')
print(iris_df[['Species','Sepal.Length']].groupby(['Species'],as_index=True).mean())
print("Max sepal length: ",iris_df['Sepal.Length'].max())

print(iris_df[['Species','Petal.Width']].groupby(['Species'],as_index=True).mean())

ax=sns.countplot(x="Sepal.Width", hue="Species",data=iris_df, palette="Set1")
ax.set(title="Categorization of flowers based on sepal width", xlabel="Sepal Width",ylabel="Total")
plt.show()

interval=(0,1,2,4)
categories=['<1','1-2','>2']
iris_df['flowers_cats']=pd.cut(iris_df['Petal.Width'],interval,labels=categories)
ax = sns.countplot(x = 'flowers_cats',  data = iris_df, hue = 'Species', palette = 'Set2')
ax.set(xlabel='Petal width', ylabel='Total',title="Categorization of flowers based on petal width")
plt.show()

subsetDataFrame = iris_df[iris_df['Species'].isin(['versicolor', 'virginica'])]
ax = sns.countplot(x = 'Sepal.Width', hue = 'Species', palette = 'Set3',data = subsetDataFrame)
ax.set(title="Flowers Categorical of 2 species based on Sepal Width",xlabel="Sepal Width", ylabel="total")
plt.show()
