from flask import Flask,redirect,render_template,request,url_for,session

app=Flask(__name__)
app.secret_key='secret'

@app.route('/',methods=['POST','GET'])
def index():
    if request.method=='GET':
        return render_template('index.html',msg="",amt="")
    if request.method=='POST':
        if request.form['milk']=='' or request.form['eggs']=='' or request.form['bread']=='':
            msg='All fields are required'
            amt=''
        elif not(request.form['milk'].isdigit()) or not(request.form['eggs'].isdigit()) or not(request.form['bread'].isdigit()):
            msg='Invalid entry'
            amt=''
        else:
            amt='Amount to be paid: Rs. '+str(int(request.form['milk'])*35+int(request.form['eggs'])*2+int(request.form['bread'])*25)
            msg=''
        return render_template('index.html',msg=msg,amt=amt)

if __name__=='__main__':
    app.run(debug=True)