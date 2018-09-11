# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\Development\AESD\Workspace\Critical_Section.cydsn\Critical_Section.cyprj
# Date: Tue, 21 Aug 2018 06:20:57 GMT
#set_units -time ns
create_clock -name {Clock_1(FFB)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ff_div_11}]]
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 48001 96001} [list]


# Component constraints for D:\Development\AESD\Workspace\Critical_Section.cydsn\TopDesign\TopDesign.cysch
# Project: D:\Development\AESD\Workspace\Critical_Section.cydsn\Critical_Section.cyprj
# Date: Tue, 21 Aug 2018 06:20:54 GMT
