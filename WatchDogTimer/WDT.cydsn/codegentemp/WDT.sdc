# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\Development\AESD\WatchDogTimer\WDT.cydsn\WDT.cyprj
# Date: Mon, 24 Sep 2018 09:12:25 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]


# Component constraints for D:\Development\AESD\WatchDogTimer\WDT.cydsn\TopDesign\TopDesign.cysch
# Project: D:\Development\AESD\WatchDogTimer\WDT.cydsn\WDT.cyprj
# Date: Mon, 24 Sep 2018 09:12:19 GMT