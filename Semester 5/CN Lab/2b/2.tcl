#To simulate FTP and TELNET traffic over the network and analyze the throughput

set ns [new Simulator]

set traceFile [open 2.tr w]
$ns trace-all $traceFile
set namFile [open 2.nam w]
$ns namtrace-all $namFile

proc finish {} {
  global ns namFile traceFile
  $ns flush-trace
  close $traceFile
  close $namFile
  exec awk -f 2.awk 2.tr &
  exec nam 2.nam &
  exit 0
}

for {set i 0} {$i < 4} {incr i} {
  set n($i) [$ns node]
}

$ns duplex-link $n(0) $n(2) 2Mb 10ms DropTail
$ns duplex-link $n(1) $n(2) 2Mb 10ms DropTail
$ns duplex-link $n(2) $n(3) 900kb 10ms DropTail

$ns queue-limit $n(0) $n(2) 10

set tcp0 [new Agent/TCP]
$ns attach-agent $n(0) $tcp0
set sink0 [new Agent/TCPSink]
$ns attach-agent $n(3) $sink0
$ns connect $tcp0 $sink0

set telnet [new Application/Telnet]
$telnet attach-agent $tcp0
$telnet set interval_ 0

set tcp1 [new Agent/TCP]
$ns attach-agent $n(1) $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n(3) $sink1
$ns connect $tcp1 $sink1

set ftp [new Application/FTP]
$ftp attach-agent $tcp1
$ftp set type_ FTP

$ns at 0.5 "$telnet start"
$ns at 0.6 "$ftp start"
$ns at 24.5 "$telnet stop"
$ns at 24.5 "$ftp stop"
$ns at 25.0 "finish"

$ns run
