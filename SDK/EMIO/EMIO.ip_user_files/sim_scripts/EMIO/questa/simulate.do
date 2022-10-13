onbreak {quit -f}
onerror {quit -f}

vsim -t 1ps -lib xil_defaultlib EMIO_opt

do {wave.do}

view wave
view structure
view signals

do {EMIO.udo}

run -all

quit -force
