#To simulate three node point-to-point network with duplex links and to find the no. of packets dropped by setting the queue size and varying bsndwidth

set ns [new Simulator]

set traceFile [open 1.tr w]
$ns trace-all $traceFile
set namFile [open 1.nam w]
$ns namtrace-all $namFile

proc finish {} {
  global ns namFile traceFile
  $ns flush-trace
  close $traceFile
  close $namFile
  exec awk -f 1.awk 1.tr &
  exec nam 1.nam &
  exit 0
}

set n(0) [$ns node]
set n(1) [$ns node]
set n(2) [$ns node]

$ns duplex-link $n(0) $n(1) 1Mb 20ms DropTail
$ns duplex-link $n(1) $n(2) 0.5Mb 20ms DropTail
$ns queue-limit $n(0) $n(1) 10
$ns queue-limit $n(1) $n(2) 10

set udp0 [new Agent/UDP]
$ns attach-agent $n(0) $udp0

set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 512
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0

set null0 [new Agent/Null]
$ns attach-agent $n(2) $null0

$ns connect $udp0 $null0

$ns at 0.5 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"

$ns run
