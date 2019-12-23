from flask import Flask,redirect,render_template,request,url_for
import re
import time
app=Flask(__name__)

@app.route('/',methods=['POST','GET'])
def index():
    if request.method=='GET':
        return render_template('index.html',msg='')
    if request.method=='POST':
        if request.form['usn']=='' or request.form['dob']=='' or request.form['m1']=='' or request.form['m2']=='' or request.form['m3']=='':
            msg='All the fields are required'
            return render_template('index.html',msg=msg)
        try:
            time.strptime(request.form['dob'],'%d/%m/%Y')
        except ValueError:
            msg='Invalid date of birth'
            return render_template('index.html',msg=msg)
        usn_pattern='^1[A-Z][A-Z][0-9][0-9][A-Z][A-Z][0-9][0-9][0-9]$'
        if not re.match(usn_pattern,request.form['usn']):
            msg='Invalid USN'
            return render_template('index.html',msg=msg)
        
        avg=(int(request.form['m1'])+int(request.form['m2'])+int(request.form['m3']))/300
        total='Average Score: '+str(avg)
        return render_template('index.html',total=total)

if __name__=='__main__':
    app.run(debug=True)