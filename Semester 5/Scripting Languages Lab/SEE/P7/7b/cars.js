window.onload=()=>{
    var teslaModels=[
        {
            "model": "modelS",
            "name": "Model S",
            "price": 69200,
            "year": 2016
        },
        {
            "model": "modelX",
            "name": "Model X",
            "price": 83700,
            "year": 2017
        },
        {
            "model": "model3",
            "name": "Model 3",
            "price": 35000,
            "year": 2017
        },
    ];
    teslaModels.forEach((item,index) => {
        var ele=document.createElement('th');
        ele.id=item.model;
        ele.innerHTML=item.name;
        document.getElementById('menu').appendChild(ele);
    });
    teslaModels.forEach(mousehover);
    function mousehover(item,index){
        var ele=document.getElementById(item.model);
        ele.onmouseover=function(){
            if(details!=null){
                document.getElementById('data-table').removeAttribute('hidden');
                document.getElementById('name').innerHTML='<h3>'+item.name+'</h3>';
                document.getElementById('pic').innerHTML='<img src="img/'+item.model+'.jpeg">';
                document.getElementById('price').innerHTML='$. '+item.price;
                document.getElementById('year').innerHTML=item.year;
            }
        }
    }
}