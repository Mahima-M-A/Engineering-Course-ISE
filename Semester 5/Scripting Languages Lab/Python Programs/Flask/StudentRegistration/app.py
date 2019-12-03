from flask import Flask,redirect,render_template,request,url_for
import time
import re

app=Flask(__name__)

@app.route('/',methods=['POST','GET'])
def index():
    if request.method=='GET':
        msg1="Enter Details"
        return render_template('index.html',msg1=msg1)
    if request.method=='POST':
        if(request.form['usn']=='' or request.form['dob']=='' or int(request.form['s1'])==0 or int(request.form['s2'])==0 or int(request.form['s3'])==0):
            msg1=''
            return render_template('index.html',msg1=msg1)
 
        try:
            time.strptime(request.form['dob'],'%d/%m/%Y')
        except ValueError:
            msg1='Invalid date of birth'
            return render_template('index.html',msg1=msg1)
        
        usn_pattern='^1[A-Z][A-Z][0-9][0-9][A-Z][A-Z][0-9][0-9][0-9]$'
        if not re.match(usn_pattern,request.form['usn']):
            msg1='Invalid USN'
            return render_template('index.html',msg1=msg1)

        avg=(int(request.form['s1'])+int(request.form['s2'])+int(request.form['s3']))/3
        msg2='RESULT:  '+str(avg)
        return render_template('index.html',msg2=msg2)

if __name__=='__main__':
    app.run(debug=True)
