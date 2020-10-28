cmake_minimum_required(VERSION 3.1)

# set the project name
project (Bonus)

# add library 
add_library(pcap.h|https://www.tcpdump.org/release/libpcap-1.9.1.tar.gz)
# add the executable
add_executable("${PROJECT_NAME}" main/main.cpp)