#To simulate an Ethernet LAN using 6-10 nodes, change error rate and data rate and compare throughput.

set ns [new Simulator]

set error_rate 0.00

$ns color 1 Blue
$ns color 2 Red

set traceFile [open 6.tr w]
$ns trace-all $traceFile
set namFile [open 6.nam w]
$ns namtrace-all $namFile

proc finish {} {
  global ns namFile traceFile
  $ns flush-trace
  close $traceFile
  close $namFile
  exec awk -f 6.awk 6.tr & 
  exec nam 6.nam &
  exit 0
}

for {set i 0} {$i < 6} {incr i} {
  set n($i) [$ns node]
}

$ns duplex-link $n(0) $n(2) 2Mb 10ms DropTail
$ns duplex-link $n(1) $n(2) 2Mb 10ms DropTail
$ns simplex-link $n(2) $n(3) 0.3Mb 100ms DropTail
$ns simplex-link $n(3) $n(2) 0.3Mb 100ms DropTail

set lan [$ns newLan "$n(3) $n(4) $n(5)" 0.5Mb 40ms LL Queue/DropTail MAC/802_3 Channel]

$ns duplex-link-op $n(0) $n(2) orient right-down
$ns duplex-link-op $n(1) $n(2) orient right-up
$ns simplex-link-op $n(2) $n(3) orient right

$ns queue-limit $n(2) $n(3) 20
$ns simplex-link-op $n(2) $n(3) queuePos 0.5

set loss_module [new ErrorModel]
$loss_module ranvar [new RandomVariable/Uniform]
$loss_module drop-target [new Agent/Null]
$loss_module set rate_ $error_rate
$ns lossmodel $loss_module $n(2) $n(3)

set tcp [new Agent/TCP/Newreno]
$tcp set fid_ 1
$tcp set window_ 8000
$tcp set packetSize_ 552
$ns attach-agent $n(0) $tcp
set sink0 [new Agent/TCPSink/DelAck]
$ns attach-agent $n(4) $sink0
$ns connect $tcp $sink0

set ftp [new Application/FTP]
$ftp set type_ FTP
$ftp attach-agent $tcp

set udp0 [new Agent/UDP]
$udp0 set fid_ 2
$ns attach-agent $n(1) $udp0
set null0 [new Agent/Null]
$ns attach-agent $n(5) $null0
$ns connect $udp0 $null0

set cbr [new Application/Traffic/CBR]
$cbr set type_ CBR
$cbr set packetSize_ 1000
$cbr set rate_ 0.2Mb
$cbr set random_ false
$cbr attach-agent $udp0

$ns at 0.1 "$cbr start"
$ns at 1.0 "$ftp start"
$ns at 124.0 "$ftp stop"
$ns at 124.5 "$cbr stop"
$ns at 125.0 "finish"

$ns run
