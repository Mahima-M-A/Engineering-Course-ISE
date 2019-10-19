BEGIN {
    dropped=0;
}
{
    event=$1;
    if(event=="d"){
        dropped++;
    }
}
END {
    printf("No of packets dropped : %d\n",dropped);
}
