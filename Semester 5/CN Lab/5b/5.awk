BEGIN {
    TCPPktRec = 0;
    UDPPktRec = 0;
    TCPPktDrop = 0;
    UDPPktDrop = 0;
}
{
    event=$1;
    pktType = $5;
    if(event == "r") {
        if(pktType == "tcp") {
            TCPPktRec++;
        }
        else if(pktType == "cbr") {
            UDPPktRec++;
        }
    }
    else if(event == "d") {
        if(pktType == "tcp") {
            TCPPktDrop++;
        }
        else if(packetType == "cbr") {
            UDPPktDrop++;
        }
    }
}
END {
    printf("\nTCP:\tRecieved: %d\tDropped: %d",TCPPktRec,TCPPktDrop);
    printf("\nUDP:\tRecieved: %d\tDropped: %d\n",UDPPktRec,UDPPktDrop);
}
