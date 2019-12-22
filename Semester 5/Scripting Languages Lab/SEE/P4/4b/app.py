from flask import Flask,redirect,render_template,request,url_for,session

app=Flask(__name__)
app.secret_key='secret'

@app.route('/store',methods=['POST','GET'])
def store():
    if request.method=='GET':
        return render_template('store.html')
    if request.method=='POST':
        for item in ['milk','eggs','bread']:
            if item not in session:
                session[item]=int(request.form[item])
            else:
                session[item]+=int(request.form[item])
    return redirect(url_for('cart'))

@app.route('/cart',methods=['POST','GET'])
def cart():
    cart=[]
    for item in ['milk','eggs','bread']:
        cart.append({'name':item.upper(),'qty':session[item]})
    return render_template('cart.html',cart=cart)

if __name__=='__main__':
    app.run(debug=True)