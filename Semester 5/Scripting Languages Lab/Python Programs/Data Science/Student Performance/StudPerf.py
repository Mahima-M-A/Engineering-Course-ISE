import pandas as pd
from pandas import Series, DataFrame

# numpy, matplotlib, seaborn
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

#To display header rows and description of the loaded dataset
stud_df=pd.read_csv('StudentsPerformance.csv')
print("======Data Headers=======")
print(stud_df.head())
print("=====Data Description=====")
stud_df.info()
stud_df.describe()

#To remove unnecessary features such as 'lunch' from the data frame 
stud_df = stud_df.drop(['lunch'], axis=1)
print("=====Check if columns were really dropped=====")
print(stud_df.head())

#To replace empty column values in ‘parental level of education’ with a default value
stud_df['parental level of education'] = stud_df['parental level of education'].fillna("Y")
print(stud_df['parental level of education'])

#To convert the attribute ‘race/ethnicity’ to have ‘groupA’ to be ‘Asian Students’ etc
findv=['group A','group B','group C','group D','group E']
repv=['Asian Students','African Students','Afro-Asian Students','American Students','European Students']
stud_df['race/ethnicity']=stud_df['race/ethnicity'].replace(findv,repv)
print(stud_df['race/ethnicity'])

#Visualizations

#Tally of the Number of Male & Female students who took up the ‘test preparation course’ and those who did not.
ax = sns.countplot(x = 'test preparation course', hue = 'gender', palette = 'Set3',data = stud_df)
ax.set(title="Course completion based on gender",xlabel="course", ylabel="total")
plt.show()

#Total Number of Male & Female Students belonging to each student group
ax = sns.countplot(x = 'race/ethnicity', hue = 'gender', palette = 'Set2',data = stud_df)
ax.set(title="Based on Categories they belong to", xlabel="categories",ylabel="total")
plt.show()

"""
No of students who ‘failed’(less than 40), ‘second class’(between 40 & 50).
‘first class’(between 60 & 75) and ‘distinction’(above 75)
"""
#in ‘Maths’,
interval = (0,40,50,60,75)
categories = ['Fail','II class','I class', 'Distinction']
stud_df['Marks_cats'] = pd.cut(stud_df.mathscore, interval, labels = categories) 
ax = sns.countplot(x = 'Marks_cats',  data = stud_df, hue = 'gender', palette = 'Set1')
ax.set(xlabel='Marks Categorical', ylabel='Total',title="Math Marks Categorical Distribution")
plt.show()

#in ‘Writing’.
interval = (0,40,50,60,75)
categories = ['Fail','II class','I class', 'Distinction']
stud_df['Marks_cats'] = pd.cut(stud_df.writingscore, interval, labels = categories) 
ax = sns.countplot(x = 'Marks_cats',  data = stud_df, hue = 'gender', palette = 'Set2')
ax.set(xlabel='Marks Categorical', ylabel='Total',title="Writing Marks Categorical Distribution")
plt.show()

#in ‘Reading’
interval = (0,40,50,60,75)
categories = ['Fail','II class','I class', 'Distinction']
stud_df['Marks_cats'] = pd.cut(stud_df.readingscore, interval, labels = categories) 
ax = sns.countplot(x = 'Marks_cats',  data = stud_df, hue = 'gender', palette = 'Set3')
ax.set(xlabel='Marks Categorical', ylabel='Total',title="Reading Marks Categorical Distribution")
plt.show()

#To find the average Maths, Reading and Writing Score of each Group (Ethnicity)
print(stud_df[['race/ethnicity','mathscore','writingscore','readingscore']].groupby(['race/ethnicity'],as_index=True).mean())
