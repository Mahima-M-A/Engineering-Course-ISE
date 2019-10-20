BEGIN{
	dropped=0;
}
{
	event=$1;
	if(event=="d"){
		dropped++;
	}
}
END{
	printf("Number of packets dropped: %d\n",dropped);
}
