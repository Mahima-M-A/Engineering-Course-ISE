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
