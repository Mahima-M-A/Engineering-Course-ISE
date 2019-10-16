function get(a){
    return document.getElementById(a).value;
}

function set(a,b){
    document.getElementById(a).innerHTML=b;
}

function check(){
    if(get("usn").length!=10 || get("name").length==0) return false;
    else return true;
}

function grade(a,i){
    if(a>100 || a=="") set("res"+i,"Invalid marks");
    else if(a>90) set("res"+i,"S+");
    else if(a>80) set("res"+i,"S");
    else if(a>70) set("res"+i,"A");
    else if(a>60) set("res"+i,"B");
    else if(a>50) set("res"+i,"C");
    else if(a>40) set("res"+i,"D");
    else set("res"+i,"F");
}

function calc(){
    if(check()){
        document.getElementById("res").removeAttribute('hidden');
        var total=0;
        for(i=1;i<=3;i++){
            var m=get("sub"+i.toString());
            total+=parseInt(m);
            grade(m,i.toString());
        }
        var avg=total/3;
        grade(avg,"4");
    }
}
