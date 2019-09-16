function check(){
	var text=document.getElementById("text").value;
	var words=text.split(" ");
	var max=0;
	var index=0;
	
	for(var i=0;i<words.length;i++){
		if(words[i].length>max){
			max=words[i].length;
			index=i;
		}
	}
	document.getElementById("word").innerHTML="The longest word is: "+words[index];
	document.getElementById("length").innerHTML="Its length is: "+max;
}