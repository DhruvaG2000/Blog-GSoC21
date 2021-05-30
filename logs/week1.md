---
sort: 1
---
 
# Logs from May 19 to May 26

- Skimmed through the Bela Makefile. (didn't understand much, realized I needed to study GNU Make further)
- Went through the proposal revise the workflow
- Sent shipping address details to the org and mentor.
- Try to cross-compile on xenomai without actually running it on the device (On my own PC before the beaglebone AI arrives) by following [these](https://source.denx.de/Xenomai/xenomai/-/wikis/Installing_Xenomai_3#user-content-building-the-x86-libraries-3264bit) instructions.   
- Find out if robert nelson has built xenomai kernel for BBAI (Found it).
- located script in the BBAI (that is yet to arrive) that will allow to install pre-built kernels in this case xenomai.  
- Went through the AM57x Ref. manual once again, noted does the McASP pin base address.
- Studied GNU Make in depth and started writing a blog about it.
- Created 4 branches:
  - ***bbai-dev***: This is the branch where I will ultimately try to integrate all changes once they are tested and proven.
  - ***bbai-mcasp***: Here I have temporarily inserted base address of BBAI McASP 1, will test once BBAI arrives.
  - ***clpru*** : Here I plan to compile using gcc or clpru. (to be decided once board arrives)
  - ***bbai-makefile***: Here I will make changes to the makefile to include additional steps for the bbai. So far I have managed to add the flag for bbai. Not yet decided how this flag will be used later on and when and where. Will have to study the code more thoroughly as I am still not understanding in which part of the code is Bela actually detecting the hardware and how? I have not been able to see any pass from makefile telling the board_detect codes about the current hardware.
- Started tracking my tasks on github's new Project feature.   
