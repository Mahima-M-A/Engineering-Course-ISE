from flask import Flask,request,redirect,render_template,session,url_for

app=Flask(__name__)
app.secret_key='secret'

@app.route('/',methods=['POST','GET'])
def Store():
    if request.method=='GET':
        return render_template('Store.html')
    if request.method=='POST':
        for item in ['Milk','Eggs','Bread']:
            if item not in session:
                session[item]=int(request.form[item])
            else:
                session[item]+=int(request.form[item])
        return redirect(url_for('Cart'))

@app.route('/Cart',methods=['POST','GET'])
def Cart():
    cart=[]
    for item in ['Milk','Eggs','Bread']:
        cart.append({'name':item.capitalize(),'quantity':session[item]})
    return render_template('Cart.html',cart=cart)

if __name__=='__main__':
    app.run(debug=True)
