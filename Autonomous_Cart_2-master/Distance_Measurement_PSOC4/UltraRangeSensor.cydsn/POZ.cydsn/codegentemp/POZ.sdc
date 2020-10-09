# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\first processor\Downloads\Project_Onderzoek\UltraRangeSensor.cydsn\POZ.cydsn\POZ.cyprj
# Date: Tue, 31 Mar 2020 01:37:39 GMT
#set_units -time ns
create_clock -name {Clock_2(FFB)} -period 25000 -waveform {0 12500} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {UART_SCBCLK(FFB)} -period 8666.6666666666661 -waveform {0 4333.33333333333} [list [get_pins {ClockBlock/ff_div_3}]]
create_clock -name {Clock_1(FFB)} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ff_div_11}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/hfclk}] -edges {1 601 1201} [list]
create_generated_clock -name {UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 209 417} -nominal_period 8666.6666666666661 [list]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 241 481} [list]


# Component constraints for C:\Users\first processor\Downloads\Project_Onderzoek\UltraRangeSensor.cydsn\POZ.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\first processor\Downloads\Project_Onderzoek\UltraRangeSensor.cydsn\POZ.cydsn\POZ.cyprj
# Date: Tue, 31 Mar 2020 01:37:36 GMT
