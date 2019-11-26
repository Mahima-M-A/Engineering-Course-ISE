from flask import Flask, redirect, url_for, render_template, request
# Initialize the Flask application
app = Flask(__name__)
@app.route('/')
def index():
	return render_template('log_in.html')

@app.route('/log_in',methods = ['POST','GET'])
def log_in():
	if request.method == 'POST':
		if request.form['usn'] == 'admin' and request.form['pass'] == 'admin' :
			return redirect(url_for('success'))
		else:
			return render_template('log_in.html', msg='incorrect entry')

@app.route('/success')
def success():
	return 'logged in successfully'
if __name__ == '__main__':
	app.run(debug = True)
