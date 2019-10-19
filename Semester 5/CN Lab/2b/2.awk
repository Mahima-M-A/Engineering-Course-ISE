BEGIN{
    telnetPkts=0;
    ftpPkts=0;
    telnetSize=0;
    ftpSize=0;
    telnetTotal=0;
    ftpTotal=0;
}
{
    event=$1;
    pkttype= $5;
    fromnode=$9;
    tonode=$10;
    pktsize=$6;

    if(event == "r" && pkttype == "tcp" && fromnode == "0.0" && tonode == "3.0"){
        telnetPkts++;
        telnetSize = pktsize;
    }
    if(event == "r" && pkttype == "tcp" && fromnode == "1.0" && tonode == "3.1"){
        ftpPkts++;
        ftpSize = pktsize;
    }
}
END{
    telnetTotal=telnetPkts*telnetSize*8;
    ftpTotal=ftpPkts*ftpSize*8;

    printf("The Throughput of FTP application is %d \n", ftpTotal/24);
    printf("The Throughput of TELNET application is %d \n", telnetTotal/24);
}
