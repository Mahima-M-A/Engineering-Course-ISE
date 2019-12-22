from flask import Flask,url_for,redirect,render_template,session,request

app=Flask(__name__)
app.secret_key="secret"

@app.route("/",methods=["POST", "GET"])
def index():
    try:
        balance=session["balance"]
        count=session["count"]
    except KeyError:
        balance=session["balance"]=8000
        count=session["count"]=0
    if request.method=="GET":
        return render_template('index.html',msg="",balance=balance)
    if request.method=="POST":
        if request.form['amount']=='':
            msg="Amount required"
        elif int(request.form['amount'])<0:
            msg="Negative amount cannot be entered"
        elif session["count"]==5:
            msg="5 transactions complete"
        else:
            if request.form['action']=='Withdraw':
                if int(request.form['amount'])>session['balance']:
                    msg="Not enough balance"
                elif int(request.form['amount'])>5000:
                    msg="Cannot withdraw more than 5000"
                else:
                    balance=session['balance']-int(request.form['amount'])
                    session['balance']=balance
                    session['count']=session['count']+1
                    msg="Withdrawn successfully"
            elif request.form['action']=='Deposit':
                balance=session['balance']+int(request.form['amount'])
                session['balance']=balance
                session['count']=session['count']+1
                msg="Deposited successfully"
        return render_template('index.html',msg=msg,balance=balance)

if __name__=='__main__':
    app.run(debug=True)