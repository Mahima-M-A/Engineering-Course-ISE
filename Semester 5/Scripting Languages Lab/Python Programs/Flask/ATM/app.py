from flask import Flask,redirect,url_for,render_template,request,session

app=Flask(__name__)
app.secret_key='secret'

@app.route('/',methods=['POST','GET'])
def index():
    try:
        balance=session['balance']
        count=session['count']
    except KeyError:
        balance=session['balance']=8000
        count=session['count']=0

    if request.method=='GET':
        return render_template('index.html',balance=balance,msg="")

    if request.method=='POST':
        if request.form['amount']=='':
            msg='Amount required'
        elif int(request.form['amount'])<0:
            msg='Negative amount cannot be entered'
        elif session['count']==5:
            msg='5 transactions complete'
        else:
            if request.form['action']=='Withdraw':
                if int(request.form['amount'])>session['balance']:
                    msg='Not emough balance'
                elif int(request.form['amount'])>5000:
                    msg='Cannot withdraw more than 5000'
                else:
                    balance=balance-int(request.form['amount'])
                    session['balance']=balance
                    session['count']=session['count']+1
                    msg='Amount Withdrawn Successfully'
            elif request.form['action']=='Deposit':
                if int(request.form['amount'])>10000:
                    msg='Cannot deposit more than 10000'
                else:
                    balance=balance+int(request.form['amount'])
                    session['balance']=balance
                    session['count']=session['count']+1
                    msg='Amount Deposited Successfully
                    
        return render_template('index.html',balance=balance,msg=msg)

if __name__=='__main__':
    app.run(debug=True)
