BEGIN{
  tcprec=0;
  tcpdrop=0;
  tcpsent=0;
  udprec=0;
  udpdrop=0;
  udpsent=0;
  totrec=0;
  totdrop=0;
  totsent=0;
}
{
  event=$1;
  pkttype=$5;
  if(pkttype=="tcp"){
    if(event=="r"){
      tcprec++;
    }
    if(event=="d"){
      tcpdrop++;
    }
    if(event=="+"){
      tcpsent++;
    }
  }
  else if(pkttype=="cbr"){
    if(event=="r"){
      udprec++;
    }
    if(event=="d"){
      udpdrop++;
    }
    if(event=="+"){
      udpsent++;
    }
  }
}
END{
  totsent=tcpsent+udpsent;
  totrec=tcprec+udprec;
  totdrop=tcpdrop+udpdrop;
  printf("TCP packets-  sent: %d   received: %d   drop:%d\n",tcpsent,tcprec,tcpdrop);
  printf("UDP packets-  sent: %d   received: %d   drop:%d\n",udpsent,udprec,udpdrop);
  printf("Total packets sent: %d\n",totsent);
  printf("Total packets received: %d\n",totrec);
  printf("Total packets dropped: %d\n",totdrop);
}
